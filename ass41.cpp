//41.	Write a class Array which will store integer elements in dynamically allocated space.
//class Array
//{
//	int size;
//	int* arr;
//}
//Provide below functions in Array class -
//1. Default constructor - Take 5 as default size.Initialize the array elements to 0
//2. Parameterized constructor - Takes size as parameter.Initialize the array elements to 0.
//3. Copy constructor - Performs deep copy of Array object.
//4. Destructor - Deletes memory which is allocated dynamically.

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Array {
	int size;
	int* arr;
public:
	Array();
	Array(int);
	Array(Array& a);
	~Array();
};

Array::Array() {
	size = 5;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	cout << "Default constructor" << endl;
}
Array::Array(int s) {
	size = s;
	arr = new int[s+1];
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	cout << "Parameterized constructor" << endl;
}
Array::Array(Array& a) {
	size = a.size;
	arr = new int[a.size + 1];
	cout << "Copy constructor" << endl;
}
Array::~Array() {
	delete[]arr;
	cout<<"Destructor"<< endl;
}
int main() {
	Array a1;
	Array a2(3);
	Array a3(a1);
	return 0;
}
