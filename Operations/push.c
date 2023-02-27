#include "../push_swap.h"

void	ft_push(t_list **stack_get, t_list **stack_give)
{
	t_list	*temp;

	if (!(*stack_give))
		return ;
	temp = (*stack_give)->next;
	(*stack_give)->next = *stack_get;
	*stack_get = *stack_give;
	*stack_give = temp;
}


//Take the first element at the top of b and put it at the top of a
int	pa(t_list **stack_a, t_list **stack_b, int moves[], int i)
{
	ft_push(stack_a, stack_b);
	moves[i] = 4;
	i++;
	return (i);
}


//Take the first element at the top of a and put it at the top of b.
int	pb(t_list **stack_a, t_list **stack_b, int moves[], int i)
{
	ft_push(stack_b, stack_a);
	moves[i] = 5;
	i++;
	return (i);
}

