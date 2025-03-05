//43.	Create objects c1, c2, c3, c4 of class Complex implemented earlier.
// Overload necessary operators to execute following statements
//a.c3 = c1 + c2
//b.c3 = c1 - c2
//c.c2 = -c1
//d.c4 = ++c1
//e.c4 = c1++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class complex {
	int real;
	int img;
public:
	complex();
	complex(int ,int);
	void accept();
	void display();
	complex operator+(complex&);
	complex operator-(complex&);
	complex operator-();
	complex operator++();
	complex operator++(int i);
	complex operator==(bool&);
};
complex::complex() {
	real = 0;
	img = 0;
}
complex::complex(int r, int i) {
	real = r;
	img = i;
}
complex complex ::operator+(complex& c) {
	complex temp;
	temp.real = real + c.real;
	temp.img = img + c.img;
	return temp;
}

complex complex ::operator-(complex& c) {
	complex temp;
	temp.real = real - c.real;
	temp.img = img - c.img;
	return temp;
}
complex complex ::operator-() {
	complex temp;
	temp.real = - 1 * real;
	temp.img = - 1 * img;
	return temp;
}
complex complex ::operator++() {
	complex temp;
	temp.real = ++real;
	temp.img = ++img;
	return temp;
}
complex complex ::operator++(int i) {
	complex temp;
	temp.real = real++;
	temp.img = img++;
	return temp;
}

bool complex :: operator==(complex& m) {
	complex temp;
	return (temp.F == m.F && temp.s == t.s);
}

void complex::accept() {
	cout << "Enter the value" << endl;
	cin >> real >> img;
}
void complex::display() {
	cout << real << "+" << img << "i" << endl;
}
int main() {
	complex c1(11,21), c2(12,22), c3(10,20), c4(11,22);
	
	c3 = c1 + c2;
	c3.display();
	
	c3 = c1 - c2;
	c3.display();
	
	c2 = -c1;
	c2.display();
	
	c4 = ++c1;
	c4.display();
	
	c4 = c1++;
	c4.display();
	
	return 0;
}