/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:23:31 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/08 08:38:21 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_stacking(int ac, char **av, int option)
{
	t_elem	*stack;
	int		i;

	stack = ft_calloc(sizeof(t_elem), (ac + 1));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < (ac - 1))
	{
		if (option == 1)
		{
			stack[i].nbr = ft_atoi(av[i]);
			stack[i].set = 1;
		}
		else
		{
			stack[i].nbr = 0;
			stack[i].set = 0;
		}
		stack[i].index = i;
		i++;
	}
	stack[i].index = -1;
	return (stack);
}
