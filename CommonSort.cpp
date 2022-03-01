#include<iostream>
using namespace std;

int max(int* arr, int size)
{
	int max = arr[0];

	for (int i = 0; i < size; i++)
		if (arr[i] > max)
			max = arr[i];

	return max;
}

void display(int* arr, int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	
	cout << endl;
}

int main()
{
	// Unique Sort

	int size = 10;
	int* arr = new int [size] { 22, 68, 19, 26, 1, 45, 29, 3, 6, 12 };

	int max_index = max(arr, size); // get the max value from the (arr) : O(n)
	// O = time complexity
	// n = size of array

	bool* values_till_max = new bool[max_index] { false }; // creating new memory of size m : O*(m)
	// O* = space complexity
	// m = max value of array

	for (int i = 0; i < size; i++)
		values_till_max[arr[i]] = true; // assigning true to the arr index of (values_till_max) : O(n)

	int res_index = 0; // for storing sorted array to the (arr)

	display(arr, size);

	for (int i = 0; i <= max_index; i++)
	{
		if (values_till_max[i])
			arr[res_index++] = i; // getting the value from (values_till_max) and storing in (arr) array : O(m)
	}

	display(arr, size);

	// time complexity = O(n) + O(n) + O(m) 
	// = O(n) (if n > m) 
	// or
	// = O(m) (if m > n)
	 
	// space complexity = O*(m)

	return 0;
}