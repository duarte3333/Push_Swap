/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:09:25 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/11 18:19:01 by dsa-mora         ###   ########.fr       */
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
	while (ft_lstsize(*stack_a) != 0)
	{	
		if (ft_get_int(ft_get_index(0, *stack_a), *stack_a) >= l \
			&& ft_get_int(ft_get_index(0, *stack_a), *stack_a) <= r)
		{
			pb(stack_a, stack_b);
			j++;
		}
		if (j == (size_chunk))
		{
			l += size_chunk;
			r += size_chunk;
			j = 0;
		}
		ra(stack_a);
	}
	i = ft_lstsize(*stack_b);
	while (ft_lstsize(*stack_b) > 0)
	{	
		i = ft_get_min(*stack_b);
		ft_put_top_b(stack_b, ft_get_index(i, *stack_b));
		pa(stack_a, stack_b);
	}
}
