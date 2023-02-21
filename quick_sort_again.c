/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:22:11 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/02/11 18:19:22 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_number(int nb_rotations, t_list **stack_a)
{
	int i;

	i = nb_rotations;
	while (i)
	{
		ra(stack_a);
		i--;
	}
}

void	ft_rotate_until_last_is_last(t_list **stack_a)
{
	int max;
	int index;
	int nb_rotations;

	//printf("RO TA TE\n");
	max = ft_get_max(*stack_a);
	index = ft_get_index(max, *stack_a) + 1;
	nb_rotations = ft_lstsize(*stack_a) - index;
	while (nb_rotations)
	{
		rra(stack_a);
		nb_rotations--;
	}
	//printf("max %i\n", max);
	//printf("last %i\n", ft_lstlast(*stack_a)->content);
	// printf("its me");
	// if (ft_lstlast(*stack_a)->content == max)
	// 	return ;
	// while ((*stack_a)->content != max)
	// 	ra(stack_a);
	// ra(stack_a);
	// printf("RO TA TE\n");

}


void	ft_stackb_is_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int i;

	//printf("estou sorted\n");
	i = size;
	while (i)
	{
		pa(stack_a, stack_b);
		i--;
	}
}

int ft_count_sorted(t_list *stack_a)
{
	int count;

	count = 0;
	if (!stack_a)
		return (0);
	while (stack_a->next != NULL)
	{
		if ((stack_a->next->content) - (stack_a->content) == 1)
			count++;
		stack_a = stack_a->next;
	}
	return (count);
}

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
		// if (ft_all_less_median(*stack_b) == 1)
		// 	return ;

int	ft_size_partition_to_a(t_list *stack_b, int median)
{
	int i;

	i = 0;
	while (stack_b)
	{
		if ((stack_b->content) > median)
			i++;
		stack_b = stack_b->next;
	}
	return (i);
}

void	ft_quick_sort_b(t_list **stack_a, t_list **stack_b, t_stack *stacks)
{
	int		size;
	int		size_partition;
	int		counter;
	int		nb;

	counter = 0;
	//printf("entrei no B\n");
	size = stacks->current_size_b;
	if (ft_is_sorted(*stack_b))
	{
		ft_stackb_is_sort(stack_a, stack_b, stacks->current_size_b);
		return ;
	}
	stacks->median_b = ft_get_median(*stack_b);
	//printf("median B %i\n", stacks->median_b);
	while (size)
	{
		//printf("size B: %i\n", size);
		if (stacks->current_size_b == 4 && ft_is_sorted((*stack_a)->next->next))
		{
			//printf("im here\n");
			nb = ft_get_max(*stack_b);
			//printf("oioi %i\n", nb);
			while (1)
			{
				if ((*stack_b)->content == nb)
				{
					pa(stack_a, stack_b);
					break;
				}
				else
					rb(stack_b); 
			}
			stacks->current_size_a++;
			stacks->current_size_b--;
			ft_sort_special_three(stack_a, stack_b);

		}
		if (stacks->current_size_b == 3)
		{
			//printf("tenho tres no B\n");
			ft_sort_three_B(stack_b);
			rb(stack_b);
			rb(stack_b);
			pa(stack_a, stack_b);
			rb(stack_b);
			pa(stack_a, stack_b);
			pa(stack_a, stack_b);
			//print_list(*stack_a, *stack_b);
			return ;
		}
		if (counter == 0)
			stacks->size_partition = ft_size_partition_to_a(*stack_b, stacks->median_b);
		//printf("size partition: %i\n", stacks->size_partition);
		//printf("counter: %i\n", counter);
		if (((*stack_b)->content) > (stacks->median_b))
		{
			pa(stack_a, stack_b);
			stacks->current_size_b--;
			stacks->current_size_a++;
			counter++;
		}
		else
			rb(stack_b);
		if (stacks->size_partition == counter && stacks->size_partition >= 3)
		{
			//printf("vou para o A e counter: %i\n", counter);
			ft_quick_sort_a(stack_a, stack_b, 1, stacks);
			break ;
		}
		if (stacks->size_partition == counter && stacks->size_partition == 2)
		{
			//printf("somos dois %i\n", counter);
			if ((*stack_a)->content > (*stack_a)->next->content)
				sa(*stack_a);
			break ;
		}
		size--;
		//printf("tamanho particao %i e size %i\n", stacks->size_partition, size);
		//print_list(*stack_a, *stack_b);
	}
	ft_quick_sort_b(stack_a, stack_b, stacks);
}

