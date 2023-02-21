/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:05:35 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/10 15:07:24 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;

	if ((first > second) && (second < third) && (first < third))
		sa(*stack_a);
	else if ((first > second) && (second > third) && (first > third))
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(stack_a);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(*stack_a);
		ra(stack_a);
	}	
	else if ((first < second) && (second > third) && (first > third))
		rra(stack_a);
}

void	ft_sort_three_B(t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_b)->content;
	second = (*stack_b)->next->content;
	third = (*stack_b)->next->next->content;

	if ((first > second) && (second < third) && (first < third))
		sb(*stack_b);
	else if ((first > second) && (second > third) && (first > third))
	{
		sb(*stack_b);
		rrb(stack_b);
	}
	else if ((first > second) && (second < third) && (first > third))
		rb(stack_b);
	else if ((first < second) && (second > third) && (first < third))
	{
		sb(*stack_b);
		rb(stack_b);
	}	
	else if ((first < second) && (second > third) && (first > third))
		rrb(stack_b);
}


void	ft_sort_special_three(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;

	if ((first > second) && (second < third) && (first < third))
		sa(*stack_a);
	else if ((first > second) && (second > third) && (first > third))
	{
		sa(*stack_a);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if ((first > second) && (second < third) && (first > third))
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		rra(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(*stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		rra(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}	
	else if ((first < second) && (second > third) && (first > third))
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		ra(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
}



void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	index_min;
	int	index_max;

	index_max = ft_get_index(ft_get_max(*stack_a), *stack_a);
	ft_put_top_a(stack_a, index_max);
	pb(stack_a, stack_b);
	index_min = ft_get_index(ft_get_min(*stack_a), *stack_a);
	ft_put_top_a(stack_a, index_min);
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	ft_sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = size;
	while (i)
	{
		min = ft_get_min(*stack_a);
		ft_put_top_a(stack_a, ft_get_index(min, *stack_a));
		pb(stack_a, stack_b);
		i--;
	}
	while (i < size)
	{
		pa(stack_a, stack_b);
		i++;
	}
}
