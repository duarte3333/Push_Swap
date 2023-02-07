#include "../push_swap.h"

//Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	ft_reverse_rotate(t_list **stack)
{
	t_list	*temp;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = ft_lstlast(*stack);
	ft_lstlast(*stack)->next = *stack;
	while ((*stack)->next != temp)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp;
}

void	rra(t_list **stack_a)
{
	ft_reverse_rotate(stack_a);
	printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	ft_reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	printf("rrr\n");
}
