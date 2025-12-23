/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:10:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/23 14:05:10 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	
	write(1, "Error\n", 6);
	exit(1);
}
int just_space(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

static void	is_number(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		print_error();
	if (str[i] == '+' || str[i] == '-')
		i++;
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
	
	if (!str || str[0] == '\0')
	print_error();
	is_number(str);
	nb = ft_atoi(str);
	max_min_int(nb);
	check_duplicate(*a, (int)nb);
	newnode = new_node(nb);
	add_back(a, newnode);
}
