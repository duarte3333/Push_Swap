/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:16:04 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/11 18:17:27 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_put_top_a(t_list **lst, int index, int moves[], int j)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			j = ra(lst, moves, j);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			j = rra(lst, moves, j);
			i++;
		}
	}
	return (j);
}


int	ft_put_top_b(t_list **lst, int index, int moves[], int j)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			j = rb(lst, moves, j);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			j = rrb(lst, moves, j);
			i++;
		}
	}
	return (j);
}