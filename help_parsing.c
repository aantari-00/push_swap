/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:31:31 by aantari           #+#    #+#             */
/*   Updated: 2025/12/28 05:34:04 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_duplicate(t_stack *a, int value)
{
	while (a)
	{
		if (a->data == value)
			print_error(&a);
		a = a->next;
	}
}

int	chech_is_sort(t_stack *a)
{
	t_stack	*first;
	t_stack	*second;

	first = a;
	second = a->next;
	while (first->next->next)
	{
		if (first > second)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}
