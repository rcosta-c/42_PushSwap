/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:07:09 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/04 12:12:38 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_int(int ac, char **av)
{
	int	i_cmp;
	int	i;

	if (ac == 2)
		if (ft_atol(av[0]) > INT_MAX || ft_atol(av[0]) < INT_MIN)
			return (-1);
	i = 0;
	while (i < ac)
	{
		i_cmp = (i + 1);
		while (i_cmp < (ac - 1))
		{
			if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i_cmp]) > INT_MAX)
				return (-1);
			if (ft_atol(av[i]) < INT_MIN || ft_atol(av[i_cmp]) < INT_MIN)
				return (-1);
			if (ft_atol(av[i]) == ft_atol(av[i_cmp]))
				return (-1);
			i_cmp++;
		}
		i++;
	}
	return (0);
}

static int	valid_av(int ac, char **av)
{
	int	i;
	int	ii;

	i = 0;
	while (i < (ac - 1))
	{
		ii = 0;
		while (av[i][ii] != '\0')
		{
			if ((av[i][ii] == 45) && (av[i][ii + 1] == '\0'))
				return (-1);
			if (av[i][ii] == 9 || av[i][ii] == 32 || av[i][ii] == 45 || \
					(av[i][ii] >= 48 && av[i][ii] <= 57))
				ii++;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_find_error(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (valid_av(ac, av) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (valid_int(ac, av) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (1);
}
