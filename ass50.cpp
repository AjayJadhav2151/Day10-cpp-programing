//50.	Write a template function “Sort” to sort data of any kind.e.g. int, char, float, double

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<typename T>
void BubbleSort(T *arr, int n) {
	int i, j;
	T temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[i + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	int arr[] = { 12,6,5,2,10 };
	BubbleSort(arr,5);
	for (int i = 0; i < 5; i++)
		cout << arr[i] << "  ";
	cout << endl;

	float a[5] = { 1.2,0.6,5.12,2.0,1.0 };
	BubbleSort(a, 5);
	for (int i = 0; i < 5; i++)
		cout << a[i] << "  ";
	cout << endl;
	return 0;
}