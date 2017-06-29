#include"Scalar.h"
#include"Matrix.h"
#include"Variable.h"
#include"ScriptExceptions.h"

using namespace std;


int & Scalar::operator[](int idx) const
{
	if (idx != 1)
	{
		throw INDEX_OUT_OF_RANGE;
	}
	return val_;

}

int & Scalar::operator[](IdxVec v) const
{
	// TODO: insert return statement here
}

VarPtr Scalar::Conv(VarPtr rhs) const
{
	if ((*(rhs->NumElems()))[1] == 0)
		return VarPtr(new Scalar(0));
	VarPtr pRet = VarPtr(new Scalar(*this));
	VarPtr rhsSize = rhs->Size();
	int rhsRows = (*rhsSize)[1], rhsCols = (*rhsSize)[2];
	IdxVec rhsCenter = { (rhsRows / 2) + 1,(rhsCols / 2) + 1 };
	(*pRet)[1] *= (*rhs)[rhsCenter];
	return pRet;
}

Scalar::Scalar(int val): val_(val)
{
}

Scalar::~Scalar()
{
}

VarPtr Scalar::Copy() const
{
	VarPtr scalar_c = VarPtr(new Scalar(val_));
	return scalar_c;
}

VarPtr Scalar::NumElems() const
{
	VarPtr scalar_c = VarPtr(new Scalar(1));
	return scalar_c;
}

VarPtr Scalar::Size() const
{
	VarPtr size_matrix = VarPtr(new Matrix(1, 2, 1));
	return size_matrix;
}

VarPtr Scalar::Size(int dim) const
{
	VarPtr scalar_c = VarPtr(new Scalar(1));
	return scalar_c;
}

VarPtr Scalar::Transpose() const
{
	VarPtr scalar_c = VarPtr(new Scalar(val_));
	return scalar_c;
}
