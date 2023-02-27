#include "push_swap.h"


int	ft_rotate_until_last_is_last(t_list **stack_a, int moves[], int i)
{
	int max;
	int index;
	int nb_rotations;

	max = ft_get_max(*stack_a);
	index = ft_get_index(max, *stack_a) + 1;
	nb_rotations = ft_lstsize(*stack_a) - index;
	if (index < nb_rotations)
	{	
		while (index)
		{
			ra(stack_a, moves, i);
			i++;
			index--;
		}
	}
	else
	{
		while (nb_rotations)
		{
			rra(stack_a, moves, i);
			i++;
			nb_rotations--;
		}
	}
	return (i);
}

int	*ft_previous_sort(t_list *stack_a)
{
	int *array_last_five;
	int *array;
	int i;
	int j;
	int size;

	size = ft_lstsize(stack_a);
	array = (int *)malloc(sizeof(int) * (size + 1));
	array_last_five = (int *)malloc(sizeof(int) * (5 + 1));
	if (array)
		array[size] = 0;
	if (array_last_five)
		array[5] = 0;
	while (i < size)
	{
		array[i] = (stack_a)->content;
		stack_a = (stack_a)->next;
		i++;
	}
	quicksort(array, size);
	i = size;
	j = 0;
	while (j < 5)
	{
		array_last_five[j] = array[i - 1];
		i--;
		j++;
	}
	free(array);
	return (array_last_five);
}

int	ft_nb_in_last_five(int nb, int *array)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (nb == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_dynamic_average(t_list *stack_a)
{
	int i;
	int sum;
	int average;
	int size;

	sum = 0;
	size = ft_lstsize(stack_a);
	while (stack_a)
	{
		sum += stack_a->content;
		stack_a = stack_a->next;
	}
	average = sum / size;
	return (average);	
}
