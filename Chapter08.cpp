#include<iostream>
using namespace std;

class Base
{
public:
    Base(){}
    virtual void NormalFunc() // ��ȯ Ÿ���� �߰��ϰ� ��� �Լ��� ����
    {
        cout << "base" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() : Base() {}
    void NormalFunc() // ��ȯ Ÿ���� �߰��ϰ� ��� �Լ��� ����
    {
        cout << "derived" << endl;
    }
};

int main()
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