#include <iostream>
//#include "NameCard.h"
using namespace std;

//class SoSimple
//{
//private:
//	int num;
//public:
//	SoSimple(int _n) :num(_n)
//	{
//
//	}
//	SoSimple(const SoSimple& _simple) : num(_simple.num)
//	{
//		cout << "Called SoSimple(const SoSimple& _simple)" << endl;
//	}
//	~SoSimple()
//	{
//		cout << "소멸자" << endl;
//	}
//	void ShowData()
//	{
//		cout << "num:	" << num << endl;
//	}
//};
//
//void SimpleFuncObj(SoSimple _obj)
//{
//	_obj.ShowData();
//}
class SoSimple
{
private:
	int num;
public:
	SoSimple(int _n) :num(_n)
	{

	}
	SoSimple(const SoSimple& _simple) : num(_simple.num)
	{
		cout << "Called SoSimple(const SoSimple& _simple)" << endl;
	}
	~SoSimple()
	{
		cout << "소멸자" << num << endl;
	}
	SoSimple& AddNum(int _n)
	{
		num += _n;
		return *this;
	}
	void ShowData()
	{
		cout << "num:	" << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple _obj)
{
	cout << "return 이전" << endl;
	return _obj;
}

int main5()
{
	//NameCard manClerk("Lee", "AABCEng", "010-1111-2222", COMP_POS::CLERK);
	//NameCard copy1 = manClerk;
	//NameCard manSenior("Hong", "OrangeEng", "010-2222-3333", COMP_POS::SENIOR);
	//NameCard copy2(manSenior);
	//copy1.ShowNameCardInfo();
	//copy2.ShowNameCardInfo();

	//SoSimple obj(7);
	//cout << "함수 호출 전" << endl;
	//SimpleFuncObj(obj);
	//cout << "함수 호출 후" << endl;

	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();


	return 0;
}