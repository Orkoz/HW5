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


ostream& operator<< (ostream& ro, const VarPtr& p);



class Variable
{
public:
	
	// ToDo: complete class definition
	
	

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
	virtual VarPtr Print(ostream& ro) const = 0;
	
	//virtual void variable(or Scalar Or Matrix)::print(ostream& ro) const { ///////will be added to scalar and matrix
	//	ro << "ID: " << id_;
	//	if (name_) ro << " Name: " << name_;
	//}

	virtual int& operator[](int idx) const = 0;
	virtual int& operator[](IdxVec v) const = 0;

};




#endif // _VARIABLE_H_
