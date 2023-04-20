#include "sort.h"

/**
  * bubble_sort - sorts an array of integers in
  * ascending order using the Bubble sort algorithm
  * @array: this contains the numbers that are to be sorted
  * @size: this contains the size of the array that is to be sorted
  */

void bubble_sort(int *array, size_t size)
{
	int swaps, buffer;
	size_t i;

	while (1)
	{
		swaps = 0;

		for (i = 0; i < size; i++)
		{
			if (i == size - 1)
			{
				continue;
			}
			if (array[i] > array[i + 1])
			{
				buffer = array[i];
				array[i] = array[i + 1];
				array[i + 1] = buffer;
				swaps++;
				print_array(array, size);
			}
			else
			{
				continue;
			}
		}

		if (swaps == 0)
		{
			break;
		}
	}
}
