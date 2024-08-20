/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:28:05 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/04 12:30:57 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_start(t_elem *stack);
int		ft_stack_end(t_elem *stack);
t_elem	ft_stack_min(t_elem *stack);
t_elem	ft_stack_max(t_elem *stack, int limit);

int	ft_is_sorted(t_elem *stack)
{
	int	i;

	if (!stack)
		return (-1);
	i = 0;
	while (stack[(i + 1)].index != -1)
	{
		if (stack[i].nbr > stack[(i + 1)].nbr)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_stack_start(t_elem *stack)
{
	int	start;

	if (!stack)
		return (-1);
	start = 0;
	while (stack[start].set != 1)
		start++;
	if (stack[start].index == -1)
		start--;
	return (start);
}

int	ft_stack_end(t_elem *stack)
{
	int	end;

	if (!stack)
		return (-1);
	end = 0;
	while (stack[end].index != -1)
		end++;
	end--;
	return (end);
}

t_elem	ft_stack_min(t_elem *stack)
{
	int	start;
	int	end;
	int	min_index;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	min_index = stack[start].index;
	while (start <= end)
	{
		if (stack[start].nbr < stack[min_index].nbr)
			min_index = stack[start].index;
		start++;
	}
	return (stack[min_index]);
}

t_elem	ft_stack_max(t_elem *stack, int limit)
{
	int	start;
	int	end;
	int	max_index;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	max_index = -1;
	while (start <= end)
	{
		if ((max_index == -1) || (((stack[start].nbr > stack[max_index].nbr) \
			|| (((limit == -1) || (stack[start].nbr < limit)) \
			&& (stack[max_index].set == -1)))))
			max_index = stack[start].index;
		start++;
	}
	return (stack[max_index]);
}
