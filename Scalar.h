#ifndef _SCALAR_H_
#define _SCALAR_H_

#include"Variable.h"

class Scalar : public Variable // ????????
{
public:

	// ToDo: complete class definition

	Scalar(int val);
	~Scalar();

	virtual VarPtr Copy() const  ;

	virtual VarPtr operator+(const Variable&) const  ;
	virtual VarPtr operator+(const Scalar&) const  ;
	virtual VarPtr operator+(const Matrix&) const  ;

	virtual VarPtr operator*(const Variable&) const  ;
	virtual VarPtr operator*(const Scalar&) const  ;
	virtual VarPtr operator*(const Matrix&) const  ;

	virtual VarPtr operator<(const Variable&) const  ;
	virtual VarPtr operator<(const Scalar&) const  ;
	virtual VarPtr operator<(const Matrix&) const  ;

	virtual VarPtr operator>(const Variable&) const  ;
	virtual VarPtr operator>(const Scalar&) const  ;
	virtual VarPtr operator>(const Matrix&) const  ;

	virtual VarPtr operator==(const Variable&) const  ;
	virtual VarPtr operator==(const Scalar&) const  ;
	virtual VarPtr operator==(const Matrix&) const  ;

	virtual VarPtr operator&&(const Variable&) const  ;
	virtual VarPtr operator&&(const Scalar&) const  ;
	virtual VarPtr operator&&(const Matrix&) const  ;

	virtual VarPtr operator||(const Variable&) const  ;
	virtual VarPtr operator||(const Scalar&) const  ;
	virtual VarPtr operator||(const Matrix&) const  ;

	virtual VarPtr NumElems() const  ;
	virtual VarPtr Size() const  ;
	virtual VarPtr Size(int dim) const  ;
	virtual VarPtr Transpose() const  ;
	/////// printing << ??
	virtual VarPtr Print(ostream& ro) const  ;

	//virtual void variable(or Scalar Or Matrix)::print(ostream& ro) const { ///////will be added to scalar and matrix
	//	ro << "ID: " << id_;
	//	if (name_) ro << " Name: " << name_;
	//}

	virtual int& operator[](int idx) const  ;
	virtual int& operator[](IdxVec v) const  ;

	virtual VarPtr Conv(VarPtr rhs) const;

private:
	int val_;
};

#endif // _SCALAR_H_
