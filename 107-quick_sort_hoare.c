#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * swap - swap two integers together
 * @a: second to be swaped
 * @b: first to be swaped
 *
 * Return: void
 */
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
}

/**
 * partition - partition sort of an array in assending order
 * @arr: array to be sorted
 * @low: low of the array
 * @high: high of the array
 * @size: size of array
 *
 * Return: void
 */
int partition(int *arr, int low, int high, size_t size)
{ 
	int pivot = arr[high];
	int i = low;
	int j = high;

	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
			return j;
		swap(&arr[i], &arr[j]);
		print_array(arr, size);
		i++;
		j--;
	}
}

/**
 * quickSort - quick sort of an array in assending order
 * @arr: array to be sorted
 * @low: low of the array
 * @high: high of the array
 * @size: size of array
 *
 * Return: void
 */
void quickSort(int *arr, int low, int high, size_t size)
{ 
	if (low < high) 
	{
		int pi = partition(arr, low, high, size);

		quickSort(arr, low, pi - 1, size); 
		quickSort(arr, pi, high, size);
	} 
}
void quick_sort_hoare(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
