#include <algorithm>
using namespace std;
void SelectionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min_idx = i;
		for (int j = i; j < size; j++)
			if (arr[j] < arr[min_idx]) 
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}
