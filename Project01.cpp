#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum ECusType { NONE = -1, TYPE_A = 7, TYPE_B = 4, TYPE_C = 2 };
enum { NORMAL_ACC = 1, CREDIT_ACC };

class Account
{
protected:
	const int accID;
	char* cusName;
	int balance;
public:
	explicit Account(int _id, int _balance, char* _name);
	explicit Account(const Account& _copy);
	int GetID() const;
	virtual void Deposit(int _money);
	int Withdraw(int _money);
	virtual void ShowAccInfo() const;
	virtual ~Account();
};
Account::Account(int _id, int _balance, char* _name) : accID(_id), balance(_balance)
{
	cusName = new char[strlen(_name) + 1];
	strcpy(cusName, _name);
}
Account::Account(const Account& _copy) : accID(_copy.accID), balance(_copy.balance)
{
	cusName = new char[strlen(_copy.cusName) + 1];
	strcpy(cusName, _copy.cusName);
}
int Account::GetID() const
{
	return accID;
}
void Account::Deposit(int _money)
{
	balance += _money;
}
int Account::Withdraw(int _money)
{
	if(balance < _money)
		return 0;
	balance -= _money;
	return _money;
}
void Account::ShowAccInfo() const
{
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
}
Account::~Account()
{
	delete[] cusName;
}

class NormalAccount : public Account
{
private:
	float interestRate;
public:
	NormalAccount(float _interestRate, int _id, int _balance, char* _name);
	void Deposit(int _money);
	void ShowAccInfo() const;
};
NormalAccount::NormalAccount(float _interestRate, int _id, int _balance, char* _name) : Account::Account(_id, _balance, _name), interestRate(_interestRate){}
void NormalAccount::Deposit(int _money)
{
	balance += _money + ((_money * interestRate) / 100);
}
void NormalAccount::ShowAccInfo() const
{
	cout << "계좌유형: 보통예금계좌" << endl;
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
	cout << "이자율: " << interestRate << endl;
}

class HighCreditAccount : public Account
{
private:
	float interestRate;
	ECusType cusType;
public:
	HighCreditAccount(float _interestRate, int _cusType, int _id, int _balance, char* _name);
	void Deposit(int _money);
	void ShowAccInfo() const;
};
HighCreditAccount::HighCreditAccount(float _interestRate, int _cusType, int _id, int _balance, char* _name) : interestRate(_interestRate), Account(_id, _balance, _name)
{
	switch(_cusType)
	{
	case 1:
		cusType = ECusType::TYPE_A;
		break;
	case 2:
		cusType = ECusType::TYPE_B;
		break;
	case 3:
		cusType = ECusType::TYPE_C;
		break;
	default:
		cusType = ECusType::NONE;
		break;
	}
}
void HighCreditAccount::Deposit(int _money)
{
	balance += _money + ((_money * (interestRate + (int)cusType)) / 100);
}
void HighCreditAccount::ShowAccInfo() const
{
	cout << "계좌유형: 신용신뢰계좌" << endl;
	cout << "계좌ID: " << accID << endl;
	cout << "이 름: " << cusName << endl;
	cout << "잔 액: " << balance << endl;
	cout << "이자율: " << interestRate + (int)cusType << endl;
}

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum = 0;
public:
	void ShowMenu();
	void SelectAccountType();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount();

};
void AccountHandler::ShowMenu()
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계과정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
void AccountHandler::SelectAccountType()
{
	int accTypeNum;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> accTypeNum;
	switch(accTypeNum)
	{
	case NORMAL_ACC:
		MakeNormalAccount();
		break;
	case CREDIT_ACC:
		MakeHighCreditAccount();
		break;
	default:
		cout << "다시 입력해 주시기 바랍니다." << endl;
		break;
	}
}
void AccountHandler::DepositMoney()
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
void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;
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
void AccountHandler::ShowAllAccInfo() const
{
	for(int i = 0; i < accNum; ++i)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
AccountHandler::~AccountHandler()
{
	for(int i = 0; i < accNum; ++i)
		delete accArr[i];
}
void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interestRate;
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> interestRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(interestRate, id, balance, name);
}
void AccountHandler::MakeHighCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interestRate;
	int cusType;
	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> interestRate;
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> cusType;
	cout << endl;

	accArr[accNum++] = new HighCreditAccount(interestRate, cusType, id, balance, name);
}


int main()
{
	AccountHandler handler;
	int choice;
	while(1)
	{
		handler.ShowMenu();
		cout << "선택 ";
		cin >> choice;
		cout << endl;
		switch(choice)
		{
		case MAKE:
			handler.SelectAccountType();
			break;
		case DEPOSIT:
			handler.DepositMoney();
			break;
		case WITHDRAW:
			handler.WithdrawMoney();
			break;
		case INQUIRE:
			handler.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}