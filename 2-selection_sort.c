#include "sort.h"

/**
  * selection_sort - sorts an array of integers in
  * ascending order using the Selection sort algorithm
  * @array: this is the array that is to be sorted
  * @size: this is the size of the array to be sorted
  */

void selection_sort(int *array, size_t size)
{
	int buffer;
	size_t i, j, min_idx, code;

	for (i = 0; i < size; i++)
	{
		buffer = array[i];
		code = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < buffer)
			{
				buffer = array[j];
				min_idx = j;
				code = 1;
			}
		}
		if (code == 1)
		{
			array[min_idx] = array[i];
			array[i] = buffer;
			print_array(array, size);
		}
	}
}
