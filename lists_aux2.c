#include "push_swap.h"

int	ft_get_max(t_list *lst)
{
	int	i;
	int	max;

	if (!lst)
		return (-1);
	i = 0;
	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}	
	return (max);
}

int	ft_get_min(t_list *lst)
{
	int	i;
	int	min;

	if (!lst)
		return (-1);
	i = 0;
	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}	
	return (min);
}

int	ft_get_index(int nb, t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content == nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

//Esta funcao calcula o tamanho de uma linked list
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_put_top_a(t_list **lst, int index)
{
	int	size;
	int	i;

	printf("index: %i\n", index);
	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			ra(lst);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			rra(lst);
			i++;
		}
	}
}


int	ft_put_top_b(t_list **lst, int index)
{
	int	size;
	int	i;

	size = ft_lstsize(*lst);
	if (index == -1)
		return (-1);
	else if ((size / 2) >= index)
	{
		i = index;
		while (i)
		{
			rb(lst);
			i--;
		}
	}
	else if ((size / 2) < index)
	{
		i = index;
		while (i < size)
		{
			rrb(lst);
			i++;
		}
	}
}