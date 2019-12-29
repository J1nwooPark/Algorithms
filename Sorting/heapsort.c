void InsertMaxHeap(int heap_arr[], int target, int i)
{
	while (i != 1 && target > heap_arr[i / 2])
	{
		heap_arr[i] = heap_arr[i / 2];
		i /= 2;
	}
	heap_arr[i] = target;
}
void DeleteMaxHeap(int arr[], int heap_arr[], int size, int i)
{
	arr[size - i - 1] = heap_arr[1];
	heap_arr[1] = heap_arr[size - i];
	int cur = 1, temp;
	int heap_size = size - i - 1;
	int left = cur * 2, right = cur * 2 + 1;
	while (cur != heap_size && ((left <= heap_size && heap_arr[left] > heap_arr[cur]) || (right <= heap_size && heap_arr[right] > heap_arr[cur])))
	{
		if (heap_arr[left] < heap_arr[right])
		{
			if (right <= heap_size)
			{
				temp = heap_arr[right];
				heap_arr[right] = heap_arr[cur];
				heap_arr[cur] = temp;
				cur = right;
			}
		}
		else
		{
			temp = heap_arr[left];
			heap_arr[left] = heap_arr[cur];
			heap_arr[cur] = temp;
			cur = left;
		}
		left = cur * 2;
		right = left + 1;
	}
}
void HeapSort(int arr[], int size)
{
	int* heap_arr = new int[size + 1];
	for (int i = 1; i <= size; i++)
		InsertMaxHeap(heap_arr, arr[i - 1], i);
	for (int i = 0; i < size; i++)
		DeleteMaxHeap(arr, heap_arr, size, i);
	delete[] heap_arr;
}
