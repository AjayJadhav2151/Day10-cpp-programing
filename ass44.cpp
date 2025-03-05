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
//
//44.	Modify class Array  in assignment – 41 to overload below operators
//1. Overloaded[] operator - used to get / set array element e.g.arr[4] gives 4th   index element
//2. Overloaded !operator - reverses array elements.
//3. Overload >> -Accepts array size from user.Also accepts elements of array from user.
//4. Overload << -Displays array.
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Array {
	int size;
	int* arr;
public:
	Array();
	Array(int);
	/*Array(Array& a);
	~Array();*/
	void display();
	int operator[](int a){
		return arr[a];
	}
	void operator!() {
		int temp = 0;
		for (int i = 0; i < size / 2; i++) {

		}
	}
};

Array::Array() {
	size = 5;
	arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = 0;
	}
	//for (int i = 0; i < 5; i++) {
	//	cout << arr[i];
	//}
	//cout << "Default constructor" << endl;
}
Array::Array(int s) {
	size = s;
	arr = new int[s + 1];
	for (int i = 0; i < size; i++) {
		cin>>arr[i];
	}
	for (int i = 0; i < size; i++) {
		cout<< arr[i]<<endl;
	}
	//cout << "Parameterized constructor" << endl;
}
void Array::display() {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
//Array::Array(Array& a) {
//	size = a.size;
//	arr = new int[a.size + 1];
//	//cout << "Copy constructor" << endl;
//}
//Array::~Array() {
//	delete[]arr;
//	//cout << "Destructor" << endl;
//}
int main() {
	Array a1;
	Array a2(3);
	//Array a3(a1);
	cout <<a2[2];
	return 0;
}