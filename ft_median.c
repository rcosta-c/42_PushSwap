/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:18:38 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/08 09:17:29 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_search_median(t_elem *stack, int num);

int	ft_search_pivot(t_elem *stack)
{
	int	start;
	int	end;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	while (start <= end)
	{
		if (ft_search_median(stack, stack[start].nbr))
			return (stack[start].nbr);
		start++;
	}
	return (-1);
}

static int	ft_search_median(t_elem *stack, int nbr)
{
	int	start;
	int	end;
	int	max;
	int	min;
	int	diff;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	min = 0;
	max = 0;
	while (start <= end)
	{
		if (stack[start].nbr > nbr)
			max++;
		else if (stack[start].nbr < nbr)
			min++;
		start++;
	}
	diff = (max - min);
	if ((diff >= -1) && (diff <= 1))
		return (1);
	return (0);
}

t_elem	ft_min_above_limit(t_elem *stack, int limit)
{
	int	start;
	int	end;
	int	min_index;

	start = ft_stack_start(stack);
	end = ft_stack_end(stack);
	min_index = -1;
	while (start <= end)
	{
		if ((stack[start].nbr > limit)
			&& ((min_index == -1) || (stack[start].nbr < stack[min_index].nbr)))
			min_index = stack[start].index;
		start++;
	}
	if (min_index == -1)
		return (ft_stack_min(stack));
	return (stack[min_index]);
}
