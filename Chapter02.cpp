#define _CRT_SECURE_NO_WARNINGS

// 헤더 파일 string.h는 c언어 표준 라이브러리다.
// 그리고 이러한 헤더파일에 선언된 내용들은 c++표준 라이브러리에도 있는데 어떻게 사용하느냐
// 앞에 c를 붙이고 뒤에 .h를 빼면 그게 C++ 라이브러리다.
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

// 이 때 매개변수에는 참조자가 사용되었다.
// 참조자는 선언과 동시에 변수를 참조해야만 한다.
// 하지만 함수의 매개변수의 경우 함수가 호출되는 순간 초기화한다는 의미의 선ㅇ언이므로 상관없다.
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
	// 참조자
	// int & num2 = num1일 때 num2가 num1의 참조자이다.
	// 이 때 num2를 수정하면 참조대상인 num1의 값이 바뀐다.
	// 그리고 주소값은 동일하다.
	// 참조자는 일종의 별명이라고 생각하면 된다.
	// num1의 별명이 num2라는 것
	//int num1 = 1020;
	//int& num2 = num1;
	//// 참조자는 제한이 없다.
	//int& num3 = num1;
	//int& num4 = num1;
	//// 참조자를 대상으로 만들어도 된다.
	//int& num5 = num3;

	//num2 = 3047;

	//cout << "VAL: " << num1 << endl;
	//cout << "REF: " << num2 << endl;

	//cout << "VAL: " << &num1 << endl;
	//cout << "REF: " << &num2 << endl;

	// 참조자는 변수를 대상으로만 선언할 수 있고 선언됨과 동시에 누군가를 참조해야 한다.
	// 사람은 없는데 별명만 있는건 이상하다.
	// int& num = 37; 안된다. -변수를 대상으로만 선언할 수 있다.
	// int& num; 안된다. - 선언됨과 동시에 누군가를 참조해야함
	// int& num = NULL; 안된다. - 선언됨과 동시에 누군가를 참조해야함

	// 참조자는 배열 요소도 참조할 수 있다. (배열은 아님)
	//int arr[3] = {1,3,5};
	//int& arr1 = arr[0];
	//int& arr2 = arr[1];
	//int& arr3 = arr[2];

	//cout << "Arr: " << arr1 << arr2 << arr3 << endl;

	//// 포인터 변수도 참조할 수 있다.
	//int num = 12;
	//int* ptr = &num;
	//int** dptr = &ptr;

	//int& ref = num;
	//int* (&pref) = ptr;
	//int** (&dpref) = dptr;

	//cout << "Result: " << ref << *pref << **dpref << endl;





	// 참조자는 왜 쓰냐? 함수에서 사용한다.

	// 콜 바이 레퍼런스는 포인터를 사용해서 외부에 있는 값에 접근한다. 주소값으로
	// 그리고 C++에서는 이 참조자를 이용해서도 외부에 있는 값에 접근할 수 있다. 참조자로

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

	// swap(val1); 이라는 모습만 봐서는 val1이 참조자로 쓰였는지 값형식으로 쓰였는지 유추하기 어렵다.
	// 그러니 이를 완화하기 위해 값을 변경하지 않는 참조자라면 void Swap(const int& _ref);와 같이
	// const를 이용해 나는 이 _ref로 값을 변경하지 않는다! 라는 사실을 알려주면 좋다.



	// 여기서 num1과 num2는 같은 곳을 가리킨다.
	// 순서는 num1이 먼저 있었고
	// 함수의 매개변수 ref가 num1이 있는 곳을 가리킨다.
	// &ref = num1;
	// 그리고 함수의 반환값인 ref를 num2가 가리킨다. 
	// &num2 = ref;
	// 이 때 num2가 가리키는 곳은 결국 num1이 된다.
	// 그리고 지역변수인 ref가 사라지며 num2와 num1은 한 곳을 가리킨다.
	//int num1 = 1;
	//int& num2 = RefRetFuncOne(num1);
	//// 반면 num3같은 경우 변수 num3를 받는다.
	//// num3 = ref
	//// 즉, 가리키는 장소가 다르다는 의미이다.
	//int num3 = RefRetFuncOne(num1);

	//num1++;
	//num2++;
	//num3 += 100;

	//cout << num1 << endl;
	//cout << num2 << endl;
	//cout << num3 << endl;

	// 순서는 다음과 같다.
	// normalNum이 먼저 있다.
	// &_ref = normalNum, 즉 normalNum을 _ref가 가리킨다.
	// &problemNum = num, 즉 num을 problemNum이 가리킨다.
	// 이 때 num은 지역변수이므로 함수가 종료됨과 동시에 사라진다.
	// 그렇다면 이 때 problemNum은 할당이 해제된 공간을 가리키게 되는 것이다.
	// 실제 출력해보면 이상한 수가 나오는 것을 확인할 수 있다.
	//int normalNum = 30;
	//int& problemNum = ProblemRefRetFunc(normalNum);

	//cout << &problemNum << endl;
	//if(problemNum != NULL)
	//	cout << problemNum << endl;

	// const에 추가로 다음과 같은 경우 에러가 발생한다.

	//const int cNum = 20;
	////int& cRef = cNum; // 에러 발생
	// 그러면 어떻게 해야하나
	// 아래와 같이 한다.
	//const int& cRef = cNum;

	// 참조자는 상수를 참조하지 못한다. 하지만 예외적으로 가능한 문법이 있다.
	//const int& ref = 30;
	// 이 경우 C++은 const 참조자를 이용해서 상수를 참조할때만 '임시변수'라는 것을 만든다고 한다.
	// 그리고 할당된 그 위치에 ref라는 별명을 붙여주는 셈이다.
	// 이런 귀찮은게 왜 있느냐?
	// 바로 아래 함수 때문이다.
	//cout << Adder(3, 4) << endl;
	// 앞서 설명한것처럼 참조자이나 내용을 변경하지 않을 생각이라면 const를 붙이는 것이 좋다.
	// 허나 이를 실제 호출하려면 굉장히 귀찮은 작업을 동반한다.
	// 이러한 작업을 쉽게 해주기 위해 임시변수라는 것을 만들어 주는 것이다.




	// malloc은 2가지 큰 불편함이 있다.
	// 1. 바이트 크기 단위로 크기를 지정해줘야 한다 = sizeof(char) * 20 등등...
	// 2. 반환형이 void*이기 때문에 명시적 형변환을 해줘야만 한다.
	//char* str = MakeStrAdr(20);
	//strcpy(str, "I am so happy!");
	//cout << str << endl;
	//free(str);

	// 이러한 단점이 사라진것이 new
	//int* ptr1 = new int;
	//double* ptr2 = new double;
	//int* arr1 = new int[3];
	//double* arr2 = new double[7];

	// malloc에는 free가 있듯 new에는 delete가 있다.
	//delete ptr1;
	//delete ptr2;
	//delete[]arr1;
	//delete[]arr2;

	// new와 delete를 이용해 MakeStrAdr를 수정해보면 훨씬 쉽다.
	//char* strNew = MakeStrAdr(20);
	//strcpy(strNew, "I am so happy!");
	//cout << strNew << endl;
	//delete[]strNew;


	// 마지막으로 힙에 할당된 변수를 포인터 없이 쉽게 접근해보겠다.
	// 먼저 new를 이용해 간단히 할당한다. 이제 ptr은 어떤 위치의 정수를 가리키는 포인터 변수이다.
	// 편의상 이 때 정수를 A라고 부르겠다.
	int* ptr = new int;
	// 그리고 정수형 참조자가 ptr가 가리키는 정수를 함께 가리킨다.
	// 즉 ref와 *ptr가 둘 다 A를 부르는 별명이 된다.
	int (&ref) = *ptr;
	// 그렇기 때문에 ref를 불러서 내용을 수정하면 이는 A를 수정하는 것과 같은 결과를 부른다.
	ref = 30;
	// 또한 *ptr가 가리키는 값이 A이기 때문에 *ptr의 값도 바뀐 것을 볼 수 있다.
	cout << *ptr << endl;
	delete ptr;



	SPoint* point1 = new SPoint;
	point1->xpos = 10;
	point1->ypos = 20;
	SPoint* point2 = new SPoint;
	point2->xpos = 5;
	point2->ypos = 3;
	// 함수의 반환형이 참조형이다. 그러므로 참조형으로 받고 해제할때는 아래처럼 주소값을 주는 방식이면 되는 것같다.
	SPoint& point3 = PntAdder(*point1, *point2);
	// 이렇게 참조자의 주소를 받아서 포인터에 넣으면 point3가 가리키고 있던 위치는 pptr도 함께 가리키게 된다.
	SPoint* pptr = &point3;

	cout << pptr << " " << &point3 << endl;
	delete point1;
	delete point2;
	delete& point3;
	// point3가 가리키는 위치를 할당해제하면 pptr이 가리키는 위치가 사라지게 되어 접근하면 에러가 발생한다.
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
	// 반환값은 참조
}
int RefRetFuncTwo(int& _ref)
{
	_ref++;
	return _ref;
	// 반환값은 상수나 다름없음.
}
int& ProblemRefRetFunc(int& _ref)
{
	// 잘못된 참조자의 반환에 관한 함수이다.
	// 절대 이렇게 만들지 마라
	int num = 20;
	num += _ref;
	return num;
	// 이렇듯 지역변수를 참조로 반환하게 된다면 어떤 일이 일어나는가
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