#include <iostream>
int Adder(int _num1 = 5, int _num2 = 9);


int main()
{
	int num = 20;
	// std::cout으로 출력 시작
	// <<연산자로 연결
	// std::endl;로 개행
	// CPP은 C와 달리 자료형을 따로 정해주지 않아도 알아서 자료형을 넣어줌.

	std::cout << "내용" << num << std::endl;
	// std::cin으로 입력 시작
	// >> 연산자로 연결
	// 마찬가지로 자료형을 정해주지 않아도 문제없음.
	// 아래와 같이 2개 이상의 변수에 값을 넣을 수 있으며 구분은 공백으로 구분함.
	int num2 = 40;
	std::cin >> num >> num2;

	// 문자 배열로 문자를 받을 수 있음.
	// 이는 문자가 아니라 정수, 실수 배열도 마찬가지임.
	// 출력도 배열 이름으로 변수를 사용함.
	char name[100];
	std::cin >> name;
	std::cout << "이름: " << name << std::endl;

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