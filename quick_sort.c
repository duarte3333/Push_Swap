/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:22:11 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/11 18:19:22 by dsa-mora         ###   ########.fr       */
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
	temp = stack;
	while (stack)
	{
		//printf("content: %i\n", (stack)->content);
		nb_small = ft_get_nb_less(temp, ((stack)->content));
		//printf("small: %i\n", nb_small);
		nb_high = ft_get_nb_high(temp, ((stack)->content));
		//printf("high: %i\n", nb_high);
		if (nb_small == nb_high && (size % 2 == 1))
		{
			median = (stack)->content;
			break ;
		}
		else if (((nb_small - 1) == (nb_high)) && (size % 2 == 0))
		{
			median = (stack)->content;
			break ;
		}
		(stack) = (stack)->next;
	}
	return (median);
}

// void	ft_recursion(t_list **stack_a, t_list **stack_b, int median)
// {
// 	while ((*stack_a))
// 	{
// 		if ((*stack_a) <= median)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 	}
// }

void	ft_quick_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		median;
	int		size_a;
	int		size_b;
	int		flag;

	flag = 0;
	while (ft_lstsize(*stack_a) > 0)
	{
		size_a = ft_lstsize(*stack_a);
		//printf("size: %i\n", size_a);
		median = ft_get_median(*stack_a);
		//printf("median: %i\n", median);
		if (ft_lstsize(*stack_a) == 1)
		{
			pb(stack_a, stack_b);
			break ;
		}
		else if (ft_lstsize(*stack_a) == 2)
		{
			if ((*stack_a)->content > (*stack_a)->next->content)
			{
				sa(*stack_a);
				pb(stack_a, stack_b);
			}
			else
			{
				pb(stack_a, stack_b);
				pb(stack_a, stack_b);
			}
			break ;
		}
		while (size_a)
		{
			//printf("content outside: %i\n", (*stack_a)->content);
			if (((*stack_a)->content) < median)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			size_a--;
		}
		flag++;
		// if (flag > 1)
		// 	break ;
	}
	flag = 0;
	//printf("END\n");
	while (ft_lstsize(*stack_b) > 0)
	{
		size_b = ft_lstsize(*stack_b);
		//printf("size: %i\n", size_b);
		median = ft_get_median(*stack_b);
		//printf("median: %i\n", median);
		if (ft_lstsize(*stack_b) == 1)
		{
			pa(stack_a, stack_b);
			break ;
		}
		else if (ft_lstsize(*stack_b) == 2)
		{
			if ((*stack_b)->content > (*stack_b)->next->content)
			{
				pa(stack_a, stack_b);
				pa(stack_a, stack_b);
			}
			else
			{
				sb(*stack_b);
				pa(stack_a, stack_b);
			}
			break ;
		}
		while (size_b)
		{
			//printf("content: %i\n", (*stack_b)->content);
			if (((*stack_b)->content) > median)
				pa(stack_a, stack_b);
			else
				rb(stack_b);
			size_b--;
		}
		flag++;
		// if (flag > 4)
		// 	break 
	}
}
