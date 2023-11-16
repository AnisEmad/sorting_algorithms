#include "sort.h"

/**
 * swap - swap two givin elements
 *
 * Return: void
 *
 * @a: the first element to swap
 *
 * @b: the second element to swap
*/

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort_recursive - make the recursive function to sort the data
 *
 * Return: void
 *
 * @arr: the array to sort
 *
 * @low: the first element of array
 *
 * @high: the last element of the array
 *
 * @n: the size of the array
*/

void quick_sort_recursive(int arr[], int low, int high, size_t n)
{
	int pi, pivot, i, j;

	if (low < high)
	{
		pivot = arr[high];
		i = low - 1;
		for (j = low; j <= high; j++)
		{
			if (arr[j] < pivot)
			{
				i++;
				if (i != j)
				{
					swap(&arr[i], &arr[j]);
					print_array(arr, n);
				}
			}
		}
		if (i + 1 != high)
		{
			swap(&arr[i + 1], &arr[high]);
			print_array(arr, n);
		}
		pi = i + 1;
		quick_sort_recursive(arr, low, pi - 1, n);
		quick_sort_recursive(arr, pi + 1, high, n);
	}
}

/**
 * quick_sort - sort data in array by quick sort
 *
 * Return: void
 *
 * @array: the array to sort
 *
 * @size: the size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0 || *array == NULL)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
