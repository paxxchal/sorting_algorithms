#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - counting_sort of a array
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */

void countingsort(int *array, size_t size, int exp)
{
	int size2 = size;
	int *array1;
	int *output;
	int i;

	array1 = malloc(sizeof(int) * 10);
	output = malloc(sizeof(int) * size);
	for (i = 0; i < 10; ++i)
	{
		array1[i] = 0;
	}

	for (i = 0; i < size2; i++)
	{
		array1[(array[i]/exp) % 10]++;
	}
	for (i = 1; i < 10; i++)
	{
		array1[i] += array1[i - 1];
	}
	for (i = size - 1; i >= 0; i--)
	{
		output[array1[(array[i]/exp) % 10] - 1] = array[i];
		array1[(array[i]/exp) % 10]--;
	}
	for (i = 0; i < size2; i++)
	{
		array[i] = output[i];
	}
	print_array(array, size2);
	free(array1);
	free(output);
}

int getMax(int *arr, int n)
{
	int mx = arr[0];
	int i;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > mx)
		{
			mx = arr[i];
		}
	}
	return mx;
}
void radix_sort(int *array, size_t size)
{
	int m = getMax(array, size);
	int exp;

	for (exp = 1; m / exp > 0; exp *= 10)
	{
		countingsort(array, size, exp);
	}
}
