#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Calculator.h"
#include "Printer.h"
using namespace std;



//namespace CAR_CONST
//{
//	enum
//	{
//		ID_LEN		= 20,
//		MAX_SPD		= 200,
//		FUEL_STEP		= 2,
//		ACC_STEP		= 10,
//		BRK_STEP		= 10
//	};
//}
//struct Car
//{
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//
//	void ShowCarState();
//
//
//
//	void Accel()
//	{
//		if(fuelGauge <= 0)
//			return;
//		else
//			fuelGauge -= CAR_CONST::FUEL_STEP;
//
//		if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
//		{
//			curSpeed = CAR_CONST::MAX_SPD;
//			return;
//		}
//
//		curSpeed += CAR_CONST::ACC_STEP;
//	}
//
//	void Break()
//	{
//		if(curSpeed < CAR_CONST::BRK_STEP)
//		{
//			curSpeed = 0;
//			return;
//		}
//		curSpeed -= CAR_CONST::BRK_STEP;
//	}
//};
//inline void Car::ShowCarState()
//{
//	cout << "소유자 ID: " << gamerID << endl;
//	cout << "연료량: " << fuelGauge << "%" << endl;
//	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
//}


namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char* _ID, int _fuelGauge);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* _ID, int _fuelGauge)
{
	strcpy(gamerID, _ID);
	fuelGauge = _fuelGauge;
	curSpeed = 0;
}
inline void Car::ShowCarState()
{
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
	if(fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if(curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}



int main3()
{
	//Car run99 = {"run99", 100, 0};
	//Accel(run99);
	//Accel(run99);
	//ShowCarState(run99);
	//Break(run99);
	//ShowCarState(run99);

	//Car sped77 = {"sped77", 100, 0};
	//Accel(sped77);
	//Break(sped77);
	//ShowCarState(sped77);

	//Car run99;
	//run99.InitMembers("run99", 100);
	//run99.Accel();
	//run99.Accel();
	//run99.ShowCarState();

	Calculator cal;
	cal.Init();
	cout << cal.Add(3.2, 2.4) << endl;
	cout << cal.Sub(3.5, 2.5) << endl;
	cout << cal.Mul(2.0, 3.1) << endl;
	cout << cal.Div(7.7, 1.1) << endl;

	//Printer pnt;
	//pnt.SetString("Hello World!");
	//pnt.ShowString();

	//pnt.SetString("I love C++");
	//pnt.ShowString();
	
	return 0;
}