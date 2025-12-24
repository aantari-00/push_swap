/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:10:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/24 00:16:06 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(t_stack **a)
{
	if (a)
		free_stack(a);
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

static void	is_number(char *str, t_stack **a)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		print_error(a);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error(a);
		i++;
	}
}
static void	max_min_int(long nbr , t_stack **a)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		print_error(a);
}

void	runfunc(char *str, t_stack **a)
{
	long				nb;
	t_stack			*newnode;
	
	if (!str || str[0] == '\0')
	print_error(a);
	is_number(str,a);
	nb = ft_atoi(str);
	max_min_int(nb,a);
	check_duplicate(*a, (int)nb);
	newnode = new_node(nb);
	add_back(a, newnode);
}
