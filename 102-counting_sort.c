#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	size_t i, max = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	print_array(count_array, max + 1);

	free(count_array);
	free(output_array);
}
