#include <iostream>
#include "PartitionTest.h"
//using std::cout;
//using std::cin;
//using std::endl;
using namespace std;

// ����Ʈ �Ű�����
int Adder(int _num1 = 5, int _num2 = 9);
// �ζ��� �Լ�
inline int SQUARE(int _x)
{
	return _x * _x;
}
template<typename T>
inline T SQUARE_TEMPLATE(T _x)
{
	return _x * _x;
}

// ���ӽ����̽� ����
namespace Test1
{
	void Func(void);
}
namespace Test2
{
	void Func(void);
}
// using�� �̿��� ���
namespace Hybrid
{
	void HybFunc(void)
	{
		std::cout << "So Simple Function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}
}
//���������� ������ ��������
int val = 60;
int mainStudy()
{
	//int num = 20;
	// std::cout���� ��� ����
	// <<�����ڷ� ����
	// std::endl;�� ����
	// CPP�� C�� �޸� �ڷ����� ���� �������� �ʾƵ� �˾Ƽ� �ڷ����� �־���.

	//std::cout << "����" << num << std::endl;
	// std::cin���� �Է� ����
	// >> �����ڷ� ����
	// ���������� �ڷ����� �������� �ʾƵ� ��������.
	// �Ʒ��� ���� 2�� �̻��� ������ ���� ���� �� ������ ������ �������� ������.
	//int num2 = 40;
	//std::cin >> num >> num2;

	// ���� �迭�� ���ڸ� ���� �� ����.
	// �̴� ���ڰ� �ƴ϶� ����, �Ǽ� �迭�� ����������.
	// ��µ� �迭 �̸����� ������ �����.
	//char name[100];
	//std::cin >> name;
	//std::cout << "�̸�: " << name << std::endl;

	// �ζ��� �Լ��� C�� ��ũ���Լ��� �޸� �����Ͽ� ����� �� �ִ�.
	//std::cout << SQUARE(6) << std::endl;
	// ������ C�� ��ũ�� �Լ��� �޸� �ڷ����� �̸� ��������ϴ� ������ �����Ѵ�.
	// �̴� C++�� ���ø��� ����ϸ� �Ǹ� ����� ������ ����.
	//std::cout << SQUARE_TEMPLATE(12) << std::endl;
	
	// ���� �����̽� �ǻ��
	Test1::Func();
	Test2::Func();
	// ���� ::�� ���� �ǹ����� �˼� ������ �̴� �������� �����ڶ�� �θ���.
	// ������� ����
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	// using�� �̿��� ���ӽ����̽� ���
	// �̷��� �����ϴ� �ǹ̴� HybFunc�� ���ӽ����̽� Hybrid���� ã�ƶ�� ������ ����
	// HybFunc�� �Լ��� �ƴ� �������� ��� ������.
	using Hybrid::HybFunc;
	HybFunc();
	// using�� �̿��� ���ӽ����̽��� Ư�� �Լ��� �����ϸ� �̸� ����ó�� ����Ҽ��� �ִ�.
	// Ȥ�� using namespace�� �ƿ� ���ӽ����̽��� ����ع����� �ȴ�.
	cout << "using cout" << endl;
	int usingNum;
	cin >> usingNum;
	cout << usingNum << endl;
	// namespace�� ���ƾƾȾ࿡ �����ϰ� ��ø�� ��� �Ʒ�ó�� ��Ī�� �ο��� �� �ִ�.
	//namespace ABC = AAA::BBB::CCC;
	// �̴� AAA�ȿ� BBB�ȿ� CCC�� �ǹ��Ѵ�.

	// ���������� ������ �̸��� ���������� ��������.
	// ������ �������� �����ڸ� �̿��� ���������� ������ ���������� ������ �� �ִ�.

	int val = 20;
	val += 3; // 23
	::val += 3; // 63

	return 0;
}
// ���ӽ����̽��� �Լ� ����
void Test1::Func()
{
	std::cout << "Test1�Լ�" << std::endl;
}
void Test2::Func()
{
	std::cout << "Test2�Լ�" << std::endl;
}


// �����ε�
int GetNum(int _num1)
{
	return _num1;
}

int GetNum(int _num1, int _num2)
{
	return _num2;
}

//����Ʈ �Ű�����
// ����Ʈ �Ű������� �Լ��� ������ ��� ����ο��� ǥ���ϸ� �ȴ�.
//int Adder(int _num1 = 5, int _num2 = 9);
int Adder(int _num1, int _num2)
{
	return _num1 + _num2;
}