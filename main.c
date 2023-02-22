/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/22 17:47:08 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_variables(t_stack *stacks, t_list **stack_a, t_list **stack_b)
{
	stacks->current_size_a = ft_lstsize(*stack_a);
	stacks->current_size_b = ft_lstsize(*stack_b);
}


int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	static	t_stack stacks;

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
		// if (ac == 4)
		// {
		// 	ft_sort_three(&stack_a);
		// }
		// else if (ac == 6)
		// 	ft_sort_five(&stack_a, &stack_b);
		//else
		// ft_set_variables(&stacks, &stack_a, &stack_b);
		// printf("size b %i\n", stacks.current_size_b);
		// pb(&stack_a, &stack_b);
		// printf("size b %i \n", stacks.current_size_b);
		//print_list(stack_a, stack_b);
		ft_set_variables(&stacks, &stack_a, &stack_b);
		ft_quick_sort_a(&stack_a, &stack_b, 0, &stacks);
		//ft_sort_optimize(&stack_a, &stack_b);
		//print_list(stack_a, stack_b);
		//ft_quick_sort(&stack_a, &stack_b);
	}
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}
