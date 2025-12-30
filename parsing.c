/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:10:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/24 02:28:13 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_msg(void)
{
	write(1, "Error\n", 6);
}

int	just_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	max_min_int(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}

int	runfunc(char *str, t_stack **a)
{
	long	nb;
	t_stack	*newnode;

	if (!str || str[0] == '\0')
		return (1);
	if (is_number(str) == 1)
		return (1);
	nb = ft_atoi(str);
	if (max_min_int(nb) == 1)
		return (1);
	if (check_duplicate(*a, (int)nb) == 1)
		return (1);
	newnode = new_node(nb);
	add_back(a, newnode);
	return (0);
}
