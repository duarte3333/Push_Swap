/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 16:55:34 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	possible_sorts(t_list *stack_a, t_list *stack_b, char moves[], int nb)
{
	int	i;

	i = 0;
	if (nb == 1)
		;
	else if (nb == 2)
	{
		if ((stack_a)->content > (stack_a)->next->content)
			i = sa(stack_a, moves, i);
	}
	else if (nb == 3)
		i = ft_sort_three(&stack_a, moves, i);
	else if (nb == 4)
		i = ft_sort_four(&stack_a, &stack_b, moves, i);
	else if (nb == 5)
		i = ft_sort_five(&stack_a, &stack_b, moves, i);
	else
		i = ft_cost_algorithm(&stack_a, &stack_b, moves, i);
	ft_print_moves(moves, i);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_list			*stack_a;
	t_list			*stack_b;
	char			moves[999999];
	int				nb_elem;

	stack_b = NULL;
	nb_elem = 0;
	if (empty_file(av[1]))
		return (0);
	if (ac == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	nb_elem = ft_count_numbers(av);
	stack_a = ft_list_loading(av);
	printf("nb %i\n", nb_elem);
	if (stack_a == NULL)
		write(2, "Error\n", 6);
	else
		possible_sorts(stack_a, stack_b, moves, nb_elem);
}
