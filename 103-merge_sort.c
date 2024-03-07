#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <stdlib.h>

/**
 * merge_elements - merge elemets in array
 * @arr: array to sort
 * @front: front of the array to be merged
 * @tail: tail of the array to be merged
 * @middle: middle of the array to be merged
 *
 * Return: void
 */
void merge_elements(int *arr, int front, int tail, int middle)
{
	int s1 = (middle - front) + 1;
	int s2 = (tail - middle);
	int *firstsubarray;
	int *secondsubarray;
	int i;
	int j;
	int counter = 0;

	firstsubarray = malloc(sizeof(int) * s1);
	secondsubarray = malloc(sizeof(int) * s2);
	for (i = 0; i < s1; i++)
	{
		firstsubarray[i] = arr[front + i];
	}
	for (i = 0; i < s2; i++)
	{
		secondsubarray[i] = arr[middle + i + 1];
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(firstsubarray, s1);
	printf("[right]: ");
	print_array(secondsubarray, s2);
	i = 0;
	j = 0;
	while (counter < (s1 + s2))
	{
		if (i < s1 && j < s2)
		{
			if (firstsubarray[i] <= secondsubarray[j])
			{
				arr[front + counter] = firstsubarray[i];
				i++;
			}
			else
			{
				arr[front + counter] = secondsubarray[j];
				j++;
			}
		}
		else if (i < s1)
		{
			arr[front + counter] = firstsubarray[i];
			i++;
		}
		else
		{
			arr[front + counter] = secondsubarray[j];
			j++;
		}
		counter++;
	}
	printf("[Done]: ");
	print_array(arr, s1 + s2);
}

/**
 * sort_element - sort elemets in array
 * @arr: array to sort
 * @front: front of the array to be merged
 * @tail: tail of the array to be merged
 * @middle: middle of the array to be merged
 *
 * Return: void
 */
void sort_element(int *arr, int front, int tail)
{
	int m;

	if (front < tail)
	{
		m = (front + tail) / 2;

		sort_element(arr, front, m);
		sort_element(arr, m + 1, tail);

		merge_elements(arr, front, tail + 1, m);
	}
}

/**
 * merge_sort - merge elemets in array
 * @array: array to sort
 * @size: size of the array to be merged
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	sort_element(array, 0, size - 1);
}
