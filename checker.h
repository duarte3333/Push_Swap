/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsa-mora <dsa-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:03:45 by dsa-mora          #+#    #+#             */
/*   Updated: 2023/03/02 16:19:13 by dsa-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "Get_Next_Line/get_next_line.h"

int		main(int argc, char **argv);
void	ft_push(t_list **stack_get, t_list **stack_give);
void	ft_swap(t_list *stack);
void	ft_rotate(t_list **stack);
void	ft_swap(t_list *stack);
void	ft_reverse_rotate(t_list **stack);
void	checker_moves(t_list **stack_a, t_list **stack_b, char *move);

#endif