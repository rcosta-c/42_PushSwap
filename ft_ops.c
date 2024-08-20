/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:23:19 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/04 12:23:23 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_elem(t_elem *stack, char *msg)
{
	int	start;
	int	temp;

	start = ft_stack_start(stack);
	temp = stack[start].nbr;
	stack[start].nbr = stack[(start + 1)].nbr;
	stack[(start + 1)].nbr = temp;
	ft_putstr_fd(msg, 1);
}

void	ft_push_elem(t_elem *stack_a, t_elem *stack_b, char *msg)
{
	int	a_index;
	int	b_index;

	a_index = 0;
	while (stack_a[a_index].set != 1)
		a_index++;
	b_index = 0;
	while ((stack_b[b_index].index != -1) && (stack_b[b_index].set != 1))
		b_index++;
	b_index--;
	stack_b[b_index].nbr = stack_a[a_index].nbr;
	stack_b[b_index].set = 1;
	stack_a[a_index].nbr = 0;
	stack_a[a_index].set = 0;
	ft_putstr_fd(msg, 1);
}
