/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 07:03:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/23 14:02:50 by aantari          ###   ########.fr       */
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
	else	
	{
		last = *stack;
		while (last->next)
			last = last->next;
		if (newnode->data == last->data)
			print_error();
		last->next = newnode;
		newnode->next = NULL;
	}
}
int	stack_size(t_stack *stack)
{
	size_t	count;
	t_stack	*tmp;

	if (!stack)
		return (0);
	count = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
t_stack	*last_node(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return (NULL);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
