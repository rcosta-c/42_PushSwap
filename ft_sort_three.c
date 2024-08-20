/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:21:15 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/08 09:06:07 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_elem *stack)
{
	int	start;
	int	end;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	if ((ft_stack_min(stack).index == start) \
		&& (ft_stack_max(stack, -1).index == end))
		return ;
	if ((ft_stack_min(stack).index == start) \
		&& (ft_stack_max(stack, -1).index == (end - 1)))
	{
		ft_swap_elem(stack, "sa\n");
		ft_rotate(stack, "ra\n");
	}
	if (ft_stack_max(stack, -1).index == start)
		ft_rotate(stack, "ra\n");
	if (stack[start].nbr > stack[(start + 1)].nbr)
		ft_swap_elem(stack, "sa\n");
	if (ft_stack_min(stack).index == end)
		ft_rev_rotate(stack, "rra\n");
}
