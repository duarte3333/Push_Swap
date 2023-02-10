/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:16:04 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/10 17:16:26 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	ft_put_top_a(t_list **lst, int index)
{
	int	size;
	int	i;

	printf("index: %i\n", index);
	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			ra(lst);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			rra(lst);
			i++;
		}
	}
}


int	ft_put_top_b(t_list **lst, int index)
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
			rb(lst);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			rrb(lst);
			i++;
		}
	}
}