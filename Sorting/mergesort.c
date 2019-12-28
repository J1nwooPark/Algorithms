void Merge(int arr_left[], int arr_right[], int arr[], int size)
{
	int left_idx = 0, right_idx = 0, arr_idx = 0;
	while (left_idx < size / 2 && right_idx < (size - size / 2))
	{
		if (arr_left[left_idx] < arr_right[right_idx])
			arr[arr_idx++] = arr_left[left_idx++];
		else
			arr[arr_idx++] = arr_right[right_idx++];
	}
	while (left_idx < size / 2)
		arr[arr_idx++] = arr_left[left_idx++];
	while (right_idx < (size - size / 2))
		arr[arr_idx++] = arr_right[right_idx++];
}
void MergeSort(int arr[], int size)
{
	if (size <= 1) return;
	int* arr_left = new int[size / 2];
	int* arr_right = new int[size - size / 2];
	for (int i = 0; i < size / 2; i++)
		arr_left[i] = arr[i];
	for (int i = 0; i < size - size / 2; i++)
		arr_right[i] = arr[size / 2 + i];
	MergeSort(arr_left, size / 2);
	MergeSort(arr_right, size - size / 2);
	Merge(arr_left, arr_right, arr, size);
}
