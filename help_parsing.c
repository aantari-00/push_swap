/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:31:31 by aantari           #+#    #+#             */
/*   Updated: 2025/12/24 00:28:42 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_space(char *str)
{
    int i = 0;

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

