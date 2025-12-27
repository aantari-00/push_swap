/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_phase1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 03:05:35 by aantari           #+#    #+#             */
/*   Updated: 2025/12/27 01:01:10 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *a)
{
	int		*arr;
	int		i;
	int		len;
	t_stack	*tmp;

	len = stack_size(a);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

static int	*sort_arry(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static int	init_chunk(int size)
{
	int	end;

	if (size <= 100)
		end = size / 6;
	else
		end = size / 14;
	return (end);
}
static void	push_to_b(t_stack **a, t_stack **b, int *start, int *end)
{
	pb(a, b);
	if (*b && (*b)->next && (*b)->next->data > (*b)->data)
		sb(b);
	(*start)++;
	(*end)++;
}

void	push_chunks(t_stack **a, t_stack **b)
{
	int(start), (end), (size), (*sort_arr);
	start = 0;
	size = stack_size(*a);
	sort_arr = sort_arry(stack_to_array(*a), size);
	end = init_chunk(size);
	while (*a)
	{
		if ((*a)->data <= sort_arr[start])
		{
			pb(a, b);
			rb(b);
			start++;
			end++;
		}
		else if (end < size && (*a)->data <= sort_arr[end])
			push_to_b(a, b, &start, &end);
		else
			ra(a);
	}
	free(sort_arr);
}
