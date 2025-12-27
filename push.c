/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:26:19 by aantari           #+#    #+#             */
/*   Updated: 2025/12/27 05:17:45 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*first;

	if (!stack1 || !*stack1)
		return (0);
	first = *stack1;
	*stack1 = first->next;
	first->next = *stack2;
	*stack2 = first;
	return (1);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}

void	pa(t_stack **b, t_stack **a)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}
