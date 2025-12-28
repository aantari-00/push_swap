/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:12:44 by aantari           #+#    #+#             */
/*   Updated: 2025/12/27 07:01:19 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*find_bigg(t_stack *b)
{
	t_stack	*bigg;

	bigg = b;
	while (b)
	{
		if (b->data > bigg->data)
			bigg = b;
		b = b->next;
	}
	return (bigg);
}

int	get_position(t_stack *b, t_stack *bigg)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp == bigg)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static void	get_operation(t_stack **a, t_stack **b)
{
	t_stack	*bigg;

	int (size), (pos);
	size = stack_size(*b);
	bigg = find_bigg(*b);
	pos = get_position(*b, bigg);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		pos = size - pos;
		while (pos > 0)
		{
			rrb(b);
			pos--;
		}
	}
	pa(b, a);
}

void	push_to_stack_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		get_operation(a, b);
	}
}
