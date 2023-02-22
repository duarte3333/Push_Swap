#include "push_swap.h"

int	ft_get_nb_less_part(t_list *stack, int nb, int len)
{
	int	counter;

	counter = 0;
	while (stack && len)
	{
		if (stack->content < nb)
			counter++;
		stack = stack->next;
		len--;
	}
	return (counter);
}

int	ft_get_nb_high_part(t_list *stack, int nb, int len)
{
	int	counter;

	counter = 0;
	while (stack && len)
	{
		if (stack->content > nb)
			counter++;
		stack = stack->next;
		len--;
	}
	return (counter);
}

int	ft_get_partition_median(t_list *stack, int len)
{
	int		nb_small;
	int		nb_high;
	int		median;
	int		size_len;
	t_list	*temp;

	median = 0;
	size_len = len;
	temp = stack;
	while (stack && size_len)
	{
		//printf("content: %i\n", (stack)->content);
		nb_small = ft_get_nb_less_part(temp, ((stack)->content), len);
		//printf("small: %i\n", nb_small);
		nb_high = ft_get_nb_high_part(temp, ((stack)->content), len);
		//printf("high: %i\n", nb_high);
		if (nb_small == nb_high && (len % 2 == 1))
		{
			median = (stack)->content;
			break ;
		}
		else if (((nb_small) == (nb_high - 1)) && (len % 2 == 0))
		{
			median = (stack)->content;
			break ;
		}
		size_len--;
		(stack) = (stack)->next;
	}
	return (median);
}

int	ft_get_partition_median_alternative(t_list *stack, int len)
{
	int		nb_small;
	int		nb_high;
	int		median;
	int		size_len;
	t_list	*temp;

	median = 0;
	size_len = len;
	temp = stack;
	while (stack && size_len)
	{
		//printf("content: %i\n", (stack)->content);
		nb_small = ft_get_nb_less_part(temp, ((stack)->content), len);
		//printf("small: %i\n", nb_small);
		nb_high = ft_get_nb_high_part(temp, ((stack)->content), len);
		//printf("high: %i\n", nb_high);
		if (nb_small == nb_high && (len % 2 == 1))
		{
			median = (stack)->content;
			break ;
		}
		else if (((nb_small - 1) == (nb_high)) && (len % 2 == 0))
		{
			median = (stack)->content;
			break ;
		}
		size_len--;
		(stack) = (stack)->next;
	}
	return (median);
}