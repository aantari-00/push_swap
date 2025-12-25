/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:12:00 by aantari           #+#    #+#             */
/*   Updated: 2025/12/24 02:28:21 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*beforlast;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	beforlast = *stack;
	while (beforlast->next->next)
	{
		beforlast = beforlast->next;
	}
	last = beforlast->next;
	beforlast->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate(a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (reverse_rotate(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (reverse_rotate(a) && reverse_rotate(b))
		write(1, "rrr\n", 4);
}
