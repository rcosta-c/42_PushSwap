/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:16:12 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/07/08 08:59:31 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(t_elem *stack_a, t_elem *stack_b, char **input, int tofree);
static void	ft_sort(t_elem *stack_a, t_elem *stack_b, int ac);
static char	**ft_split_elems(int *ac, char **av, int *tofree);
static int	ft_count_args(char **av);

int	main(int ac, char **av)
{
	char	**input;
	t_elem	*stack_a;
	t_elem	*stack_b;
	int		tofree;
	int		error;

	++av;
	input = av;
	tofree = 0;
	if (ac == 2)
		input = ft_split_elems(&ac, input, &tofree);
	error = ft_find_error (ac, input);
	if (error <= 0)
	{
		ft_free (NULL, NULL, input, tofree);
		return (0);
	}
	stack_a = ft_stacking(ac, input, 1);
	stack_b = ft_stacking(ac, input, 0);
	if (ft_is_sorted(stack_a) == -1)
		ft_sort(stack_a, stack_b, ac);
	ft_free (stack_a, stack_b, input, tofree);
	return (0);
}

static char	**ft_split_elems(int *ac, char **av, int *tofree)
{
	char	**elem_lst;

	elem_lst = ft_split(av[0], 32);
	*ac = ft_count_args(elem_lst) + 1;
	*tofree = 1;
	return (elem_lst);
}

static int	ft_count_args(char **av)
{
	int	nbr;

	nbr = 0;
	while (av[nbr])
		nbr++;
	return (nbr);
}

static void	ft_free(t_elem *stack_a, t_elem *stack_b, char **input, int tofree)
{
	int	x;

	x = 0;
	if (tofree)
	{
		while (input[x] != 0)
		{
			free (input[x]);
			x++;
		}
		free (input[x]);
		free (input);
	}
	if (stack_a != NULL)
		free (stack_a);
	if (stack_b != NULL)
		free (stack_b);
	return ;
}

static void	ft_sort(t_elem *stack_a, t_elem *stack_b, int ac)
{
	if (ac == 3)
	{
		if (ft_is_sorted(stack_a) == -1)
			ft_swap_elem(stack_a, "sa\n");
	}
	else if (ac == 4)
		ft_sort_three(stack_a);
	else
		ft_sort_stack(stack_a, stack_b, ac);
}
