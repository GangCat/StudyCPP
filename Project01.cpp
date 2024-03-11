#include <iostream>
using namespace std;

void BankMenu();
void GetMenuNumber();
void CreateAccount();
void DepositMoneyMenu();
void WithdrawMoneyMenu();
void PrintInfo();

int DepositMoney(int _accountID, int _money);
int WithdrawMoney(int _accountID, int _money);

typedef enum {NONE = -1, CREATE_ACCOUNT = 1, DEPOSIT, WITHDRAW, PRINT, EXIT} EMenuType;

int curMenuNum;
int curCustomerCount = 0;

typedef struct
{
	int id;
	int money;
	char name[20];
}SCInfo;

SCInfo customerInfo[100];

int main()
{
	while(1)
	{
		BankMenu();
		GetMenuNumber();
		switch(curMenuNum)
		{
		case CREATE_ACCOUNT:
			CreateAccount();
			break;
		case DEPOSIT:
			DepositMoneyMenu();
			break;
		case WITHDRAW:
			WithdrawMoneyMenu();
			break;
		case PRINT:
			PrintInfo();
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸� �ԷµǾ����ϴ�. �ٽ� �Է��� �ֽñ� �ٶ��ϴ�." << endl;
			break;
		}
	}
	return 0;
}

void BankMenu()
{

		cout << "-----Menu------" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
}

void GetMenuNumber()
{
	cout << "����:";
	cin >> curMenuNum;
}

void CreateAccount()
{
	SCInfo curCustomerInfo = customerInfo[curCustomerCount];
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> curCustomerInfo.id;
	cout << "�� ��: ";
	cin >> curCustomerInfo.name;
	cout << "�Աݾ�: ";
	cin >> curCustomerInfo.money;
	customerInfo[curCustomerCount] = curCustomerInfo;
	curCustomerCount += 1;
}
void DepositMoneyMenu()
{
	int depositMoney;
	int depositTargetAccountID;
	cout << "[��   ��]" << endl;
	cout << "����ID: ";
	cin >> depositTargetAccountID;
	cout << "�Աݾ�: ";
	cin >> depositMoney;
	cout << "�ԱݿϷ�" << endl;
	cout << "���� �ܾ�: " << DepositMoney(depositTargetAccountID, depositMoney) << endl;
	
}

int DepositMoney(int _accountID, int _money)
{
	for(int i = 0; i < curCustomerCount; ++i)
	{
		if(customerInfo[i].id == _accountID)
		{
			customerInfo[i].money += _money;
			return customerInfo[i].money;
		}
	}
}

void WithdrawMoneyMenu()
{
	int depositMoney;
	int depositTargetAccountID;
	cout << "[��    ��]" << endl;
	cout << "����ID: ";
	cin >> depositTargetAccountID;
	cout << "��ݾ�: ";
	cin >> depositMoney;
	cout << "��ݿϷ�" << endl;
	cout << "���� �ܾ�: " << WithdrawMoney(depositTargetAccountID, depositMoney) << endl;
}

int WithdrawMoney(int _accountID, int _money)
{
	for(int i = 0; i < curCustomerCount; ++i)
	{
		if(customerInfo[i].id == _accountID)
		{
			customerInfo[i].money -= _money;
			return customerInfo[i].money;
		}
	}
}

void PrintInfo()
{
	for(int i = 0; i < curCustomerCount; ++i)
	{
		cout << "����ID: " << customerInfo[i].id << endl;
		cout << "�̸�: " << customerInfo[i].name << endl;
		cout << "�ܾ�: " << customerInfo[i].money << endl;
		cout << "==========================" << endl;
	}
}