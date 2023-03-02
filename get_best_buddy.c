/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_buddy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:33:21 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/01 19:35:17 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Esta funcao conta o numero de movimentos necessarios para 
//colocar um elemento no topo
int	ft_calculate_cost_up(int size, int index)
{
	int	counter;

	counter = 0;
	if (index <= (size / 2))
	{
		counter = index;
	}
	else if (index > (size / 2))
		counter = size - index;
	return (counter);
}

//Esta funcao retorna o melhor vizinho do numero a avaliar
//em questao no A
int	ft_get_best_buddy(t_list **stack_a, long long nb)
{
	long int	best_buddy;
	long int	counter;
	long int	tmp;
	t_list		*temp;

	counter = __LONG_LONG_MAX__;
	best_buddy = __LONG_LONG_MAX__;
	temp = *stack_a;
	while (*stack_a)
	{
		tmp = (*stack_a)->content - nb;
		if ((tmp < counter) && ((*stack_a)->content > nb))
		{
			counter = tmp;
			best_buddy = (*stack_a)->content;
		}
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp;
	if (best_buddy == __LONG_LONG_MAX__)
		return (-1);
	return (ft_get_index(best_buddy, *stack_a));
}
