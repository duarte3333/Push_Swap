#include "push_swap.h"

int	partition(t_list **stack_a, t_list **stack_b, int low, int high)
{
	int	pivot_index;
	int	pivot_value;
	int	i;
	int	j;

	pivot_index = ft_get_index(high, stack_a);

	//if (pivot_index != high)
	//	swap(&array[pivot_index], &array[high]);

	pivot_value = ft_get_int(pivot_index, stack_a);
	i = low;
	j = low;
	while (j < high)
	{
		if (ft_get_int(j, stack_a) <= pivot_value)
		{
			// swap_two(stack_a, stack_b, \
			// 	ft_get_index(ft_get_int(i, stack_a), stack_a), \
			// 	ft_get_index(ft_get_int(j, stack_a), stack_a));
			pb(stack_a, stack_b);
			i++;
		}
		j++;
	}
	// swap_two(stack_a, stack_b, \
	// 	ft_get_index(ft_get_int(i, stack_a), stack_a), \
	// 	ft_get_index(ft_get_int(high, stack_a), stack_a));
	pa(stack_a, stack_b);
	return (i);
}

void	quicksort_recursion(t_list **stack_a, t_list **stack_b, \
	int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(stack_a, stack_b, low, high);
		quicksort_recursion(stack_a, stack_b, low, pivot_index - 1);
		quicksort_recursion(stack_a, stack_b, pivot_index + 1, high);
	}
}

void	quicksort(t_list **stack_a, t_list **stack_b, int length)
{
	quicksort_recursion(stack_a, stack_b, 0, length - 1);
}


