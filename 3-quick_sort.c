#include "sort.h"


void quick(int *array, int start, int end, size_t size)
{
	int i, j;
	int buffer, pivot;
	if (start >= end)
	{
		return;
	}

	pivot = array[end];
	j = start - 1;
	for (i = start; i <= end - 1; i++)
	{
		if (array[i] < pivot)
		{
			j += 1;
			buffer = array[i];
			array[i] = array[j];
			array[j] = buffer;
			print_array(array, size);
		}
	}
	buffer = array[end];
	array[end] = array[j + 1];
	array[j + 1] = buffer;

	quick(array, start, j, size);
	quick(array, j + 2, end, size);
}

/**
  * quick_sort - sorts an array of integers in
  * ascending order using the Quick sort algorithm
  * @array: this is the array that is to be sorted
  * @size: this is the size of the array to be sorted
  */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end = size - 1;	

	quick(array, start, end, size);

}


