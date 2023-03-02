/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:57:05 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 16:53:48 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_sorted(t_list *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next != NULL)
	{
		if ((stack_a->next->content) < (stack_a->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_read_commands(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		checker_moves(stack_a, stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	if (ft_is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

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
	ft_read_commands(&stack_a, &stack_b);
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}
