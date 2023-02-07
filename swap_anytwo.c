#include "push_swap.h"


// void	go_index(int size, int index, t_list **stack_a)
// {
// 	int	i;
// 	int	counter;

// 	if ((size / 2) >= index)
// 	{
// 		i = index;
// 		while (i)
// 		{
// 			rra(stack_a);
// 			i--;
// 		}
// 	}
// 	else if ((size / 2) < index)
// 	{
// 		i = index;
// 		while (i < size)
// 		{
// 			ra(stack_a);
// 			i++;
// 		}
// 	}
// }

// void	swap_two(t_list **stack_a, t_list **stack_b, int index_1, int index_2)
// {
// 	int	number_above;
// 	int	size;

// 	size = ft_lstsize(*stack_a);
// 	if (index_1 < index_2)
// 	{
// 		number_above = ft_get_int(index_2, *stack_a);
// 		ft_put_top(stack_a, index_1);
// 		pb(stack_a, stack_b);
// 		ft_put_top(stack_a, ft_get_index(number_above, *stack_a));
// 		pa(stack_a, stack_b);
// 		pb(stack_a, stack_b);
// 		pb(stack_a, stack_b);
// 		print_list(*stack_a, *stack_b);
// 		sb(*stack_b);
// 		pa(stack_a, stack_b);
// 		pa(stack_a, stack_b);
// 		go_index(size, index_2, stack_a);
// 		print_list(*stack_a, *stack_b);
// 		print_list(*stack_a, *stack_b);
// 		go_index(size, index_1, stack_a);
// 		print_list(*stack_a, *stack_b);
// 	}
// 	else if (index_1 > index_2)
// 	{
// 		number_above = ft_get_int(index_1, *stack_a);
// 		ft_put_top(stack_a, index_2);
// 		pb(stack_a, stack_b);
// 		ft_put_top(stack_a, ft_get_index(number_above, *stack_a));
// 		pb(stack_a, stack_b);
// 		sb(*stack_b);
// 		print_list(*stack_a, *stack_b);
// 		pa(stack_a, stack_b);
// 		ra(stack_a);
// 		go_index(size - 1, index_1, stack_a);
// 		print_list(*stack_a, *stack_b);
// 		//pa(stack_a, stack_b);
// 		//go_index(size, index_2, stack_a);
// 		//print_list(*stack_a, *stack_b);
// 	}
// 	else if (index_1 == index_2)
// 		return ;
// }
