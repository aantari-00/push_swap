/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:03:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/20 07:55:20 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}
void	add_back(t_stack **stack, t_stack *newnode)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = newnode;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = newnode;
	newnode->next = NULL;
}
