#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge_element(int *arr, int low, int high, int order, size_t size)
{
	if (high > 1)
	{
		int position = high / 2;
		int temp = 0;
		int j = 0;
		int i = 0;

		for (i = low; i < low + position; i++)
		{
			j = i + position;
			if ((order == 1 && arr[i] > arr[j]) || (order == 0 && arr[i] < arr[j]))
			{
                printf("Merging [%d/%d]", (2**high), size);
                if (order == 1)
                {
                    printf(" (UP):\n");
                }
                else
                {
                    printf(" (DOWN):\n");
                }
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
                print_array(arr, size);
			}
		}
		merge_element(arr, low, position, order, size);
		merge_element(arr, low + position, position, order, size);
	}
}

void bitonicsort(int *arr, int low, int high, int order, size_t size)
{
    int position;
	
	if (high > 1)
	{
		position = high / 2;

		bitonicsort(arr, low, position, 1, size);
		bitonicsort(arr, low + position, position, 0, size);
		merge_element(arr, low, high, order, size);
	}
}
void bitonic_sort(int *array, size_t size)
{
	bitonicsort(array, 0, size, 1, size);
}
