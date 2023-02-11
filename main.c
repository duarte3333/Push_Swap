/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/11 18:14:49 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

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
		ft_quick_sort(&stack_a, &stack_b);
		//ft_sort_optimize(&stack_a, &stack_b);
		//ft_quick_sort(&stack_a, &stack_b);
	}
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}
