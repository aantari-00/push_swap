/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:26:03 by aantari           #+#    #+#             */
/*   Updated: 2025/12/26 03:57:52 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_stack(t_stack *b)
{
	while (b)
	{
		printf("%d\n", b->data);
		b = b->next;
	}
}

void	handle_arg(char *arg, t_stack **a)
{
	char	**str;
	int		j;

	if (arg[0] == '\0' || just_space(arg))
		print_error(a);
	if (check_space(arg))
	{
		str = ft_split(arg, ' ');
		if (!str || !str[0])
			print_error(a);
		j = 0;
		while (str[j])
		{
			runfunc(str[j], a);
			j++;
		}
		ft_free_arr(str);
	}
	else
		runfunc(arg, a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		handle_arg(av[i], &a);
		i++;
	}
	push_chunks(&a, &b);
	print_stack(b);
	free_stack(&a);
}
