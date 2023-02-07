/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:29:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/01/28 17:09:03 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>


typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *nptr);
int		ft_isdigit(int i);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *str, char charset);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_get_int(int index, t_list *lst);
int		ft_check_limits(char *str);
int		ft_check_nb(char *str_nb);
t_list	*ft_free_all(char **list_str, t_list *stack_a);
void	ft_free_stack(t_list *stack_a);
int		ft_check_double(t_list *stack_a, int a);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
int		ft_get_max(t_list *lst);
int		ft_get_min(t_list *lst);
int		ft_get_index(int nb, t_list *lst);
int		ft_lstsize(t_list *lst);
void	quicksort(t_list **stack_a, t_list **stack_b, int length);
void	quicksort_recursion(t_list **stack_a, \
	t_list **stack_b, int low, int high);
int		partition(t_list **stack_a, t_list **stack_b, \
	int low, int high);
void	swap_two(t_list **stack_a, t_list **stack_b, int index_1, int index_2);
void	ft_sort_simple(t_list **stack_a, t_list **stack_b);
int		smaller_chunk1(int size, int size_chunk, t_list **stack_a);
int		smaller_chunk2(int size, int size_chunk, t_list **stack_a);
int		ft_cost_top(t_list **lst, int index);
int		ft_put_top_optimized(int size, int size_chunk, t_list **stack_a);
int		ft_put_top_a(t_list **lst, int index);
int		ft_put_top_b(t_list **lst, int index);




#endif