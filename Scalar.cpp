#include"Scalar.h"
#include"Matrix.h"
#include"Variable.h"
#include"ScriptExceptions.h"

using namespace std;


//int & Scalar::operator[](int idx) const
//{
//	if (idx != 1)
//	{
//		throw INDEX_OUT_OF_RANGE;
//	}
//	return val_;
//}
//
//int & Scalar::operator[](IdxVec v) const
//{
//	
//}

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

Scalar::Scalar(): val_(0)
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
	VarPtr size_matrix(new Matrix(1, 2, 1));
	return size_matrix;
}

VarPtr Scalar::Size(int dim) const
{
	VarPtr scalar_size(new Scalar(1));
	return scalar_size;
}

VarPtr Scalar::Transpose() const
{
	VarPtr scalar_t = this->Copy();
	return scalar_t;
}

void Scalar::Print(ostream& ro) const
{
	ro << val_;
}

VarPtr Scalar::operator+(const Variable & rhs) const
{
	VarPtr to_be_added = rhs.Copy();
	return *(to_be_added.get()) + *this;
}

VarPtr Scalar::operator+(const Scalar & rhs) const
{
	VarPtr sum = VarPtr(new Scalar( val_ + rhs.val_));
	return sum;
}

VarPtr Scalar::operator+(const Matrix & rhs) const
{
	VarPtr to_be_added = rhs.Copy();
	return *(to_be_added.get()) + *this;
}

VarPtr Scalar::operator*(const Variable & rhs) const
{
	VarPtr to_be_multiplied = rhs.Copy();
	return *(to_be_multiplied.get()) * (*this);
}

VarPtr Scalar::operator*(const Scalar & rhs) const
{
	VarPtr multiply = VarPtr(new Scalar(val_ + rhs.val_));
	return multiply;
}

VarPtr Scalar::operator*(const Matrix & rhs) const
{
	VarPtr to_be_multiplied = rhs.Copy();
	return *(to_be_multiplied.get()) * (*this);
}

VarPtr Scalar::operator<(const Variable & rhs) const
{
	VarPtr to_be_checked = rhs.Copy();
	return *(to_be_checked.get()) > (*this);
}

VarPtr Scalar::operator<(const Scalar & rhs) const
{
	if (val_ < rhs.val_)
	{
		VarPtr logic_answer = VarPtr(new Scalar(1));
	} else
	{
		VarPtr logic_answer = VarPtr(new Scalar(0));
	}
	return logic_answer;
}

VarPtr Scalar::operator<(const Matrix & rhs) const
{
	VarPtr logic_answer = rhs.Copy();
	return *(logic_answer.get()) > (*this);
}

VarPtr Scalar::operator>(const Variable & rhs) const
{
	VarPtr to_be_checked = rhs.Copy();
	return *(to_be_checked.get()) < (*this);
}

VarPtr Scalar::operator>(const Scalar & rhs) const
{
	if (val_ > rhs.val_)
	{
		VarPtr logic_answer = VarPtr(new Scalar(1));
	}
	else
	{
		VarPtr logic_answer = VarPtr(new Scalar(0));
	}
	return logic_answer;
}

VarPtr Scalar::operator>(const Matrix & rhs) const
{
	VarPtr logic_answer = rhs.Copy();
	return *(logic_answer.get()) < (*this);
}

VarPtr Scalar::operator==(const Variable & rhs) const
{
	VarPtr to_be_checked = rhs.Copy();
	return *(to_be_checked.get()) == (*this);
}

VarPtr Scalar::operator==(const Scalar & rhs) const
{
	if (val_ == rhs.val_)
	{
		VarPtr logic_answer = VarPtr(new Scalar(1));
	}
	else
	{
		VarPtr logic_answer = VarPtr(new Scalar(0));
	}
	return logic_answer;
}

VarPtr Scalar::operator==(const Matrix & rhs) const
{
	VarPtr logic_answer = rhs.Copy();
	return *(logic_answer.get()) == (*this);
}

VarPtr Scalar::operator&&(const Variable &) const
{
	VarPtr to_be_checked = rhs.Copy();
	return *(to_be_checked.get()) && (*this);

}

VarPtr Scalar::operator&&(const Scalar &) const
{
	if ((val_ == 1) && (rhs.val_ == 1))
	{
		VarPtr logic_answer = VarPtr(new Scalar(1));
	}
	else
	{
		VarPtr logic_answer = VarPtr(new Scalar(0));
	}
	return logic_answer;
}

VarPtr Scalar::operator&&(const Matrix &) const
{
	throw BAD_INPUT;
}

VarPtr Scalar::operator||(const Variable &) const
{
	VarPtr to_be_checked = rhs.Copy();
	return *(to_be_checked.get()) || (*this);
}

VarPtr Scalar::operator||(const Scalar &) const
{
	if ((val_ == 0) && (rhs.val_ == 0))
	{
		VarPtr logic_answer = VarPtr(new Scalar(0));
	}
	else
	{
		VarPtr logic_answer = VarPtr(new Scalar(1));
	}
	return logic_answer;
}

VarPtr Scalar::operator||(const Matrix &) const
{
	throw BAD_INPUT;
}

int & Scalar::operator[](int idx) const
{
	if (idx != 1)
	{
		throw INDEX_OUT_OF_RANGE;
	}
	else
	{
		return val_;
	}
}

int & Scalar::operator[](IdxVec v) const
{
	if ((v[0] != 1) && (v[1] != 1))
		throw INDEX_OUT_OF_RANGE;
	int i = val_;
	return i;
}

int & Scalar::operator[](IdxVec v)
{
	if ((v[0] != 1) && (v[1] != 1))
		throw INDEX_OUT_OF_RANGE;
	return val_;
}


