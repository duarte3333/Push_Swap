/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:08:06 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 16:20:23 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	checker_moves(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		ft_swap(*stack_a);
	else if (ft_strcmp(move, "sb\n") == 0)
		ft_swap(*stack_b);
	else if (ft_strcmp(move, "ra\n") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(move, "rb\n") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(move, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(move, "rra\n") == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strcmp(move, "pa\n") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(move, "pb\n") == 0)
		ft_push(stack_b, stack_a);
	else
		write(2, "Error\n", 6);
}
