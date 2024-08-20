/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:20:40 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/04 12:21:10 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_elem *stack, char *msg)
{
	int	start;
	int	end;
	int	temp;
	int	temp2;
	int	i;

	start = 0;
	while ((stack[start].index != -1) && (stack[start].set != 1))
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = end;
	temp = stack[i].nbr;
	while (i > start)
	{
		temp2 = stack[(i - 1)].nbr;
		stack[(i - 1)].nbr = temp;
		temp = temp2;
		i--;
	}
	stack[end].nbr = temp;
	ft_putstr_fd(msg, 1);
}

void	ft_rev_rotate(t_elem *stack, char *msg)
{
	int	start;
	int	end;
	int	temp;
	int	temp2;
	int	i;

	start = 0;
	while ((stack[start].index != -1) && (stack[start].set != 1))
		start++;
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	i = start;
	temp = stack[i].nbr;
	while (i < end)
	{
		temp2 = stack[(i + 1)].nbr;
		stack[(i + 1)].nbr = temp;
		temp = temp2;
		i++;
	}
	stack[start].nbr = temp;
	ft_putstr_fd(msg, 1);
}

int	ft_rotate_top(t_elem *stack, int index, char *r, char *rr)
{
	int	op;
	int	n_op;
	int	sign;

	n_op = ft_getontop_ops(stack, index, 1);
	sign = n_op;
	if (n_op < 0)
		n_op = -n_op;
	op = n_op;
	if (n_op != 0)
	{
		while (n_op > 0)
		{
			if (sign > 0)
				ft_rotate(stack, r);
			else
				ft_rev_rotate(stack, rr);
			n_op--;
		}
	}
	if (sign > 0)
		sign = 1;
	else
		sign = -1;
	return (sign * op);
}

void	ft_rotate_both(t_elem *stack_a, t_elem *stack_b, int way)
{
	if (way == 0)
	{
		ft_rotate(stack_a, "");
		ft_rotate(stack_b, "");
		ft_putstr_fd("rr\n", 1);
	}
	else
	{
		ft_rev_rotate(stack_a, "");
		ft_rev_rotate(stack_b, "");
		ft_putstr_fd("rrr\n", 1);
	}
}
