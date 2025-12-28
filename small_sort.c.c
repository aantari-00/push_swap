/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 06:11:47 by aantari           #+#    #+#             */
/*   Updated: 2025/12/28 05:34:28 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

static void	sort_three(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->data;
	y = (*a)->next->data;
	z = (*a)->next->next->data;
	if (x > y && y < z && x > z)
		ra(a);
	else if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x < y && y > z && x < z)
	{
		rra(a);
		sa(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*bigg;
	int		pos;

	bigg = find_bigg(*a);
	pos = get_position(*a, bigg);
	if (pos == 1)
		sa(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(b, a);
	ra(a);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*bigg;
	int		pos;

	bigg = find_bigg(*a);
	pos = get_position(*a, bigg);
	if (pos == 1)
		sa(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(b, a);
	ra(a);
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	if (size == 4)
		sort_four(a, b);
	if (size == 5)
		sort_five(a, b);
}
