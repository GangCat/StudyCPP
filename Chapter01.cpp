#include <iostream>
int Adder(int _num1 = 5, int _num2 = 9);


int main()
{
	int num = 20;
	// std::cout���� ��� ����
	// <<�����ڷ� ����
	// std::endl;�� ����
	// CPP�� C�� �޸� �ڷ����� ���� �������� �ʾƵ� �˾Ƽ� �ڷ����� �־���.

	std::cout << "����" << num << std::endl;
	// std::cin���� �Է� ����
	// >> �����ڷ� ����
	// ���������� �ڷ����� �������� �ʾƵ� ��������.
	// �Ʒ��� ���� 2�� �̻��� ������ ���� ���� �� ������ ������ �������� ������.
	int num2 = 40;
	std::cin >> num >> num2;

	// ���� �迭�� ���ڸ� ���� �� ����.
	// �̴� ���ڰ� �ƴ϶� ����, �Ǽ� �迭�� ����������.
	// ��µ� �迭 �̸����� ������ �����.
	char name[100];
	std::cin >> name;
	std::cout << "�̸�: " << name << std::endl;

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