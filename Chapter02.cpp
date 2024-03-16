#define _CRT_SECURE_NO_WARNINGS

// ��� ���� string.h�� c��� ǥ�� ���̺귯����.
// �׸��� �̷��� ������Ͽ� ����� ������� c++ǥ�� ���̺귯������ �ִµ� ��� ����ϴ���
// �տ� c�� ���̰� �ڿ� .h�� ���� �װ� C++ ���̺귯����.
// 
#include<iostream>
#include<cstring>
//#include<string.h>
#include<cstdlib>
//#include<stdlib.h>
#include<cstdio>
//#include<stdio.h>
#include<cmath>
//#include<math.h>
#include<ctime>


using namespace std;

// �� �� �Ű��������� �����ڰ� ���Ǿ���.
// �����ڴ� ����� ���ÿ� ������ �����ؾ߸� �Ѵ�.
// ������ �Լ��� �Ű������� ��� �Լ��� ȣ��Ǵ� ���� �ʱ�ȭ�Ѵٴ� �ǹ��� �������̹Ƿ� �������.
void SwapByRef2(int& _ref1, int& _ref2)
{
	int temp = _ref1;
	_ref1 = _ref2;
	_ref2 = temp;
}

void Question01(int& _refVal)
{
	_refVal += 1;
	_refVal *= -1;
}

void SwapPointer(int* (&_pref1), int* (&_pref2));
int& RefRetFuncOne(int& _ref);
int RefRetFuncTwo(int& _ref);
int& ProblemRefRetFunc(int& _num);
int Adder(const int& _ref1, const int& _ref2);

char* MakeStrAdr(int _len)
{
	//char* str = (char*)malloc(sizeof(char) * _len);
	char* str = new char[20];
	return str;
}

typedef struct __point
{
	int xpos;
	int ypos;
}SPoint;

SPoint& PntAdder(const SPoint& _p1, const SPoint& _p2);

