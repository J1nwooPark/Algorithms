void BucketSort(int arr[], int size, int range)
{
	int arr_idx = 0;
	int* bucket_array = new int[range]();
	for (int i = 0; i < size; i++)
		bucket_array[arr[i]]++;
	for (int i = 0; i < range; i++)
		if (bucket_array[i])
			arr[arr_idx++] = i;
}
