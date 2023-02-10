#include "push_swap.h"

//Retorna o content maximo da linked list
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

//Retorna o content minimo da linked list
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


//Retorna o indice do elemento para o 
//qual o lst esta a apontar
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