/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:09:09 by aantari           #+#    #+#             */
/*   Updated: 2025/12/20 06:11:37 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	return (1);
}
void	ra(t_stack **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}
void	rb(t_stack **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) && rotate(b))
		write(1, "rr\n", 3);
}
