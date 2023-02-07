#include "../push_swap.h"

void	ft_swap(t_list *stack)
{
	int	temp;

	if (!(stack) || !(stack->next))
		return ;
	temp = (stack->content);
	stack->content = stack->next->content;
	stack->next->content = temp;
}

//Swap the first 2 elements at the top of stack a.
void	sa(t_list *stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

//Swap the first 2 elements at the top of stack b.
void	sb(t_list *stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}
