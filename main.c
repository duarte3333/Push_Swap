/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/24 17:18:59 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_variables(t_stack *stacks, t_list **stack_a, t_list **stack_b)
{
	stacks->current_size_a = ft_lstsize(*stack_a);
	stacks->current_size_b = ft_lstsize(*stack_b);
}

void	ft_print_moves(int moves[], int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (moves[j] == 1)
			printf("sa\n");
		else if (moves[j] == 2)
			printf("sb\n");
		else if (moves[j] == 4)
			printf("pa\n");
		else if (moves[j] == 5)
			printf("pb\n");
		else if (moves[j] == 6)
			printf("ra\n");
		else if (moves[j] == 7)
			printf("rb\n");
		else if (moves[j] == 9)
			printf("rra\n");
		else if (moves[j] == 10)
			printf("rrb\n");
		j++;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	static	t_stack stacks;	
	int	moves[10000];
	int i;

	i = 0;
	stack_b = NULL;
	if (ac == 1)
	{
		printf("Not enough arguments\n");
		return (0);
	}
	stack_a = ft_list_loading(av);
	if (stack_a == NULL)
		printf("Error\n");
	else
	{
		if (ac == 4)
		{
			i = ft_sort_three(&stack_a, moves, i);
		}
		else if (ac == 6)
			i = ft_sort_five(&stack_a, &stack_b, moves, i);
		else
			i = ft_cost_algorithm(&stack_a, &stack_b, moves, i);
	}
	ft_print_moves(moves, i);

	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}
