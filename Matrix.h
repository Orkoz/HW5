

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include"Variable.h"
#include"Scalar.h"


class Matrix : public Variable
{
public:
	Matrix(int row, int col, int val);
	Matrix(int startVal, int endVal);
    Matrix(const Matrix& mat);
	~Matrix();
	VarPtr Copy() const;
	VarPtr NumElems() const;
	VarPtr Size() const;
	VarPtr Size(int dim) const;
	VarPtr Conv(VarPtr rhs) const; ////needed to declare one for scalar and one for matrix?
	VarPtr Transpose() const;
	void Print(ostream& ro) const;

	int& operator[](int idx);
	int& operator[](IdxVec v);
	const int& operator[](int idx) const;
	const int& operator[](IdxVec v) const;

	VarPtr operator+(const Variable&) const;
	VarPtr operator+(const Scalar&) const;
	VarPtr operator+(const Matrix&) const;

	VarPtr operator*(const Variable&) const;
	VarPtr operator*(const Scalar&) const;
	VarPtr operator*(const Matrix&) const;

	VarPtr operator<(const Variable&) const;
	VarPtr operator<(const Scalar&) const;
	VarPtr operator<(const Matrix&) const;

	VarPtr operator>(const Variable&) const;
	VarPtr operator>(const Scalar&) const;
	VarPtr operator>(const Matrix&) const;

	VarPtr operator==(const Variable&) const;
	VarPtr operator==(const Scalar&) const;
	VarPtr operator==(const Matrix&) const;

	VarPtr operator&&(const Variable&) const;
	VarPtr operator&&(const Scalar&) const;
	VarPtr operator&&(const Matrix&) const;

	VarPtr operator||(const Variable&) const;
	VarPtr operator||(const Scalar&) const;
	VarPtr operator||(const Matrix&) const;


private:
	int row_;
	int col_;
	int** matrix_;
};
#endif
