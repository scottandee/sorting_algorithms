#include "sort.h"

int partition(int *array, int start, int end, size_t size)
{
	int i, j, buffer, pivot;

	pivot = array[end];
	j = start - 1;
	for (i = start; i <= end - 1; i++)
	{
		if (array[i] < pivot)
		{
			j = j + 1;
			buffer = array[i];
			array[i] = array[j];
			array[j] = buffer;
			print_array(array, size);
		}
	}
	buffer = array[end];
	array[end] = array[j + 1];
	array[j + 1] = buffer;
	print_array(array, size);

	return (j + 1);
}
/**
  * quick - this is the quiick sort algorithm
  * @array: this is the array that is to be sorted
  * @start: this is the point at which the sorting should start
  * @end: this is the point where the sorting should end
  * @size: this is the size of the array
  */

void quick(int *array, int start, int end, size_t size)
{
	int p;

	if (start <= end)
	{
		p = partition(array, start, end, size);
		quick(array, start, p - 1, size);
		quick(array, p + 1, end, size);
	}
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
