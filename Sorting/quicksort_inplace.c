#include <algorithm>
using namespace std;
void QuickSort_inplace(int arr[], int start, int end)
{
	if (start >= end) return;
	int pivot = arr[end];
	int left = start, right = end - 1;
	while (left <= right)
	{
		while (left <= right && arr[left] <= pivot) left++;
		while (right >= left && arr[right] >= pivot) right--;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	swap(&arr[left], &arr[end]);
	QuickSort_inplace(arr, start, left - 1);
	QuickSort_inplace(arr, left + 1, end);
}
