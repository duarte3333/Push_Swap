/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_aux_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:54:09 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 14:33:53 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_until_last_is_last(t_list **stack_a, char moves[], int i)
{
	int	max;
	int	index;
	int	nb_rotations;

	max = ft_get_max(*stack_a);
	index = ft_get_index(max, *stack_a) + 1;
	nb_rotations = ft_lstsize(*stack_a) - index;
	if (index < nb_rotations)
	{	
		while (index--)
		{
			ra(stack_a, moves, i);
			i++;
		}
	}
	else
	{
		while (nb_rotations--)
		{
			rra(stack_a, moves, i);
			i++;
		}
	}
	return (i);
}

int	ft_get_dynamic_average(t_list *stack_a)
{
	long long	sum;
	int			average;
	int			size;

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
