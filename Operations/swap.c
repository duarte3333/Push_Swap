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
int	sa(t_list *stack_a, char moves[], int i)
{
	ft_swap(stack_a);
	moves[i] = '1';
	i++;
	return (i);
}

//Swap the first 2 elements at the top of stack b.
int sb(t_list *stack_b, char moves[], int i)
{
	ft_swap(stack_b);
	moves[i] = '2';
	i++;
	return (i);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}
