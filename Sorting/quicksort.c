void QuickSort(int arr[], int size)
{
	if (size <= 1) return;

	int pivot = arr[size - 1];
	int less_size = 0, equal_size = 0, greater_size = 0;
	int* arr_less = new int[size];
	int* arr_equal = new int[size];
	int* arr_greater = new int[size];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < pivot) arr_less[less_size++] = arr[i];
		else if (arr[i] == pivot) arr_equal[equal_size++] = arr[i];
		else arr_greater[greater_size++] = arr[i];
	}
	QuickSort(arr_less, less_size);
	QuickSort(arr_greater, greater_size);
	for (int i = 0; i < less_size; i++)
		arr[i] = arr_less[i];
	for (int i = 0; i < equal_size; i++)
		arr[less_size + i] = arr_equal[i];
	for (int i = 0; i < greater_size; i++)
		arr[less_size + equal_size + i] = arr_greater[i];
	delete[] arr_less, arr_equal, arr_greater;
}
