//42.	Write a class Employee for an application which will have data members for employee id, 
//employee name and salary.Provide the following functionalities in Employee class.
//1. Initialing objects using default and parameterized constructors.
//2. Accepting and displaying the information of employee from console
//
//class Employee
//{
//	int emp_id;
//	char emp_name[20];
//	double salary;
//public:
//	Employee();
//	Employee(int, char*, double);
//	void Accept();
//	void Display();
//};
//
//In "main" function declare an array of Employee objects.Write a menu driven program to -
//a.Insert record into an array.
//b.Update information of specific employee on the basis of emp_id accepted from user
//c.Display all records.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Employee
{
	int emp_id;
	char emp_name[20];
	double salary;
public:
	Employee();
	Employee(int, char*, double);
	void Accept();
	void Display();
	int getnewId();
	void update();
};

int Employee::getnewId() {
	return emp_id;
}
void Employee::update() {
	cout << "Employee Id Found!!!!" << endl;
	int up;
	cout << "If you want to update name type 1 and for salary type 0" << endl;
	cin >> up;
	if (up == 1) {
	cout << "Update Employee name:" << endl;
	cin >> emp_name;
	cout << "name updated!!" << endl;
	}
	else if (up == 0) {
	cout << "Update Employee salary:" << endl;
	cin >> salary;
	cout << "salary updated!!" << endl;
	}
	else
	{
		cout << "invalid choice" << endl;
	}
}
Employee::Employee() {
	emp_id = 0;
	strcpy(emp_name, "");
	salary = 0.0;
}

Employee::Employee(int id, char* name, double sal) {
	emp_id = id;
	strcpy(emp_name , name);
	salary = sal;
}

void Employee::Accept() {
	cout << "Enter the Employee Id:" << endl;
	cin >> emp_id;
	cout << "Enter the Employee name:" << endl;
	cin >> emp_name;
	cout << "Enter the Employee salary:"<< endl;
	cin >> salary;
}

void Employee::Display() {
	cout<<"Emplyee Id is:"<< emp_id << endl;
	cout << "Employee name is:" << emp_name << endl;
	cout << "Employee salary is:" << salary << endl;
}

int main() {
	int getid;
	Employee emp[5];
	char ch;
	do {
	cout << "\t\tMenu\t\t" << endl;
	cout << "a.Insert Employee record " << endl;
	cout << "b.Update information of like Name and Salary" << endl;
	cout << "c.Display all Employee records." << endl;
	cout << "Enter your choice in character" << endl;
	cin >> ch;
	switch (ch)
	{
	case 'a':
		cout << "Enter the Three employee info" << endl;
		for (int i = 1; i <= 3; i++) {
			emp[i].Accept();
		}

		break;
	case 'b':
		cout << "Enter the Employee Id" << endl;
		cin >>getid;
		for (int i = 1; i <= 3; i++) {
			if (getid == emp[i].getnewId()) {
				emp[i].update();
			}
		}
		break;
	case 'c':
		for (int i = 1; i <= 3; i++) {
			emp[i].Display();
		}
		break;
	default:
		cout << "invalid input" << endl;
		break;
	}
	} while (ch != 'd');
	return 0;
}
