#include <iostream>
#include "PartitionTest.h"
//using std::cout;
//using std::cin;
//using std::endl;
using namespace std;

// 디폴트 매개변수
int Adder(int _num1 = 5, int _num2 = 9);
// 인라인 함수
inline int SQUARE(int _x)
{
	return _x * _x;
}
template<typename T>
inline T SQUARE_TEMPLATE(T _x)
{
	return _x * _x;
}

// 네임스페이스 선언
namespace Test1
{
	void Func(void);
}
namespace Test2
{
	void Func(void);
}
// using을 이용한 명시
namespace Hybrid
{
	void HybFunc(void)
	{
		std::cout << "So Simple Function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}
}
//지역변수에 가려진 전역변수
int val = 60;
int mainStudy()
{
	//int num = 20;
	// std::cout으로 출력 시작
	// <<연산자로 연결
	// std::endl;로 개행
	// CPP은 C와 달리 자료형을 따로 정해주지 않아도 알아서 자료형을 넣어줌.

	//std::cout << "내용" << num << std::endl;
	// std::cin으로 입력 시작
	// >> 연산자로 연결
	// 마찬가지로 자료형을 정해주지 않아도 문제없음.
	// 아래와 같이 2개 이상의 변수에 값을 넣을 수 있으며 구분은 공백으로 구분함.
	//int num2 = 40;
	//std::cin >> num >> num2;

	// 문자 배열로 문자를 받을 수 있음.
	// 이는 문자가 아니라 정수, 실수 배열도 마찬가지임.
	// 출력도 배열 이름으로 변수를 사용함.
	//char name[100];
	//std::cin >> name;
	//std::cout << "이름: " << name << std::endl;

	// 인라인 함수는 C의 매크로함수와 달리 정의하여 사용할 수 있다.
	//std::cout << SQUARE(6) << std::endl;
	// 하지만 C의 매크로 함수와 달리 자료형을 미리 정해줘야하는 단점이 존재한다.
	// 이는 C++의 템플릿을 상요하면 되며 모습은 다음과 같다.
	//std::cout << SQUARE_TEMPLATE(12) << std::endl;
	
	// 네임 스페이스 실사용
	Test1::Func();
	Test2::Func();
	// 이제 ::가 무슨 의미인지 알수 있으며 이는 범위지정 연산자라고 부른다.
	// 헤더파일 복습
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	// using을 이용한 네임스페이스 명시
	// 이렇게 선언하는 의미는 HybFunc를 네임스페이스 Hybrid에서 찾아라는 일종의 선언
	// HybFunc이 함수가 아닌 변수여도 사용 가능함.
	using Hybrid::HybFunc;
	HybFunc();
	// using을 이용해 네임스페이스의 특정 함수를 선언하면 이를 전역처럼 사용할수도 있다.
	// 혹은 using namespace로 아예 네임스페이스를 사용해버리면 된다.
	cout << "using cout" << endl;
	int usingNum;
	cin >> usingNum;
	cout << usingNum << endl;
	// namespace가 마아아안약에 과도하게 중첩된 경우 아래처럼 별칭을 부여할 수 있다.
	//namespace ABC = AAA::BBB::CCC;
	// 이는 AAA안에 BBB안에 CCC를 의미한다.

	// 전역변수는 동일한 이름의 지역변수에 가려진다.
	// 하지만 범위지정 연산자를 이용해 지역변수에 가려진 전역변수에 접근할 수 있다.

	int val = 20;
	val += 3; // 23
	::val += 3; // 63

	return 0;
}
// 네임스페이스의 함수 정의
void Test1::Func()
{
	std::cout << "Test1함수" << std::endl;
}
void Test2::Func()
{
	std::cout << "Test2함수" << std::endl;
}


// 오버로딩
int GetNum(int _num1)
{
	return _num1;
}

int GetNum(int _num1, int _num2)
{
	return _num2;
}

//디폴트 매개변수
// 디폴트 매개변수는 함수를 선언할 경우 선언부에만 표현하면 된다.
//int Adder(int _num1 = 5, int _num2 = 9);
int Adder(int _num1, int _num2)
{
	return _num1 + _num2;
}