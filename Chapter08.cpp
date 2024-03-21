#include<iostream>
using namespace std;

class Base
{
public:
    Base(){}
    virtual void NormalFunc()
    {
        cout << "base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() : Base() {}
    void NormalFunc()
    {
        cout << "derived" << endl;
    }
};

int main8()
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