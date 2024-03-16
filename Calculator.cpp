#include <iostream>
#include "Calculator.h"



float Calculator::Add(float _lhs, float _rhs)
{
	++addCnt;
	return _lhs + _rhs;
}

float Calculator::Sub(float _lhs, float _rhs)
{
	++subCnt;
	return _lhs - _rhs;
}

float Calculator::Mul(float _lhs, float _rhs)
{
	++mulCnt;
	return _lhs * _rhs;
}

float Calculator::Div(float _lhs, float _rhs)
{
	++divCnt;
	return _lhs / _rhs;
}