/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:02:25 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/08 11:16:57 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_elem
{
	int	nbr;
	int	index;
	int	set;
}	t_elem;

//find errors
int		ft_find_error(int ac, char **av);

//prep args to stack
t_elem	*ft_stacking(int ac, char **av, int option);

//sort and OP functions
void	ft_sort_three(t_elem *stack);
void	ft_rotate(t_elem *stack, char *msg);
void	ft_rev_rotate(t_elem *stack, char *msg);
int		ft_rotate_top(t_elem *stack, int index, char *r, char *rr);
void	ft_rotate_both(t_elem *stack_a, t_elem *stack_b, int way);
void	ft_swap_elem(t_elem *stack, char *msg);
void	ft_push_elem(t_elem *stack_a, t_elem *stack_b, char *msg);
void	ft_sort_stack(t_elem *stack_b, t_elem *stack_a, int stack_len);
t_elem	ft_min_above_limit(t_elem *stack, int limit);
int		ft_search_pivot(t_elem *stack);
int		ft_getontop_ops(t_elem *stack, int index, int sign);
void	ft_order(t_elem *stack_a, t_elem *stack_b, int index);
int		ft_check_order(t_elem *stack_a, t_elem *stack_b, int index);

//stack utils
int		ft_stack_start(t_elem *stack);
int		ft_stack_end(t_elem *stack);
t_elem	ft_stack_min(t_elem *stack);
t_elem	ft_stack_max(t_elem *stack, int limit);
int		ft_is_sorted(t_elem *stack);

#endif
