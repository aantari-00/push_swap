/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:10:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/22 09:46:14 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static void	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		print_error();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error();
		i++;
	}
}
static void	max_min_int(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		print_error();
}

void	runfunc(char *str, t_stack **a)
{
	long				nb;
	t_stack			*newnode;

	is_number(str);
	nb = ft_atoi(str);
	max_min_int(nb);
	newnode = new_node(nb);
	add_back(a, newnode);
}
