void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void SelectionSort(int arr[], int size)
{
	int min_idx = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
			if (arr[j] < arr[min_idx]) 
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
        min_idx = i + 1;
	}
}
