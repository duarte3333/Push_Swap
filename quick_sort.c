// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/10 20:22:11 by dsa-mora          #+#    #+#             */
// /*   Updated: 2023/02/11 18:19:22 by dsa-mora         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int	ft_is_sorted(t_list *stack_a)
// {
// 	while (stack_a->next != NULL)
// 	{
// 		if ((stack_a->next->content) < (stack_a->content))
// 			return (0);
// 		stack_a = stack_a->next;
// 	}
// 	return (1);
// }

// void	ft_quick_sort_a(t_list **stack_a, t_list **stack_b)
// {
// 	int		median;
// 	int		size_a;
// 	int		flag;

// 	flag = 0;
// 	while (ft_lstsize(*stack_a) > 0)
// 	{
// 		size_a = ft_lstsize(*stack_a);
// 		printf("size: %i\n", size_a);
// 		median = ft_get_median(*stack_a);
// 		printf("median: %i\n", median);
// 		if (ft_lstsize(*stack_a) == 1)
// 		{
// 			pb(stack_a, stack_b);
// 			break ;
// 		}
// 		else if (ft_lstsize(*stack_a) == 2)
// 		{
// 			if ((*stack_a)->content > (*stack_a)->next->content)
// 			{
// 				sa(*stack_a);
// 				pb(stack_a, stack_b);
// 			}
// 			else
// 			{
// 				pb(stack_a, stack_b);
// 				pb(stack_a, stack_b);
// 			}
// 			break ;
// 		}
// 		while (size_a)
// 		{
// 			printf("content: %i\n", (*stack_a)->content);
// 			if (((*stack_a)->content) < median)
// 				pb(stack_a, stack_b);
// 			else
// 				ra(stack_a);
// 			size_a--;
// 		}
// 		flag++;
// 		// if (flag > 1)
// 		// 	break ;
// 	}
// }

// void	ft_quick_sort_b(t_list **stack_a, t_list **stack_b)
// {
// 	int		median;
// 	int		size_b;
// 	int		flag;

// 	flag = 0;
// 	//printf("END\n");
// 	while (ft_lstsize(*stack_b) > 0)
// 	{
// 		size_b = ft_lstsize(*stack_b);
// 		printf("size: %i\n", size_b);
// 		median = ft_get_median(*stack_b);
// 		printf("median: %i\n", median);
// 		if (ft_lstsize(*stack_b) == 1)
// 		{
// 			pa(stack_a, stack_b);
// 			break ;
// 		}
// 		else if (ft_lstsize(*stack_b) == 2)
// 		{
// 			if ((*stack_b)->content > (*stack_b)->next->content)
// 			{
// 				pa(stack_a, stack_b);
// 				pa(stack_a, stack_b);
// 			}
// 			else
// 			{
// 				sb(*stack_b);
// 				pa(stack_a, stack_b);
// 			}
// 			break ;
// 		}
// 		while (size_b)
// 		{
// 			printf("content: %i\n", (*stack_b)->content);
// 			if (((*stack_b)->content) > median)
// 			{
// 				pa(stack_a, stack_b);
// 			}
// 			else
// 				rb(stack_b);
// 			size_b--;
// 		}
// 		printf("diff");
// 		if (ft_is_sorted(*stack_a) == 0)
// 		{
// 			printf("nao tou sorted");
// 			ft_quick_sort_a(stack_a, stack_b);
// 		}
// 		flag++;
// 		if (flag > 10)
// 		 	break ;
// 	}
// }

// void	ft_quick_sort(t_list **stack_a, t_list **stack_b)
// {
// 	ft_quick_sort_a(stack_a, stack_b);
// 	printf("END\n");
// 	ft_quick_sort_b(stack_a, stack_b);
// }
