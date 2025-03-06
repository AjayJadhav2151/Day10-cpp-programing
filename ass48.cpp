//48.	Modify above assignment 47 as given below –
//a.Create Employee pointer and allow it to hold address of any Employee objects(WageEmployee &
// SalesPerson) created on heap
//b.Using Employee pointer call accept() and display() to accept and display the details of
// dynamically created objects.
//c.Free the memory for the objects created on heap
//d.Make the Employee class  as abstract.


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);
	void display();
};

Date::Date() {
	day = 1;
	month = 1;
	year = 2001;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

void Date::display() {
	cout << "Date of Birth is: " << day << "/" << month << "/" << year << endl;
}

class Employee
{
	int empid;
	char name[20];
	Date date;
public:
	Employee();
	Employee(int, const char*, int, int, int);
	void display();
};

Employee::Employee() {
	empid = 101;
	strcpy(name, "Ajay");
}

Employee::Employee(int id, const char* n, int d, int m, int y) :date(d, m, y) {
	empid = id;
	strcpy(name, n);
}

void Employee::display() {
	cout << "Employee Id: " << empid << endl;
	cout << "Employee Name: " << name << endl;
	date.display();
}

class WageEmployee : public Employee
{
	int hours;
	int rate;
public:
	WageEmployee();
	WageEmployee(int, const char*, int, int, int, int, int);
	void display();
	int calcSalary();
};

WageEmployee::WageEmployee() {
	hours = 5;
	rate = 50;
}
WageEmployee::WageEmployee(int id, const char* n, int d, int m, int y, int h, int r) :Employee(id, n, d, m, y) {
	hours = h;
	rate = r;
}
void WageEmployee::display() {
	Employee::display();
	cout << "Hours " << hours << endl;
	cout << "Rate per Hours " << rate << endl;
	cout << "WageEmployee Salary " << calcSalary() << endl;
}
int WageEmployee::calcSalary() {
	return hours * rate;
}

class SalesPerson : public WageEmployee
{
	int sale;
	int commi;
public:
	SalesPerson();
	SalesPerson(int, const char*, int, int, int, int, int, int, int);
	void display();
	int calcSalary();
};

SalesPerson::SalesPerson() {
	sale = 5;
	commi = 3;
}
SalesPerson::SalesPerson(int id, const char* n, int d, int m, int y, int h, int r, int s, int c) :WageEmployee(id, n, d, m, y, h, r) {
	sale = s;
	commi = c;
}
void SalesPerson::display() {
	WageEmployee::display();
	cout << "Number of items sold " << sale << endl;
	cout << "Commission per item " << commi << "% " << endl;
	cout << "SalesPerson Salary " << calcSalary() << endl;
}
int SalesPerson::calcSalary() {
	return WageEmployee::calcSalary() + sale * commi;
}

int main() {
	Employee e1;
	e1.display();
	SalesPerson s2(102, "PushPak", 12, 11, 2001, 10, 900, 500, 3);
	s2.display();
}