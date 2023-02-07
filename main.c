/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:21:34 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/28 17:44:27 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// {{1}, {1,22}, {35}} - av
// {{1}} - list_str - list_str[0] = {1}
// {{1}, {22}} - list_str - list_str[0] = {1} - list_str[1] = {22}

t_list	*ft_list_loading(char **av)
{
	int		i;
	int		j;
	char	**list_str;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (av[++i])
	{
		list_str = ft_split(av[i], ' ');
		j = -1;
		while (list_str[++j])
		{
			if (!ft_check_nb(list_str[j]))
				return (ft_free_all(list_str, stack_a));
			if (!ft_check_double(stack_a, ft_atoi(list_str[j])))
				return (ft_free_all(list_str, stack_a));
			ft_lstadd_back(&stack_a, ft_lstnew((int)ft_atoi(list_str[j])));
			free(list_str[j]);
		}
		free(list_str);
	}
	return (stack_a);
}

void	print_list(t_list *stack_a, t_list *stack_b)
{
	int	a;
	int	b;
	printf("\nA	||	B\n");
	printf("-----------------\n");
	while (stack_a || stack_b)
	{
		if (!stack_a)
			a = 0;
		else
		{
			a = stack_a->content;
			stack_a = stack_a->next;
		}
		if (!stack_b)
			b = 0;
		else
		{
			b = stack_b->content;
			stack_b = stack_b->next;
		}
		printf("%i	||	%i\n", a, b);
	}
}

void	ft_sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;

	if ((first > second) && (second < third) && (first < third))
		sa(*stack_a);
	else if ((first > second) && (second > third) && (first > third))
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if ((first > second) && (second < third) && (first > third))
		ra(stack_a);
	else if ((first < second) && (second > third) && (first < third))
	{
		sa(*stack_a);
		ra(stack_a);
	}	
	else if ((first < second) && (second > third) && (first > third))
		rra(stack_a);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	index_min;
	int	index_max;

	index_max = ft_get_index(ft_get_max(*stack_a), *stack_a);
	ft_put_top_a(stack_a, index_max);
	pb(stack_a, stack_b);
	index_min = ft_get_index(ft_get_min(*stack_a), *stack_a);
	ft_put_top_a(stack_a, index_min);
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	ft_sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = size;
	while (i)
	{
		min = ft_get_min(*stack_a);
		ft_put_top_a(stack_a, ft_get_index(min, *stack_a));
		pb(stack_a, stack_b);
		i--;
	}
	while (i < size)
	{
		pa(stack_a, stack_b);
		i++;
	}

}

void	ft_sort_optimize(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	size_chunk;
	int	i;
	int	l;
	int	r;
	int j;

	min = ft_get_min(*stack_a);
	size_chunk = 20;
	l = min;
	r = min + size_chunk - 1;
	j = 0;
	//printf("left: %i, right. %i\n",l, r);
	while (ft_lstsize(*stack_a) != 0)
	{	
		//printf("current nb: %i\n",ft_get_int(ft_get_index(0, *stack_a), *stack_a));
		if (ft_get_int(ft_get_index(0, *stack_a), *stack_a) >= l \
			&& ft_get_int(ft_get_index(0, *stack_a), *stack_a) <= r)
		{
			//printf("current nb: %i\n",ft_get_int(ft_get_index(i, *stack_a), *stack_a));
			//printf("go in, j: %i\n", j);
			//ft_put_top(stack_a, ft_get_index(ft_get_min(*stack_a), *stack_a));
			pb(stack_a, stack_b);
			j++;
		}
		if (j == (size_chunk))
		{
			l += size_chunk;
			r += size_chunk;
			j = 0;
			//printf("left: %i, right. %i\n",l, r);
		}
		ra(stack_a);
	}
	i = ft_lstsize(*stack_b);
	while (ft_lstsize(*stack_b) > 0)
	{	
		//printf("min: %i\n", min);
		i = ft_get_min(*stack_b);
		ft_put_top_b(stack_b, ft_get_index(i, *stack_b));
		pa(stack_a, stack_b);
	}
	//print_list(*stack_a, *stack_b);

}

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
		if (ac == 4)
		{
			ft_sort_three(&stack_a);
		}
		else if (ac == 6)
			ft_sort_five(&stack_a, &stack_b);
		else
			ft_sort_optimize(&stack_a, &stack_b);
		//quicksort(&stack_a, &stack_b, ft_lstsize(stack_a));
		//swap_two(&stack_a, &stack_b, 4, 6);
		//print_list(stack_a, stack_b);
	}
	ft_free_stack(stack_b);
	ft_free_stack(stack_a);
}

