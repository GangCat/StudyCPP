#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
	const int accID;
	int balance;
	char* cusName;
public:
	explicit Account(int _id, int _balance, char* _name) : accID(_id), balance(_balance)
	{
		cusName = new char[strlen(_name) + 1];
		strcpy(cusName, _name);
	}
	explicit Account(const Account& _copy) : accID(_copy.accID), balance(_copy.balance)
	{
		cusName = new char[strlen(_copy.cusName) + 1];
		strcpy(cusName, _copy.cusName);
	}
	int GetID() const { return accID; }
	void Deposit(int _money)
	{
		balance += _money;
	}
	int Withdraw(int _money)
	{
		if(balance < _money)
			return 0;
		balance -= _money;
		return _money;
	}
	void ShowAccInfo() const
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액: " << balance << endl;
	}
	~Account()
	{
		delete[] cusName;
	}
};

Account* accArr[100];
int accNum = 0;

int main()
{
	int choice;
	while(1)
	{
		ShowMenu();
		cout << "선택 ";
		cin >> choice;
		cout << endl;
		switch(choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for(int i = 0; i < accNum; ++i)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu()
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3.출 금" << endl;
	cout << "4. 계과정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;
	for(int i = 0; i < accNum; ++i)
	{
		if(accArr[i]->GetID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;
	for(int i = 0; i < accNum; ++i)
	{
		if(accArr[i]->GetID() == id)
		{
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl;
}

void ShowAllAccInfo()
{
	for(int i = 0; i < accNum; ++i)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}