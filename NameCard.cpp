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
		std::cout << "���" << std::endl;;
		break;
	case SENIOR:
		std::cout << "����" << std::endl;;
		break;
	case ASSIST:
		std::cout << "�븮" << std::endl;;
		break;
	case MANAGER:
		std::cout << "����" << std::endl;;
		break;
	}
}
void NameCard::ShowNameCardInfo() const
{
	cout << "�̸�: " << name << endl;
	cout << "ȸ��: " << compName << endl;
	cout << "��ȭ��ȣ: " << phoneNum << endl;
	cout << "����: ";
	COMP_POS::ShowPosName(pos);
	cout << endl;
}