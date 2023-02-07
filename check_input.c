#include "push_swap.h"

//2147483647
//-2147483648
int	ft_check_limits(char *str)
{
	int			i;
	long long	num;
	int			signal;

	signal = 1;
	i = 0;
	if (str[0] == '-')
	{
		signal *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	num = 0;
	i--;
	while (str[++i])
		num = num * 10 + str[i] - '0';
	if ((num * signal) > INT_MAX || (num * signal) < INT_MIN)
		return (0);
	return (1);
}

int	ft_check_nb(char *str_nb)
{
	int	i;

	i = -1;
	if (str_nb[0] == '-')
		i++;
	while (str_nb[++i])
	{
		if (!ft_isdigit(str_nb[i]))
			return (0);
	}
	if (!ft_check_limits(str_nb))
		return (0);
	return (1);
}

void	ft_free_stack(t_list *stack_a)
{
	t_list	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}

t_list	*ft_free_all(char **list_str, t_list *stack_a)
{
	int		i;

	i = -1;
	while (list_str[++i])
		free(list_str[i]);
	free(list_str);
	ft_free_stack(stack_a);
	return (NULL);
}

int	ft_check_double(t_list *stack_a, int a)
{
	while (stack_a)
	{
		if (stack_a->content == a)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
