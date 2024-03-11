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
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못 입력되었습니다. 다시 입력해 주시기 바랍니다." << endl;
			break;
		}
	}
	return 0;
}

void BankMenu()
{

		cout << "-----Menu------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
}

void GetMenuNumber()
{
	cout << "선택:";
	cin >> curMenuNum;
}

void CreateAccount()
{
	SCInfo curCustomerInfo = customerInfo[curCustomerCount];
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> curCustomerInfo.id;
	cout << "이 름: ";
	cin >> curCustomerInfo.name;
	cout << "입금액: ";
	cin >> curCustomerInfo.money;
	customerInfo[curCustomerCount] = curCustomerInfo;
	curCustomerCount += 1;
}
void DepositMoneyMenu()
{
	int depositMoney;
	int depositTargetAccountID;
	cout << "[입   금]" << endl;
	cout << "계좌ID: ";
	cin >> depositTargetAccountID;
	cout << "입금액: ";
	cin >> depositMoney;
	cout << "입금완료" << endl;
	cout << "현재 잔액: " << DepositMoney(depositTargetAccountID, depositMoney) << endl;
	
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
	cout << "[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> depositTargetAccountID;
	cout << "출금액: ";
	cin >> depositMoney;
	cout << "출금완료" << endl;
	cout << "현재 잔액: " << WithdrawMoney(depositTargetAccountID, depositMoney) << endl;
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
		cout << "계좌ID: " << customerInfo[i].id << endl;
		cout << "이름: " << customerInfo[i].name << endl;
		cout << "잔액: " << customerInfo[i].money << endl;
		cout << "==========================" << endl;
	}
}