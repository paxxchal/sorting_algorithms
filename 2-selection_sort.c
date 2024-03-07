#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swap two integers together
 * @array: array to be sorted
 * @x: first to be sorted
 * @y: second place
 *
 * Return: void
 */
void swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t n;
	size_t i;
	size_t m;

	for (i = 0; i < size; i++)
	{
		n = i;
		for (m = i + 1; m < size; m++)
		{
			if (array[n] > array[m])
			{
				n = m;
			}
		}
		
		if (n != i)
		{
			swap(array, i, n);
			print_array(array, size);
		}
	}
}
