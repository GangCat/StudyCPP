#define _CRT_SECURE_NO_WARNINGS
#include"NameCard.h"
#include<iostream>
#include<cstring>
using namespace std;

NameCard::NameCard(const char* _name, const char* _compName, const char* _phoneNum, int _pos)
	:pos(_pos)
{
	name = new char[strlen(_name)];
	strcpy(name, _name);
	compName = new char[strlen(_compName)];
	strcpy(compName, _compName);
	phoneNum= new char[strlen(_phoneNum)];
	strcpy(phoneNum, _phoneNum);
}
void COMP_POS::ShowPosName(int _pos)
{
	switch(_pos)
	{
	case CLERK:
		std::cout << "사원" << std::endl;;
		break;
	case SENIOR:
		std::cout << "주임" << std::endl;;
		break;
	case ASSIST:
		std::cout << "대리" << std::endl;;
		break;
	case MANAGER:
		std::cout << "과장" << std::endl;;
		break;
	}
}
void NameCard::ShowNameCardInfo() const
{
	cout << "이름: " << name << endl;
	cout << "회사: " << compName << endl;
	cout << "전화번호: " << phoneNum << endl;
	cout << "직급: ";
	COMP_POS::ShowPosName(pos);
	cout << endl;
}