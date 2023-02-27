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
	long int best_buddy;
	int counter;
	t_list *temp;

	counter = INT_MAX;		
	//printf("counter %i\n", counter);
	best_buddy = INT_MAX + 1;
	temp = *stack_a;
	while (*stack_a)
	{
		//printf("counter %i\n", counter);
		//printf("best_buddy %i\n", best_buddy);
		if (((*stack_a)->content - nb) < counter && ((*stack_a)->content > nb))
		{
			counter = (*stack_a)->content - nb;
			best_buddy = (*stack_a)->content;
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp;
	if (best_buddy == INT_MAX + 1)
		return (-1);
	//printf("best_buddy %i\n", best_buddy);
	//printf("index %i\n", ft_get_index(best_buddy, *stack_a));
	return (ft_get_index(best_buddy, *stack_a));
}

int	*ft_get_cost_best_buddy(t_list **stack_a, t_list **stack_b, int moves[], int i)
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
				best = cost_nb + cost_bf;
				//printf("final bf %i, final nb %i\n\n", final_bf, final_nb);
			}
		}
		//printf("-------------\n");
		(*stack_b) = (*stack_b)->next;
		index_nb++;
	}
	*stack_b = temp;
	i = ft_put_top_a(stack_a, final_bf, moves, i);
	i = ft_put_top_b(stack_b, final_nb, moves, i);
	//print_list(*stack_a, *stack_b);
	i = pa(stack_a, stack_b, moves, i);
	return (i);
	//print_list(*stack_a, *stack_b);

}


int	ft_cost_algorithm(t_list **stack_a, t_list **stack_b, int moves[], int i)
{

	int *arr_last_five;
	int average;

	arr_last_five = ft_previous_sort(*stack_a);
	average = ft_get_dynamic_average(*stack_a);
	while (ft_lstsize(*stack_a) > 5)
	{
		if (ft_nb_in_last_five((*stack_a)->content, arr_last_five) || \
			(*stack_a)->content > average)
			i = ra(stack_a, moves, i);
		else
		{
			i = pb(stack_a, stack_b, moves, i);
			average = ft_get_dynamic_average(*stack_a);
		}
	}
	free(arr_last_five);
	i = ft_sort_five(stack_a, stack_b, moves, i);
	//print_list(*stack_a, *stack_b);
	while (ft_lstsize(*stack_b) > 0)
		i = ft_get_cost_best_buddy(stack_a, stack_b, moves, i);
	i = ft_rotate_until_last_is_last(stack_a, moves, i);
	return (i);
	//print_list(*stack_a, *stack_b);
}

