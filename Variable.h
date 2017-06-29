#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include<iostream>
#include<ostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ScriptExceptions.h"
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

	virtual VarPtr Copy() const = 0;
	virtual VarPtr NumElems() const = 0;
	virtual VarPtr Size() const = 0;
	virtual VarPtr Size(int dim) const = 0;
	virtual VarPtr Conv(VarPtr rhs) const = 0; ////needed to declare one for scalar and one for matrix?
	virtual VarPtr Transpose() const = 0;
	virtual void Print(ostream& ro) const = 0;

	virtual int& operator[](int idx) = 0;
	virtual int& operator[](IdxVec v) = 0;
    virtual const int& operator[](int idx) const = 0 ;
    virtual const int& operator[](IdxVec v) const = 0;
	
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

    friend ostream& operator<<(ostream& ro, const Variable& rhs);

};

#endif // _VARIABLE_H_
