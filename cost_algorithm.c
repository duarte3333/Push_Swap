/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:15:13 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 13:54:30 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Coloca o melhor amigo e o numero em questao no topo da sua depois 
//manda o numero do A para o B de modo a ficarem juntos
int	ft_make_the_moves(t_stack *budd, t_list **stack_a, \
t_list **stack_b, char moves[])
{
	budd->i = ft_put_top_a(stack_a, budd->final_bf, moves, budd->i);
	budd->i = ft_put_top_b(stack_b, budd->final_nb, moves, budd->i);
	budd->i = pa(stack_a, stack_b, moves, budd->i);
	return (budd->i);
}

//Esta funcao ira definir algumas variaveis que irao ser utilizadas 
//na funcao cost buddy
void	ft_set_buddy(t_stack *cost_buddy, t_list **stack_a, \
	t_list **stack_b, int i)
{
	cost_buddy->i = i;
	cost_buddy->temp = *stack_b;
	cost_buddy->best = INT_MAX;
	cost_buddy->index_nb = 0;
	cost_buddy->size_b = ft_lstsize(*stack_b);
	cost_buddy->size_a = ft_lstsize(*stack_a);
}

//Calcula todas as possibilidades de melhor amigo e para um numero em A
//e escolhe aquele que custar menos levar ate ao topo
//Depois, chama a funcao acima que permite o numero do A e melhor amigo
//ficarem juntos
int	ft_get_cost_best_buddy(t_list **stack_a, t_list **stack_b, \
	char moves[], int i)
{
	t_stack	budd;

	ft_set_buddy(&budd, stack_a, stack_b, i);
	while (*stack_b)
	{
		budd.index_bf = ft_get_best_buddy(stack_a, (*stack_b)->content);
		if (budd.index_bf != -1)
		{
			budd.cost_bf = ft_calculate_cost_up(budd.size_a, budd.index_bf);
			budd.cost_nb = ft_calculate_cost_up(budd.size_b, budd.index_nb);
			if ((budd.cost_bf + budd.cost_nb) < budd.best \
				&& (budd.cost_bf + budd.cost_nb) >= 0)
			{	
				budd.final_nb = budd.index_nb;
				budd.final_bf = budd.index_bf;
				budd.best = budd.cost_nb + budd.cost_bf;
			}
		}
		(*stack_b) = (*stack_b)->next;
		budd.index_nb++;
	}
	*stack_b = budd.temp;
	i = ft_make_the_moves(&budd, stack_a, stack_b, moves);
	return (i);
}

int	ft_cost_algorithm(t_list **stack_a, t_list **stack_b, char moves[], int i)
{
	int	average;

	average = ft_get_dynamic_average(*stack_a);
	while (ft_lstsize(*stack_a) > 5)
	{
		if ((*stack_a)->content > average)
			i = ra(stack_a, moves, i);
		else
		{
			i = pb(stack_a, stack_b, moves, i);
			average = ft_get_dynamic_average(*stack_a);
		}
	}
	i = ft_sort_five(stack_a, stack_b, moves, i);
	while (ft_lstsize(*stack_b) > 0)
	{
		i = ft_get_cost_best_buddy(stack_a, stack_b, moves, i);
	}
	i = ft_rotate_until_last_is_last(stack_a, moves, i);
	return (i);
}
