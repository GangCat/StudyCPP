#pragma once
class Calculator
{
private:
	int addCnt;
	int subCnt;
	int mulCnt;
	int divCnt;
public:
	void Init();
	float Add(float _lhs, float _rhs);
	float Sub(float _lhs, float _rhs);
	float Mul(float _lhs, float _rhs);
	float Div(float _lhs, float _rhs);


};

inline void Calculator::Init()
{
	addCnt = 0;
	subCnt = 0;
	mulCnt = 0;
	divCnt = 0;
}