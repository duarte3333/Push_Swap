/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:29:15 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/01 19:50:29 by dsa-mora         ###   ########.fr       */
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

typedef struct s_stack
{
	int		i;
	int		index_bf;
	int		cost_bf;
	int		cost_nb;
	int		best;
	int		final_bf;
	int		final_nb;
	int		index_nb;
	int		size_b;
	int		size_a;
	t_list	*temp;
}				t_stack;
//Checker and parsing
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
t_list	*ft_free_all(char **list_str, t_list *stack_a, int i);
void	ft_free_stack(t_list *stack_a);
int		ft_check_double(t_list *stack_a, int a);

//Moves
int		pa(t_list **stack_a, t_list **stack_b, char moves[], int i);
int		pb(t_list **stack_a, t_list **stack_b, char moves[], int i);
int		rra(t_list **stack_a, char moves[], int i);
int		rrb(t_list **stack_a, char moves[], int i);
int		ra(t_list **stack_a, char moves[], int i);
int		rb(t_list **stack_a, char moves[], int i);
int		sa(t_list *stack_a, char moves[], int i);
int		sb(t_list *stack_a, char moves[], int i);
void	ss(t_list *stack_a, t_list *stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);


//Algorithm
int		ft_get_dynamic_average(t_list *stack_a);
int		ft_calculate_cost_up(int size, int index);
int		ft_get_best_buddy(t_list **stack_a, long long nb);
int		ft_sort_three(t_list **stack_a, char moves[], int i);
int		ft_sort_four(t_list **stack_a, t_list **stack_b, char moves[], int i);
int		ft_sort_five(t_list **stack_a, t_list **stack_b, char moves[], int i);
int		ft_put_top_a(t_list **lst, int index, char moves[], int i);
int		ft_put_top_b(t_list **lst, int index, char moves[], int i);
int		ft_cost_algorithm(t_list **stack_a, t_list **stack_b, \
	char moves[], int i);

//Load list
t_list	*ft_list_loading(char **av);
void	print_list(t_list *stack_a, t_list *stack_b);
void	ft_print_moves(char moves[], int i);
int		empty_file(char *str);
int		ft_rotate_until_last_is_last(t_list **stack_a, char moves[], int i);

//Aux Lists Functions
int		ft_get_max(t_list *lst);
int		ft_get_min(t_list *lst);
int		ft_get_index(int nb, t_list *lst);
int		ft_lstsize(t_list *lst);

#endif