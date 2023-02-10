#include "push_swap.h"

int	ft_cost_top(t_list **lst, int index)
{
	int	size;
	int	i;
	int	cost;

	cost = 0;
	size = ft_lstsize(*lst);
	if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			cost++;
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			cost++;
			i++;
		}
	}
	return (cost);
}
