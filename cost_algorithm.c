/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:15:13 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/24 18:46:46 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_rotate_until_last_is_last(t_list **stack_a)
// {
// 	int max;
// 	int index;
// 	int nb_rotations;

// 	//printf("RO TA TE\n");
// 	max = ft_get_max(*stack_a);
// 	index = ft_get_index(max, *stack_a) + 1;
// 	nb_rotations = ft_lstsize(*stack_a) - index;
// 	if (index < nb_rotations)
// 	{	
// 		while (index)
// 		{
// 			ra(stack_a);
// 			index--;
// 		}
// 	}
// 	else
// 	{
// 		while (nb_rotations)
// 		{
// 			rra(stack_a);
// 			nb_rotations--;
// 		}
// 	}
// }


int	ft_calculate_cost_up(int size, int index)
{
	int counter;
	
	if (index <= (size / 2))
	{
		counter = index;
	}
	else if(index > (size / 2))
		counter = size - index;	
	return (counter);
}

int ft_get_best_buddy(t_list **stack_a, int nb)
{
	int best_buddy;
	int counter;
	t_list *temp;

	counter = INT_MAX;		
	//printf("counter %i\n", counter);
	best_buddy = 0;
	temp = *stack_a;
	while (*stack_a)
	{
		//printf("counter %i\n", counter);
		//printf("best_buddy %i\n", best_buddy);
		if (((*stack_a)->content - nb) < counter && ((*stack_a)->content - nb) > 0)
		{
			counter = (*stack_a)->content - nb;
			best_buddy = (*stack_a)->content;
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp;
	if (best_buddy == 0)
		return (-1);
	//printf("best_buddy %i\n", best_buddy);
	//printf("index %i\n", ft_get_index(best_buddy, *stack_a));
	return (ft_get_index(best_buddy, *stack_a));
}

int	*ft_get_cost_best_buddy(t_list **stack_a, t_list **stack_b)
{
	int index_bf;
	int cost_bf;
	int cost_nb;
	int best;
	int final_bf;
	int final_nb;
	int index_nb;
	int size_b;
	int size_a;
	t_list *temp;

	best = INT_MAX;
	temp = *stack_b;
	index_nb = 0;
	size_b = ft_lstsize(*stack_b);
	size_a = ft_lstsize(*stack_a);
	while (*stack_b)	
	{
		//printf("nb %i\n", (*stack_b)->content);
		index_bf = ft_get_best_buddy(stack_a, (*stack_b)->content);
		if (index_bf != -1)
		{
			//printf("index bf %i\n", index_bf);
			cost_bf = ft_calculate_cost_up(size_a, index_bf);
			//printf("cost bf %i\n", cost_bf);
			//printf("index nb %i\n", index_nb);
			cost_nb = ft_calculate_cost_up(size_b, index_nb);
			//printf("cost nb %i\n", cost_nb);
			//printf("COST %i\n", cost_nb + cost_bf);
			if ((cost_bf + cost_nb) < best && (cost_bf + cost_nb) >= 0)
			{	
				final_nb = index_nb;
				final_bf = index_bf;
				best = cost_bf + cost_bf;
				//printf("final bf %i, final nb %i\n\n", final_bf, final_nb);
			}
		}
		//printf("-------------\n");
		(*stack_b) = (*stack_b)->next;
		index_nb++;
	}
	*stack_b = temp;
	ft_put_top_a(stack_a, final_bf);
	ft_put_top_b(stack_b, final_nb);
	//print_list(*stack_a, *stack_b);
	pa(stack_a, stack_b);
	//print_list(*stack_a, *stack_b);

}

void	a_to_b(t_list **stack_a, t_list **stack_b, int *arr_last_five)
{
	int	min;
	int	size_chunk;
	int	l;
	int	r;
	int j;
	int flag;

	min = ft_get_min(*stack_a);
	size_chunk = 50;
	l = min;
	r = min + size_chunk - 1;
	j = 0;
	while (ft_lstsize(*stack_a) > 5)
	{	
		//printf("nb %i\n", (*stack_a)->content);
		if (ft_get_int(ft_get_index(0, *stack_a), *stack_a) >= l \
			&& ft_get_int(ft_get_index(0, *stack_a), *stack_a) <= r)
		{
			if (ft_nb_in_last_five((*stack_a)->content, arr_last_five))
				ra(stack_a);
			else 
			{
				pb(stack_a, stack_b);
				j++;
			}
		}
		if (j == (size_chunk))
		{
			l += size_chunk;
			r += size_chunk;
			j = 0;
		}
		ra(stack_a);
	}
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

void	ft_cost_algorithm(t_list **stack_a, t_list **stack_b)
{

	int *arr_last_five;
	arr_last_five = ft_previous_sort(*stack_a);
	// int i = 0;
	// while (i < 5)
	// {
	// 	printf("array %i\n", arr_last_five[i]);
	// 	i++;
	// }
	
	
	//a_to_b(stack_a, stack_b, arr_last_five);
	while (ft_lstsize(*stack_a) > 5)
	{
		if (ft_nb_in_last_five((*stack_a)->content, arr_last_five))
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	free(arr_last_five);
	ft_sort_five(stack_a, stack_b);
	//print_list(*stack_a, *stack_b);
	while (ft_lstsize(*stack_b) > 0)
		ft_get_cost_best_buddy(stack_a, stack_b);
	ft_rotate_until_last_is_last(stack_a);
	//print_list(*stack_a, *stack_b);
}