void	ft_quick_sort_a(t_list **stack_a, t_list **stack_b, int part, t_stack *stacks)
{
	int		median;
	int		counter;
	int		size;
	int		nb;
	int		i;

	//printf("entrei no A e currentA %i\n", stacks->current_size_a);
	size = stacks->current_size_a - stacks->total_sorted;
	stacks->median_a = ft_get_partition_median(*stack_a, size);
	//printf("median A %i\n", stacks->median_a);
	if (ft_is_sorted(*stack_a))
	{
		stacks->total_sorted = ft_count_sorted(*stack_a);
		//printf("tou sorted no A	\n");
		//printf("total sorted %i\n", stacks->total_sorted);
		return ;
	}
	//printf("size %i\n", size);
	while (size)
	{
		if ((stacks->current_size_a - stacks->total_sorted) == 4)
		{
			//printf("im here\n");
			nb = ft_get_min(*stack_a);
			//printf("oioi %i\n", nb);
			i = 0;
			while (1)
			{
				if ((*stack_a)->content == nb)
				{
					pb(stack_a, stack_b);
					break;
				}
				else
				{
					ra(stack_a); 
					i++;
				}
			}
			stacks->current_size_a--;
			stacks->current_size_b++;
			ft_rotate_until_last_is_last(stack_a);
		}
		if ((stacks->current_size_a - stacks->total_sorted) == 3)
		{
			//printf("tenho tres\n");
			//printf("len aos 3 %i\n", stacks->current_size_a);
			ft_sort_special_three(stack_a, stack_b);
			stacks->total_sorted += 3;
			//printf("total sorted %i\n", stacks->total_sorted);
			return ;
		}
		if (((*stack_a)->content) < stacks->median_a)
		{
			pb(stack_a, stack_b);
			stacks->current_size_a--;
			stacks->current_size_b++;
		}
		else
			ra(stack_a);
		size--;
		//printf("total sorted %i\n", stacks->total_sorted);
		//printf("current sizeA %i e size %i\n", stacks->current_size_a, size);
		//print_list(*stack_a, *stack_b);
	}
	//print_list(*stack_a, *stack_b);
	if (part)
	{
		//printf("goes in\n");
		ft_rotate_number(stacks->total_sorted, stack_a);
		ft_quick_sort_a(stack_a, stack_b, 1, stacks);
	}
	else 
		ft_quick_sort_a(stack_a, stack_b, 0, stacks);
	ft_quick_sort_b(stack_a, stack_b, stacks);
}

// void	ft_quick_sort_b(t_list **stack_a, t_list **stack_b, int counter, int len)
// {
// 	int		size;
// 	int 	median;

// 	printf("entrei no B");
// 	if (ft_is_sorted(*stack_b))
// 	{
// 		printf("estou sorted");
// 		size = ft_lstsize(*stack_a);
// 		while (size)
// 		{
// 			pa(stack_a, stack_b);
// 			size--;
// 		}
// 		return ;
// 	}
// 	if (ft_lstsize(*stack_b) == 5)
// 	{
// 		printf("tenho tres no B\n");
// 		ft_sort_five(stack_b, stack_a);
// 		return ;
// 	}
// 	print_list(*stack_a, *stack_b);
// 	median = ft_get_median(*stack_b);
// 	printf("median B %i\n", median);
// 	if (counter == 0)
// 		len = ft_size_partition_to_a(*stack_b, median);
// 	printf("size partition: %i\n", len);
// 	printf("counter: %i\n", counter);
// 	//if (len == counter && len >= 3)
// 	//	ft_quick_sort_a(stack_a, stack_b, len, 1, stacks);
// 	if (((*stack_b)->content) > median)
// 	{
// 		pa(stack_a, stack_b);
// 		counter++;
// 	}
// 	else
// 		rb(stack_b);
// 	ft_quick_sort_b(stack_a, stack_b, counter, len);
// }

