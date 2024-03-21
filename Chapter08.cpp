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
    ptrBase->NormalFunc(); // derived ���
    ptrBase->Base::NormalFunc(); // base ���
    Derived* dr = new Derived();
    dr->NormalFunc();
    delete dr;
    delete ptrBase; // �޸� ������ �����ϱ� ���� ��ü ����


    return 0;
}