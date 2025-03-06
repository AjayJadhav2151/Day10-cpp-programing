//Construct a hierarchy of Bank accounts.
//1. Write a class Account with attributes for account number, account holder name and
// balance
//2. Inherit class SavingsAccount from base class Account
//3. SavingsAccount class will have members for
//a.Rate of interest per month
//b.Period of saving in months
//4. Inherit another class CurrentAccount from base class Account
//5. CurrentAccount class will have members for
//a.Overlimit amount
//6. Write constructors for classes SavingsAccount and CurrentAccount.
//7. Override the functions for accepting and displaying details from the user.
//8. Implement function CalculateNetBalance in class SavingsAccount
//net balance = balance + (rate of interest per month * period of saving in month)
//9. Write a menu driven main function to create and display the objects of different
// classes depending on user choice.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Account
{
	int acc_num;
	char acc_name[20];
	float balence;
public:
	Account();
	Account(int, const char*, float);
	void accept();
	void display();
	float getbal();
};
Account::Account() {
	acc_num = 0;
	strcpy(acc_name, "NA");
	balence = 0;
}
Account::Account(int ano, const char* aname, float ab ) {
	acc_num = ano;
	strcpy(acc_name, aname);
	balence = ab;
}
void Account::accept() {
	cout << "Enter your account number:" << endl;
	cin >> acc_num;
	cout << "Enter your name:" << endl;
	cin >> acc_name;
	cout << "Enter your account balence:" << endl;
	cin >> balence;
}
void Account::display() {
	cout << "Account number is:" << acc_num << "Account Holder Name is:" << acc_name << "Account balence is:" << balence << endl;
}
float Account::getbal() {
	return balence;
}

class SavingsAccount : public Account
{
	//a.Rate of interest per month
	//b.Period of saving in months
	int rinm;
	int psm;
	
public:
	SavingsAccount();
	SavingsAccount(int, const char*, float, int, int);
	void accept();
	void display();
	int CalculateNetBalance();
};

SavingsAccount::SavingsAccount() {
	rinm=0;
	psm=0;
}
SavingsAccount::SavingsAccount(int ano, const char* aname, float ab, int r, int p):Account(ano,aname,ab) {
	rinm = r;
	psm = p;
}
int SavingsAccount::CalculateNetBalance() {
	return getbal() + (getbal()*(rinm/100) * psm);
}
void SavingsAccount::accept() {
	Account::accept();
	cout << "Enter Rate of interest per month:" << endl;
	cin >> rinm;
	cout << "Enter Period of saving in months:" << endl;
	cin >> psm;
}

void SavingsAccount::display() {
	Account::display();
	cout << "Rate of interest is:" << rinm <<"%" << "Period of months:" << psm << endl;
	cout <<"NetBalnce is:" << CalculateNetBalance();
}
class CurrentAccount : public Account
{
	//Overlimit amount
	int oa;
public:
	CurrentAccount();
	CurrentAccount(int, const char*, float, int);
	void accept();
	void display();
};

CurrentAccount::CurrentAccount() {
	oa = 0;
}
CurrentAccount::CurrentAccount(int ano, const char* aname, float ab, int o):Account(ano,aname,ab) {
	oa = o;
}
void CurrentAccount::accept() {
	Account::accept();
	cout << "Enter the Overlimit amount" << endl;
	cin >> oa;
}
void CurrentAccount::display() {
	Account::display();
	cout << "Overlimit amount is:"<<oa<< endl;
}
int main() {
	int choice;
	do {
		cout << "\n**** BANK ACCOUNT MENU ****";
		cout << "\n1. Create Savings Account";
		cout << "\n2. Create Current Account";
		cout << "\n3. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			SavingsAccount sa;
			sa.accept();
			sa.display();
			break;
		}
		case 2: {
			CurrentAccount ca;
			ca.accept();
			ca.display();
			break;
		}
		case 3:
			cout << "Exit\n";
			break;
		default:
			cout << "Invalid choice\n";
		}
	} while (choice != 3);
	return 0;
}