// void	ft_quick_sort_a(t_list **stack_a, t_list **stack_b, int len, int part, t_stack *stacks)
// {
// 	int		median;
// 	int		counter;
// 	int		size;
	
// 	printf("entrei no A e len %i\n", len);
// 	size = len;
// 	if (part)
// 		stacks->median_a = ft_get_partition_median(*stack_a, len);
// 	else 
// 		stacks->median_a = ft_get_median(*stack_a);
// 	printf("median A %i\n", stacks->median_a);
// 	while (size)
// 	{
// 		if (ft_is_sorted(*stack_a))
// 			return ;
		
// 		if (stacks->current_size_a == 3)
// 		{
// 			printf("tenho tres\n");
// 			printf("len aos 3 %i\n", len);
// 			ft_sort_three(stack_a);
// 			print_list(*stack_a, *stack_b);
// 			return ;
// 		}
// 		if (((*stack_a)->content) < stacks->median_a)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 		size--;
// 	}
// 	//ft_quick_sort_b(stack_a, stack_b, 0, 0);
// }

	//median_b = ft_get_median(*stack_b);
	//if (counter >= 5)
	//{
		//printf("counter maior que 5\n");
		//i = counter;
		// while (stack_a && i)
		// {
		// 	(*stack_a) = (*stack_a)->next;
		// 	i--;
		// }
		//printf("after sort 3 i am looking at, %i\n", (*stack_a)->content);
		//ft_quick_sort_a(stack_a, stack_b);
	//}	
	//print_list(*stack_a, *stack_b);

// void quick_sort(t_list **stack_a, t_list **stack_b)
// {
// 	int		median_b;
// 	int		counter;
// 	int		i;

// 	i = 0;
// 	ft_quick_sort_a(stack_a, stack_b);	
// 	printf("oi\n");
// 	median_b = ft_get_median(*stack_b);
// 	printf("median B: %i\n", median_b);
// 	counter = ft_quick_sort_b(stack_a, stack_b, median_b);
// 	if (counter >= 3)
// 	{
// 		printf("counter maior que 3");
// 		while (i < 3)
// 		{
// 			(*stack_a) = (*stack_a)->next;
// 			i++;
// 		}
// 		printf("after sort 3 i am looking at, %i", (*stack_a)->content);
// 		ft_quick_sort_a(stack_a, stack_b);
// 	}
// }

// void	ft_quick_sort_b(t_list **stack_a, t_list **stack_b)
// {
// 	int		median;
// 	int		i;
// 	int		counter;

// 	counter = 0;
// 	i = 0;
		
// 	while (ft_lstsize(*stack_b) > 3)
// 	{
	
// 	}

// 	median = ft_get_median(*stack_b);
// 	printf("median B %i", median);
// 	if (ft_lstsize(*stack_b) == 0)
// 		return ;
// 	if (((*stack_b)->content) > median)
// 	{
// 		pa(stack_a, stack_b);
// 		counter++;
// 	}
// 	else
// 		rb(stack_b);
// 	ft_quick_sort_b(stack_a, stack_b)
// 	if (counter >= 3)
// 	{
// 		printf("counter maior que 3");
// 		while (i < 3)
// 		{
// 			(*stack_a) = (*stack_a)->next;
// 			i++;
// 		}
// 		printf("after sort 3 i am looking at, %i", (*stack_a)->content);
// 		ft_quick_sort_a(stack_a, stack_b);
// 	}
// }

// void	ft_quick_sort_a(t_list **stack_a, t_list **stack_b)
// {
// 	int		median;
	
// 	while (ft_lstsize(*stack_a) > 3)
// 	{
// 		median = ft_get_median(*stack_a);
// 		printf("median A %i", median);
// 		if (ft_is_sorted(*stack_a))
// 			break ;
// 		if (((*stack_a)->content) < median)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 	}	
// 	if (ft_lstsize(*stack_a) == 3)
// 		ft_sort_three(stack_a);
// 	if (ft_lstsize(*stack_a) == 2 && (((*stack_a)->content) > ((*stack_a)->next->content)))
// 		sa(*stack_a);
// 	ft_quick_sort_b(stack_a, stack_b);
// }


