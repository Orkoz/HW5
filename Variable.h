#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include<iostream>
#include<vector>
#include"MySharedPtr.h"

class Variable;
class Scalar;
class Matrix;

typedef MySharedPtr<Variable> VarPtr;
typedef vector<int> IdxVec;

IdxVec operator+(const IdxVec& lhs, const IdxVec& rhs);


class Variable
{
public:
	
	// ToDo: complete class definition
	
	Variable(); //c-tor
	virtual ~Variable(); //d-tor

	virtual VarPtr Copy() const = 0;
	
	virtual VarPtr operator+(const Variable&) const = 0;
	virtual VarPtr operator+(const Scalar&) const = 0;
	virtual VarPtr operator+(const Matrix&) const = 0;

	virtual VarPtr operator*(const Variable&) const = 0;
	virtual VarPtr operator*(const Scalar&) const = 0;
	virtual VarPtr operator*(const Matrix&) const = 0;

	virtual VarPtr operator<(const Variable&) const = 0;
	virtual VarPtr operator<(const Scalar&) const = 0;
	virtual VarPtr operator<(const Matrix&) const = 0;

	virtual VarPtr operator>(const Variable&) const = 0;
	virtual VarPtr operator>(const Scalar&) const = 0;
	virtual VarPtr operator>(const Matrix&) const = 0;

	virtual VarPtr operator==(const Variable&) const = 0;
	virtual VarPtr operator==(const Scalar&) const = 0;
	virtual VarPtr operator==(const Matrix&) const = 0;

	virtual VarPtr operator&&(const Variable&) const = 0;
	virtual VarPtr operator&&(const Scalar&) const = 0;
	virtual VarPtr operator&&(const Matrix&) const = 0;

	virtual VarPtr operator||(const Variable&) const = 0;
	virtual VarPtr operator||(const Scalar&) const = 0;
	virtual VarPtr operator||(const Matrix&) const = 0;

	virtual VarPtr NumElems() const = 0;
	virtual VarPtr Size() const = 0;
	virtual VarPtr Size(int dim) const = 0;
	virtual VarPtr Conv(VarPtr rhs) const = 0; ////needed to declare one for scalar and one for matrix?
	virtual VarPtr Transpose() const = 0;
	/////// printing << ??

	virtual int& operator[](int idx) const = 0;
	virtual int& operator[](IdxVec v) const = 0;

};




#endif // _VARIABLE_H_
