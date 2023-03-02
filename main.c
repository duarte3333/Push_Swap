/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/01 19:11:15 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	possible_sorts(t_list *stack_a, t_list *stack_b, char moves[], int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
		;
	else if (ac == 3)
	{
		if ((stack_a)->content > (stack_a)->next->content)
			i = sa(stack_a, moves, i);
	}
	else if (ac == 4)
		i = ft_sort_three(&stack_a, moves, i);
	else if (ac == 5)
		i = ft_sort_four(&stack_a, &stack_b, moves, i);
	else if (ac == 6)
		i = ft_sort_five(&stack_a, &stack_b, moves, i);
	else
		i = ft_cost_algorithm(&stack_a, &stack_b, moves, i);
	ft_print_moves(moves, i);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	moves[999999];

	stack_b = NULL;
	if (empty_file(av[1]))
		return (0);
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	stack_a = ft_list_loading(av);
	if (stack_a == NULL)
		write(2, "Error\n", 6);
	else
		possible_sorts(stack_a, stack_b, moves, ac);
}
