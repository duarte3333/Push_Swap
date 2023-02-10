/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:22:11 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/10 21:16:20 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_nb_less(t_list *stack, int nb)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->content < nb)
			counter++;
		stack = stack->next;
	}
	return (counter);
}

int	ft_get_nb_high(t_list *stack, int nb)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->content > nb)
			counter++;
		stack = stack->next;
	}
	return (counter);
}

int	ft_get_median(t_list *stack)
{
	int		nb_small;
	int		nb_high;
	int		median;
	int		size;
	t_list	*temp;

	size = ft_lstsize(stack);
	//printf("size: %i\n", size);
	temp = stack;
	while (stack)
	{
		nb_small = ft_get_nb_less(temp, ((stack)->content));
		//printf("small: %i\n", nb_small);
		nb_high = ft_get_nb_high(temp, ((stack)->content));
		//printf("high: %i\n", nb_high);
		if (nb_small == nb_high && (size % 2 == 1))
		{
			median = (stack)->content;
			break ;
		}
		else if (((nb_small - 1) == nb_high) && (size % 2 == 0))
		{
			median = (stack)->content;
			break ;
		}
		(stack) = (stack)->next;
	}
	return (median);
}

void	ft_recursion(t_list **stack_a, t_list **stack_b, int median)
{
	while ((*stack_a))
	{
		if ((*stack_a) <= median)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	ft_quick_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		median;
	int		size_a;

	size_a = ft_lstsize(*stack_a);

	if (*stack_a)
	{		
		median = ft_get_median(*stack_a);
		temp = *stack_a;
		while ((*stack_a))
		{
			if ((*stack_a) <= median)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			(*stack_a) = (*stack_a)->next;
		}
		//if (ft_lstsize(*stack_b) != size_a)
		//	ft_quick_sort(&temp, stack_b);
	}
}
