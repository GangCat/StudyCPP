#include<iostream>
using namespace std;

class Base
{
public:
    Base(){}
    virtual void NormalFunc() // 반환 타입을 추가하고 멤버 함수로 선언
    {
        cout << "base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() : Base() {}
    void NormalFunc() // 반환 타입을 추가하고 멤버 함수로 선언
    {
        cout << "derived" << endl;
    }
};

int main()
{
    Base* ptrBase = new Derived();
    ptrBase->NormalFunc(); // derived 출력
    ptrBase->Base::NormalFunc(); // base 출력
    Derived* dr = new Derived();
    dr->NormalFunc();

    delete dr;
    delete ptrBase; // 메모리 누수를 방지하기 위해 객체 삭제

    return 0;
}