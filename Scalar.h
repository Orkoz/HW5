#ifndef _SCALAR_H_
#define _SCALAR_H_

#include"Variable.h"
#include"Matrix.h"

class Scalar : public Variable 
{
public:

	Scalar();
	Scalar(int val);
	//~Scalar();

	VarPtr Size() const;
	VarPtr Size(int d) const;
	VarPtr Copy() const;
	VarPtr NumElems() const;
	virtual VarPtr Transpose() const;
	virtual void Print(ostream& ro) const;
	int getValue() const;
	void setValue(int val);

	virtual VarPtr operator+(const Variable&)   ;
	virtual VarPtr operator+(const Scalar&)   ;
	virtual VarPtr operator+(const Matrix&)   ;

	virtual VarPtr operator*(const Variable&)   ;
	virtual VarPtr operator*(const Scalar&)   ;
	virtual VarPtr operator*(const Matrix&)   ;

	virtual VarPtr operator<(const Variable&)   ;
	virtual VarPtr operator<(const Scalar&)   ;
	virtual VarPtr operator<(const Matrix&)   ;

	virtual VarPtr operator>(const Variable&)   ;
	virtual VarPtr operator>(const Scalar&)   ;
	virtual VarPtr operator>(const Matrix&)   ;

	virtual VarPtr operator==(const Variable&)   ;
	virtual VarPtr operator==(const Scalar&)   ;
	virtual VarPtr operator==(const Matrix&)   ;

	virtual VarPtr operator&&(const Variable&)   ;
	virtual VarPtr operator&&(const Scalar&)   ;
	virtual VarPtr operator&&(const Matrix&)   ;

	virtual VarPtr operator||(const Variable&)   ;
	virtual VarPtr operator||(const Scalar&)   ;
	virtual VarPtr operator||(const Matrix&)   ;


	virtual int& operator[](int idx);
	virtual int& operator[](IdxVec v) ;
	virtual int& operator[](IdxVec v) const;

	virtual VarPtr Conv(VarPtr rhs) const;

private:
	int val_;
};

#endif // _SCALAR_H_
