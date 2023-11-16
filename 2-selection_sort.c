#include "sort.h"
/**
 * selection_sort - sorts an array using selection sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, minj;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        minj = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[minj])
            {
                minj = j;
            }
        }
        if (minj != i)
        {
            temp = array[i];
            array[i] = array[minj];
            array[minj] = temp;
            print_array(array, size);
        }
    }
}
