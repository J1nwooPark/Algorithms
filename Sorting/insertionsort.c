#include <iostream>
using namespace std;
void InsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int cur = arr[i];
		int j = i - 1;
		while (j >= 0 && cur < arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = cur;
	}
}
