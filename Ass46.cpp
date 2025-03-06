//46.	Write a class Student having following –
//a.Student Roll Number(int)
//b.Student Name(char array)
//c.Date of Birth(Date class object where Date is user defined class)
//Implement default constructor, parameterized constructor, accept, display.
//Generate the student roll number automatically.
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
	void accept();
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
void Date::accept() {
	cout << "Enter the Date:" << endl;
	cin >> day;
	cout << "Enter the Month:" << endl;
	cin >> month;
	cout << "Enter the year:" << endl;
	cin >> year;
}
void Date::display() {
	cout << "Date of Birth is: " << day << "/" << month << "/" << year << endl;
}

class Student
{
	int rollno;
	char name[20];
	static int num;
	Date dob;
public:
	Student();
	Student(const char*, int, int,int);
	void accept();
	void display();
};
int Student::num=0;
Student::Student() {
	num++;
	rollno = num;
	strcpy(name, "Ajay");
}
Student::Student(const char* n, int d, int m, int y):dob(d,m,y) {
	num++;
	rollno = num;
	strcpy(name, n);
}
void Student::accept() {
	cout << "Roll no: " << rollno << endl;
	cout << "Enter the name of student :" << endl;
	cin >> name;
	cout << "Enter the Birth Date of Student :" << endl;
	dob.accept();
}
void Student::display() {
	cout << "Student Roll noumber is:" <<rollno<< endl;
	cout << "Student Name is: " << name << endl;
	dob.display();
}

int main() {
	Student s1;
	s1.accept();
	s1.display();
}


