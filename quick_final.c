#include "push_swap.h"


void	ft_rotate_until_last_is_last(t_list **stack_a)
{
	int max;
	int index;
	int nb_rotations;

	max = ft_get_max(*stack_a);
	index = ft_get_index(max, *stack_a) + 1;
	nb_rotations = ft_lstsize(*stack_a) - index;
	if (index < nb_rotations)
	{	
		while (index)
		{
			ra(stack_a);
			index--;
		}
	}
	else
	{
		while (nb_rotations)
		{
			rra(stack_a);
			nb_rotations--;
		}
	}
}


void	ft_stackb_is_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int i;

	i = size;
	while (i)
	{
		pa(stack_a, stack_b);
		i--;
	}
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

int	ft_is_ready_to_sort(t_list *stack_a)
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

int	ft_is_reverse_sorted(t_list *stack_a)
{
	while (stack_a->next != NULL)
	{
		if ((stack_a->next->content) > (stack_a->content))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

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
	//printf("entrei no B e tou a %i\n", stacks->current_size_b);
	size = stacks->current_size_b;
	if (!(*stack_b))
		return ;
	if (stacks->current_size_b == 1)
	{
		pa(stack_a, stack_b);
		return;
	}
	if (ft_is_reverse_sorted(*stack_b))
	{
		ft_stackb_is_sort(stack_a, stack_b, stacks->current_size_b);
		return ;
	}
	stacks->median_b = ft_get_median(*stack_b);
	//printf("median B %i\n", stacks->median_b);
	//print_list(*stack_a, *stack_b);
	while (size)
	{
		//printf("size B: %i\n", size);
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
		if (stacks->size_partition == counter && stacks->size_partition >= 5)
		{
			//printf("vou para o A e counter: %i\n", counter);
			ft_quick_sort_a(stack_a, stack_b, stacks);
			break ;
		}
		if (stacks->size_partition == counter && stacks->size_partition == 3)
		{
			ft_sort_special_three(stack_a, stack_b);
			break ;
		}
		if (stacks->size_partition == counter && stacks->size_partition == 2)
		{
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

void	ft_quick_sort_a(t_list **stack_a, t_list **stack_b, t_stack *stacks)
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
		stacks->total_sorted = stacks->current_size_a;
		//printf("tou sorted no A	\n");
		//printf("total sorted %i\n", stacks->total_sorted);
		return ;
	}
	//printf("size %i\n", size);
	while (size)
	{
		if ((stacks->current_size_a - stacks->total_sorted) <= 20)
		{
			//printf("tenho fice\n");
			if ((stacks->current_size_a - stacks->total_sorted) == 3)
			{
				ft_rotate_until_last_is_last(stack_a);
				ft_sort_special_three(stack_a, stack_b);
				stacks->total_sorted += 3;
				//print_list(*stack_a, *stack_b);

				break ;
			}
			else
			{
				i = (stacks->current_size_a - stacks->total_sorted);
				while (i > 5)
				{
					ft_put_top_a(stack_a, ft_get_index(ft_get_min(*stack_a), *stack_a));
					pb(stack_a, stack_b);
					stacks->current_size_b++;
					i--;
				}
				ft_sort_special_five(stack_a, stack_b);
				stacks->total_sorted += 5;
			}
			//ft_rotate_until_last_is_last(stack_a);
			//print_list(*stack_a, *stack_b);
			//printf("len aos 3 %i\n", stacks->current_size_a);
			stacks->total_sorted += 5;
			//printf("total sorted %i\n", stacks->total_sorted);
			break ;

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
	ft_rotate_until_last_is_last(stack_a);
	ft_quick_sort_a(stack_a, stack_b, stacks);
	ft_quick_sort_b(stack_a, stack_b, stacks);
}
