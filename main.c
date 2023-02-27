/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/27 21:59:42 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_optimize(int moves[], int i)
{
	if ((moves[i] == 1 && moves[i + 1] == 2) \
	|| (moves[i] == 2 && moves[i + 1] == 1) )
	{
		printf("ss\n");
		return (1);
	}
	else if ((moves[i] == 6 && moves[i + 1] == 7) \
	|| (moves[i] == 7 && moves[i + 1] == 6))
	{
		printf("rr\n");
		return (1);
	}
	else if ((moves[i] == 9 && moves[i + 1] == 10) \
	|| (moves[i] == 10 && moves[i + 1] == 9))
	{
		printf("rrr\n");
		return (1);
	}
	else 
		return (0);
}

int	ft_erase_zeros(int moves[],int final_moves[], int i)
{
	int j;
	int l;

	j = 0;
	l = 0;
	while (l < i)
	{
		while (moves[l] == 0)
			l++;
		final_moves[j] = moves[l];
		j++;
		l++;
	}
	return (l);
}

void	ft_print_moves(int moves[], int i)
{
	int j;
	int fmoves[3999999699];
	j = 0;

	ft_erase_zeros(moves, fmoves, i);
	while (j <= i)
	{
		if ((fmoves[j] == 1 && fmoves[j + 1] == 2) \
		|| (fmoves[j] == 2 && fmoves[j + 1] == 1) )
		{
			printf("ss\n");
			j++;
		}
		else if ((fmoves[j] == 6 && fmoves[j + 1] == 7) \
		|| (fmoves[j] == 7 && fmoves[j + 1] == 6))
		{
			printf("rr\n");
			j++;
		}
		else if ((fmoves[j] == 9 && fmoves[j + 1] == 10) \
		|| (fmoves[j] == 10 && fmoves[j + 1] == 9))
		{
			printf("rrr\n");
			j++;
		}
		else if (fmoves[j] == 1)
			printf("sa\n");
		else if (fmoves[j] == 2)
			printf("sb\n");
		else if (fmoves[j] == 4)
			printf("pa\n");
		else if (fmoves[j] == 5)
			printf("pb\n");
		else if (fmoves[j] == 6)
			printf("ra\n");
		else if (fmoves[j] == 7)
			printf("rb\n");
		else if (fmoves[j] == 9)
			printf("rra\n");
		else if (fmoves[j] == 10)
			printf("rrb\n");
		j++;
	}
}

int empty_file(char *str)
{
	int i;
	int j;

	i = 0; 
	j = 0;

	while (str && *str && *str == ' ')
		str++;
	if (!str)
		return (1);
	if (ft_strlen(str) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	static int	moves[3999999699];
	int i;

	i = 0;
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
	{
		write(2, "Error\n", 6);
	}
	else
	{
		if (ac == 2)
			;
		else if (ac == 3)
		{
			if (stack_a->content > stack_a->next->content)
				i = sa(stack_a, moves, i);
		}
		else if (ac == 4)
			i = ft_sort_three(&stack_a, moves, i);
		else if (ac == 5)
		{
			i = ft_sort_four(&stack_a, &stack_b, moves, i);
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
