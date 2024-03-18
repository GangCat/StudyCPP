#define _CRT_SECURE_NO_WARNINGS
#include"NameCard.h"
#include<iostream>
#include<cstring>
using namespace std;

NameCard::NameCard(const char* _name, const char* _compName, const char* _phoneNum, int _pos)
	:pos(_pos)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	compName = new char[strlen(_compName) + 1];
	strcpy(compName, _compName);
	phoneNum = new char[strlen(_phoneNum) + 1];
	strcpy(phoneNum, _phoneNum);
}
NameCard::NameCard(const NameCard & _card) : pos(_card.pos)
{
	name = new char[strlen(_card.name) + 1];
	strcpy(name, _card.name);
	compName = new char[strlen(_card.compName) + 1];
	strcpy(compName, _card.compName);
	phoneNum = new char[strlen(_card.phoneNum) + 1];
	strcpy(phoneNum, _card.phoneNum);
}
NameCard::~NameCard()
{
	delete[] name;
	delete[] compName;
	delete[] phoneNum;
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