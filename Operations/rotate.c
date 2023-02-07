#include "../push_swap.h"

//Shift up all elements of stack a by 1.
//The first element becomes the last one
void	ft_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = (*stack)->next;
	ft_lstlast(*stack)->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

void	ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n");
}