int mainChapter02()
{
	// ������
	// int & num2 = num1�� �� num2�� num1�� �������̴�.
	// �� �� num2�� �����ϸ� ��������� num1�� ���� �ٲ��.
	// �׸��� �ּҰ��� �����ϴ�.
	// �����ڴ� ������ �����̶�� �����ϸ� �ȴ�.
	// num1�� ������ num2��� ��
	//int num1 = 1020;
	//int& num2 = num1;
	//// �����ڴ� ������ ����.
	//int& num3 = num1;
	//int& num4 = num1;
	//// �����ڸ� ������� ���� �ȴ�.
	//int& num5 = num3;

	//num2 = 3047;

	//cout << "VAL: " << num1 << endl;
	//cout << "REF: " << num2 << endl;

	//cout << "VAL: " << &num1 << endl;
	//cout << "REF: " << &num2 << endl;

	// �����ڴ� ������ ������θ� ������ �� �ְ� ����ʰ� ���ÿ� �������� �����ؾ� �Ѵ�.
	// ����� ���µ� ���� �ִ°� �̻��ϴ�.
	// int& num = 37; �ȵȴ�. -������ ������θ� ������ �� �ִ�.
	// int& num; �ȵȴ�. - ����ʰ� ���ÿ� �������� �����ؾ���
	// int& num = NULL; �ȵȴ�. - ����ʰ� ���ÿ� �������� �����ؾ���

	// �����ڴ� �迭 ��ҵ� ������ �� �ִ�. (�迭�� �ƴ�)
	//int arr[3] = {1,3,5};
	//int& arr1 = arr[0];
	//int& arr2 = arr[1];
	//int& arr3 = arr[2];

	//cout << "Arr: " << arr1 << arr2 << arr3 << endl;

	//// ������ ������ ������ �� �ִ�.
	//int num = 12;
	//int* ptr = &num;
	//int** dptr = &ptr;

	//int& ref = num;
	//int* (&pref) = ptr;
	//int** (&dpref) = dptr;

	//cout << "Result: " << ref << *pref << **dpref << endl;





	// �����ڴ� �� ����? �Լ����� ����Ѵ�.

	// �� ���� ���۷����� �����͸� ����ؼ� �ܺο� �ִ� ���� �����Ѵ�. �ּҰ�����
	// �׸��� C++������ �� �����ڸ� �̿��ؼ��� �ܺο� �ִ� ���� ������ �� �ִ�. �����ڷ�

	//int val1 = 10;
	//int val2 = 20;
	//SwapByRef2(val1, val2);
	//cout << "val1: " << val1 << " val2: " << val2 << endl;

	//int refVal = 30;
	//Question01(refVal);
	//cout << "refval: " << refVal << endl;

	//int* ptr1 = &val1;
	//int* ptr2 = &val2;
	//cout << "ptr1: " << *ptr1 << " ptr2: " << *ptr2 << endl;
	//SwapPointer(ptr1, ptr2);
	//cout << "ptr1: " << *ptr1 << " ptr2: " << *ptr2 << endl;

	// swap(val1); �̶�� ����� ������ val1�� �����ڷ� �������� ���������� �������� �����ϱ� ��ƴ�.
	// �׷��� �̸� ��ȭ�ϱ� ���� ���� �������� �ʴ� �����ڶ�� void Swap(const int& _ref);�� ����
	// const�� �̿��� ���� �� _ref�� ���� �������� �ʴ´�! ��� ����� �˷��ָ� ����.



	// ���⼭ num1�� num2�� ���� ���� ����Ų��.
	// ������ num1�� ���� �־���
	// �Լ��� �Ű����� ref�� num1�� �ִ� ���� ����Ų��.
	// &ref = num1;
	// �׸��� �Լ��� ��ȯ���� ref�� num2�� ����Ų��. 
	// &num2 = ref;
	// �� �� num2�� ����Ű�� ���� �ᱹ num1�� �ȴ�.
	// �׸��� ���������� ref�� ������� num2�� num1�� �� ���� ����Ų��.
	//int num1 = 1;
	//int& num2 = RefRetFuncOne(num1);
	//// �ݸ� num3���� ��� ���� num3�� �޴´�.
	//// num3 = ref
	//// ��, ����Ű�� ��Ұ� �ٸ��ٴ� �ǹ��̴�.
	//int num3 = RefRetFuncOne(num1);

	//num1++;
	//num2++;
	//num3 += 100;

	//cout << num1 << endl;
	//cout << num2 << endl;
	//cout << num3 << endl;

	// ������ ������ ����.
	// normalNum�� ���� �ִ�.
	// &_ref = normalNum, �� normalNum�� _ref�� ����Ų��.
	// &problemNum = num, �� num�� problemNum�� ����Ų��.
	// �� �� num�� ���������̹Ƿ� �Լ��� ����ʰ� ���ÿ� �������.
	// �׷��ٸ� �� �� problemNum�� �Ҵ��� ������ ������ ����Ű�� �Ǵ� ���̴�.
	// ���� ����غ��� �̻��� ���� ������ ���� Ȯ���� �� �ִ�.
	//int normalNum = 30;
	//int& problemNum = ProblemRefRetFunc(normalNum);

	//cout << &problemNum << endl;
	//if(problemNum != NULL)
	//	cout << problemNum << endl;

	// const�� �߰��� ������ ���� ��� ������ �߻��Ѵ�.

	//const int cNum = 20;
	////int& cRef = cNum; // ���� �߻�
	// �׷��� ��� �ؾ��ϳ�
	// �Ʒ��� ���� �Ѵ�.
	//const int& cRef = cNum;

	// �����ڴ� ����� �������� ���Ѵ�. ������ ���������� ������ ������ �ִ�.
	//const int& ref = 30;
	// �� ��� C++�� const �����ڸ� �̿��ؼ� ����� �����Ҷ��� '�ӽú���'��� ���� ����ٰ� �Ѵ�.
	// �׸��� �Ҵ�� �� ��ġ�� ref��� ������ �ٿ��ִ� ���̴�.
	// �̷� �������� �� �ִ���?
	// �ٷ� �Ʒ� �Լ� �����̴�.
	//cout << Adder(3, 4) << endl;
	// �ռ� �����Ѱ�ó�� �������̳� ������ �������� ���� �����̶�� const�� ���̴� ���� ����.
	// �㳪 �̸� ���� ȣ���Ϸ��� ������ ������ �۾��� �����Ѵ�.
	// �̷��� �۾��� ���� ���ֱ� ���� �ӽú������ ���� ����� �ִ� ���̴�.




	// malloc�� 2���� ū �������� �ִ�.
	// 1. ����Ʈ ũ�� ������ ũ�⸦ ��������� �Ѵ� = sizeof(char) * 20 ���...
	// 2. ��ȯ���� void*�̱� ������ ����� ����ȯ�� ����߸� �Ѵ�.
	//char* str = MakeStrAdr(20);
	//strcpy(str, "I am so happy!");
	//cout << str << endl;
	//free(str);

	// �̷��� ������ ��������� new
	//int* ptr1 = new int;
	//double* ptr2 = new double;
	//int* arr1 = new int[3];
	//double* arr2 = new double[7];

	// malloc���� free�� �ֵ� new���� delete�� �ִ�.
	//delete ptr1;
	//delete ptr2;
	//delete[]arr1;
	//delete[]arr2;

	// new�� delete�� �̿��� MakeStrAdr�� �����غ��� �ξ� ����.
	//char* strNew = MakeStrAdr(20);
	//strcpy(strNew, "I am so happy!");
	//cout << strNew << endl;
	//delete[]strNew;


	// ���������� ���� �Ҵ�� ������ ������ ���� ���� �����غ��ڴ�.
	// ���� new�� �̿��� ������ �Ҵ��Ѵ�. ���� ptr�� � ��ġ�� ������ ����Ű�� ������ �����̴�.
	// ���ǻ� �� �� ������ A��� �θ��ڴ�.
	int* ptr = new int;
	// �׸��� ������ �����ڰ� ptr�� ����Ű�� ������ �Բ� ����Ų��.
	// �� ref�� *ptr�� �� �� A�� �θ��� ������ �ȴ�.
	int (&ref) = *ptr;
	// �׷��� ������ ref�� �ҷ��� ������ �����ϸ� �̴� A�� �����ϴ� �Ͱ� ���� ����� �θ���.
	ref = 30;
	// ���� *ptr�� ����Ű�� ���� A�̱� ������ *ptr�� ���� �ٲ� ���� �� �� �ִ�.
	cout << *ptr << endl;
	delete ptr;



	SPoint* point1 = new SPoint;
	point1->xpos = 10;
	point1->ypos = 20;
	SPoint* point2 = new SPoint;
	point2->xpos = 5;
	point2->ypos = 3;
	// �Լ��� ��ȯ���� �������̴�. �׷��Ƿ� ���������� �ް� �����Ҷ��� �Ʒ�ó�� �ּҰ��� �ִ� ����̸� �Ǵ� �Ͱ���.
	SPoint& point3 = PntAdder(*point1, *point2);
	// �̷��� �������� �ּҸ� �޾Ƽ� �����Ϳ� ������ point3�� ����Ű�� �ִ� ��ġ�� pptr�� �Բ� ����Ű�� �ȴ�.
	SPoint* pptr = &point3;

	cout << pptr << " " << &point3 << endl;
	delete point1;
	delete point2;
	delete& point3;
	// point3�� ����Ű�� ��ġ�� �Ҵ������ϸ� pptr�� ����Ű�� ��ġ�� ������� �Ǿ� �����ϸ� ������ �߻��Ѵ�.
	//delete pptr;

	cout << "Rand: " << rand() % 100 << endl;
	srand(10);
	cout << "srand: " << rand() % 100 << endl;
	cout << "time: " << time(NULL) << endl;
	return 0;
}

void SwapPointer(int* (&_pref1), int* (&_pref2))
{
	int* temp = _pref1;
	_pref1 = _pref2;
	_pref2 = temp;
}

int& RefRetFuncOne(int& _ref)
{
	_ref++;
	return _ref;
	// ��ȯ���� ����
}
int RefRetFuncTwo(int& _ref)
{
	_ref++;
	return _ref;
	// ��ȯ���� ����� �ٸ�����.
}
int& ProblemRefRetFunc(int& _ref)
{
	// �߸��� �������� ��ȯ�� ���� �Լ��̴�.
	// ���� �̷��� ������ ����
	int num = 20;
	num += _ref;
	return num;
	// �̷��� ���������� ������ ��ȯ�ϰ� �ȴٸ� � ���� �Ͼ�°�
}
int Adder(const int& _ref1, const int& _ref2)
{
	return _ref1 + _ref2;
}
SPoint& PntAdder(const SPoint& _p1, const SPoint& _p2)
{
	SPoint* tempP = new SPoint;
	tempP->xpos = _p1.xpos + _p2.xpos;
	tempP->ypos = _p1.ypos + _p2.ypos;
	return *tempP;
}