#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts a doubly linked list of integers in ascending order 
 * @array: array to be arranged
 * @size: size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	int gap = 1;
	int i;
	int num = size;
	int j;

	for (gap = gap * 3 + 1; gap > 0; gap /= 3)
	{
		for (i = gap; i < num; i++)
		{
			temp = array[i];
			
			for (j = i; j >= gap && array[j - gap] > temp; j -=gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
