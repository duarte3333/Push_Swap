#include "push_swap.h"

int	ft_get_nb_less(t_list *stack, int nb)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->content < nb)
			counter++;
		stack = stack->next;
	}
	return (counter);
}

int	ft_get_nb_high(t_list *stack, int nb)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		if (stack->content > nb)
			counter++;
		stack = stack->next;
	}
	return (counter);
}

int	ft_get_median(t_list *stack)
{
	int		nb_small;
	int		nb_high;
	int		median;
	int		size;
	t_list	*temp;

	median = 0;
	size = ft_lstsize(stack);
	if (stack)
		temp = stack;
	while (stack)
	{
		//printf("content: %i\n", (stack)->content);
		nb_small = ft_get_nb_less(temp, ((stack)->content));
		//printf("small: %i\n", nb_small);
		nb_high = ft_get_nb_high(temp, ((stack)->content));
		//printf("high: %i\n", nb_high);
		if (nb_small == nb_high && (size % 2 == 1))
		{
			median = (stack)->content;
			break ;
		}
		else if (((nb_small) == (nb_high - 1)) && (size % 2 == 0))
		{
			median = (stack)->content;
			break ;
		}
		(stack) = (stack)->next;
	}
	return (median);
}
