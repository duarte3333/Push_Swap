#include "push_swap.h"

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int array[], int low, int high)
{  
  int pivot_value;
  int i;
  
  pivot_value = array[high];
  i = low;

  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot_value)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[high]);
 
  return (i);
}

void quicksort_recursion(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot_index = partition(array, low, high);

    quicksort_recursion(array, low, pivot_index - 1);
    quicksort_recursion(array, pivot_index + 1, high);
  }
}

void quicksort(int array[], int length)
{
  quicksort_recursion(array, 0, length - 1);
}