/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:09:25 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 16:56:23 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// {{1}, {1,22}, {35}} - av
// {{1}} - list_str - list_str[0] = {1}
// {{1}, {22}} - list_str - list_str[0] = {1} - list_str[1] = {22}
int	ft_count_numbers(char **av)
{
	int		i;
	int		j;
	char	**list_str;
	int		nb;

	nb = 0;
	i = 0;
	while (av[++i])
	{
		list_str = ft_split(av[i], ' ');
		j = -1;
		while (list_str[++j])
		{
			nb++;
			free(list_str[j]);
		}
		free(list_str);
	}
	return (nb);
}


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
				return (ft_free_all(list_str, stack_a, j));
			if (!ft_check_double(stack_a, ft_atoi(list_str[j])))
				return (ft_free_all(list_str, stack_a, j));
			ft_lstadd_back(&stack_a, ft_lstnew((int)ft_atoi(list_str[j])));
			free(list_str[j]);
		}
		free(list_str);
	}
	return (stack_a);
}
