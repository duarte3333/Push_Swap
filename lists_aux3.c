#include "push_swap.h"

// int	get_smaller_index_of_chunk(int begin, int last, t_list **stack_a)
// {
// 	int	nb;
// 	int	min;

// 	min = ft_get_int(ft_get_index(begin, *stack_a), *stack_a);
// 	printf("begin: %i, min: %i\n", begin, min);
// 	while (begin < last)
// 	{
// 		printf("begin index: %i\n", begin);
// 		nb = ft_get_int(ft_get_index(begin, *stack_a), *stack_a);
// 		if (nb <= min)
// 			min = nb;
// 		begin++;
// 	}
// 	return (ft_get_index(min, *stack_a));
// }

// int	ft_put_top_optimized(int size, int size_chunk, t_list **stack_a)
// {
// 	int	hold_first;
// 	int	hold_second;
// 	int	cost_first;
// 	int	cost_second;

// 	printf("size: %i, size_chunks: %i\n", size, size_chunk);
// 	hold_first = smaller_chunk1(size, size_chunk, stack_a);
// 	hold_second = smaller_chunk2(size, size_chunk, stack_a);
// 	printf("hold_first %i, hold_second %i\n", hold_first, hold_second);
// 	cost_first = ft_cost_top(stack_a, hold_first);
// 	cost_second = ft_cost_top(stack_a, hold_second);
// 	printf("cost_first %i, cost_second %i\n", cost_first, cost_second);
// 	if (cost_first >= cost_second)
// 		ft_put_top(stack_a, hold_second);
// 	else if (cost_first < cost_second)
// 		ft_put_top(stack_a, hold_first);
// }
