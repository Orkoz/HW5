#ifndef _SCALAR_H_
#define _SCALAR_H_

#include"Variable.h"
#include"Matrix.h"

class Scalar : public Variable 
{
public:

	Scalar();
	Scalar(int val);
	~Scalar();

	VarPtr Size() const;
	VarPtr Size(int d) const;
	VarPtr Copy() const;
	VarPtr NumElems() const;
	virtual VarPtr Transpose() const;

	virtual void Print(ostream& ro) const;





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


	virtual int& operator[](int idx) const  ;
	virtual int& operator[](IdxVec v) const  ;
	virtual int& operator[](IdxVec v) ;

	virtual VarPtr Conv(VarPtr rhs) const;

private:
	int val_;
};

#endif // _SCALAR_H_
