#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - counting_sort of a array
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int size2 = size;
	int max = array[0];
	int *array1;
	int *output;
	int i;

	for (i = 1; i < size2; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	array1 = malloc(sizeof(int) * max);
	output = malloc(sizeof(int) * size);
	for (i = 0; i <= max; ++i)
	{
		array1[i] = 0;
	}
	for (i = 0; i < size2; i++)
	{
		array1[array[i]]++;
	}
	for (i = 1; i <= max; i++)
	{
		array1[i] += array1[i - 1];
	}
	print_array(array1, max + 1);
	for (i = size - 1; i >= 0; i--)
	{
		output[array1[array[i]] - 1] = array[i];
		array1[array[i]]--;
	}
	for (i = 0; i < size2; i++)
	{
		array[i] = output[i];
	}
	free(array1);
	free(output);
}
