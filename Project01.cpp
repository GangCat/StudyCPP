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
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
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
	cout << "��������: ���뿹�ݰ���" << endl;
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
	cout << "������: " << interestRate << endl;
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
	cout << "��������: �ſ�ŷڰ���" << endl;
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
	cout << "������: " << interestRate + (int)cusType << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. ������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}
void AccountHandler::SelectAccountType()
{
	int accTypeNum;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: ";
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
		cout << "�ٽ� �Է��� �ֽñ� �ٶ��ϴ�." << endl;
		break;
	}
}
void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;
	for(int i = 0; i < accNum; ++i)
	{
		if(accArr[i]->GetID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}
void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;
	for(int i = 0; i < accNum; ++i)
	{
		if(accArr[i]->GetID() == id)
		{
			if(accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
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
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
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
	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> interestRate;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
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
		cout << "���� ";
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