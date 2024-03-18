#pragma once
#include<iostream>
namespace COMP_POS
{
	enum
	{
		CLERK, SENIOR, ASSIST, MANAGER
	};

	void ShowPosName(int _pos);
}


class NameCard
{
private:
	char* name;
	char* compName;
	char* phoneNum;
	int pos;
public:
	NameCard(const char* _name, const char* _compName, const char* _phoneNum, int _pos);
	void ShowNameCardInfo() const;
	NameCard(const NameCard& _card);
};