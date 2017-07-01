

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include"Variable.h"
#include"Scalar.h"


class Matrix : public Variable
{
public:
	Matrix(int row, int col, int val);
	Matrix(int startVal, int endVal);
    //Matrix(const Matrix& mat);
	~Matrix();
	virtual VarPtr Copy() const;
	virtual VarPtr NumElems() const;
	virtual VarPtr Size() const;
	virtual VarPtr Size(int dim) const;
	virtual VarPtr Conv(VarPtr rhs) const; 
	virtual VarPtr Transpose() const;
	virtual void Print(ostream& ro) const;
	virtual int getValue()const;
	virtual int** getMatrix()const;

	virtual int& operator[](int idx);
	virtual int& operator[](IdxVec v);
	virtual int& operator[](IdxVec v) const;

	virtual VarPtr operator+(const Variable&) ;
	virtual VarPtr operator+(const Scalar&) ;
	virtual VarPtr operator+(const Matrix&) ;

	virtual VarPtr operator*(const Variable&) ;
	virtual VarPtr operator*(const Scalar&) ;
	virtual VarPtr operator*(const Matrix&) ;

	virtual VarPtr operator<(const Variable&) ;
	virtual VarPtr operator<(const Scalar&) ;
	virtual VarPtr operator<(const Matrix&) ;

	virtual VarPtr operator>(const Variable&) ;
	virtual VarPtr operator>(const Scalar&) ;
	virtual VarPtr operator>(const Matrix&) ;

	virtual VarPtr operator==(const Variable&) ;
	virtual VarPtr operator==(const Scalar&) ;
	virtual VarPtr operator==(const Matrix&) ;

	virtual VarPtr operator&&(const Variable&) ;
	virtual VarPtr operator&&(const Scalar&) ;
	virtual VarPtr operator&&(const Matrix&) ;

	virtual VarPtr operator||(const Variable&) ;
	virtual VarPtr operator||(const Scalar&) ;
	virtual VarPtr operator||(const Matrix&) ;


private:
	int row_;
	int col_;
	int** matrix_;
};
#endif
