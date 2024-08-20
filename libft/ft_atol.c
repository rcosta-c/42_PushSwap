/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:19:44 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/04 12:14:10 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		x;
	long	reslt;
	long	signal;

	x = 0;
	signal = 1;
	reslt = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			signal = -1;
		x++;
	}
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		reslt *= 10;
		reslt += nptr[x] - 48;
		x++;
	}
	return (reslt * signal);
}
