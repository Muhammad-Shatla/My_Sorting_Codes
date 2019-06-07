#include <iostream>
#include <cmath>
#include <string>

//#include<string.h>

using namespace std;

template<typename T>
T maxValue(T value1, T value2)  /*Generic Function Template to get the max of two inputs of any primitive
								data type.*/
{
	if (value1 > value2)
		return value1;
	else
		return value2;
}

template<typename T>
void swap(T* pnum1, T* pnum2)   /*Generic Function Template to swap between two inputs of any primitive
								data type.*/ 
{
	T temp = *pnum1;

	*pnum1 = *pnum2;
	*pnum2 = temp;
}


template<typename T>
void SelectionSort(T* arr, int size)
{
	
	
	T temp; int maxIndex, temp_size = size - 1; /*the "temp_size" is to determine how many comparisons done in each 
												 iteration of "i"*/
	
	for (int i = 0; i < size; i++) /*the i-th element is the first element in the unsorted array*/
	{
		temp = arr[i];  //this temp variable is used to compare with other elements in the unsorted part of the array.

		maxIndex = i; //the index of the max element in the unsorted array

		for (int j = 0; j < temp_size; j++)
		{
			if (maxValue(*(arr + j + i), *(arr + j + 1 + i)) > temp) /*This condition assures that the "temp" variable
																	 will always contain the max element in the unsorted
																	 array.*/
			{
				temp = maxValue(*(arr + j + i), *(arr + j + 1 + i));

				maxIndex = j + i +1;
			}

		}
		
		temp_size--;
		
		swap(arr + i, arr + maxIndex);
		
		//cout << *(arr + i) << endl;
	}

	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << endl;
	}
}

int main()
{
	int* arr; int size;

	cout << "Enter the array size: ";

	cin >> size;

	arr = new int[size];

	cout << "\nEnter an unsorted array: ";

	for (int i = 0; i < size; i++)
	{
		cin >> *(arr + i);
	}

	SelectionSort(arr, size);

	delete[] arr;
}