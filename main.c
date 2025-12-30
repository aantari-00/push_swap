/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 02:26:03 by aantari           #+#    #+#             */
/*   Updated: 2025/12/28 09:20:09 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_split(char *arg, t_stack **a)
{
	char	**str;
	int		j;

	str = ft_split(arg, ' ');
	if (!str || !str[0])
	{
		if (str)
			ft_free_arr(str);
		return (1);
	}
	j = 0;
	while (str[j])
	{
		if (runfunc(str[j], a) == 1)
			return (ft_free_arr(str), 1);
		j++;
	}
	ft_free_arr(str);
	return (0);
}

int	handle_arg(char *arg, t_stack **a)
{
	if (arg[0] == '\0' || just_space(arg))
		return (print_error_msg(), 1);
	if (check_space(arg))
	{
		if (handle_split(arg, a) == 1)
			return (print_error_msg(), 1);
	}
	else
	{
		if (runfunc(arg, a) == 1)
			return (print_error_msg(), 1);
	}
	return (0);
}

static void	help_main(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (!chech_is_sort(a))
	{
		if (size < 6)
			small_sort(&a, &b);
		else
		{
			push_chunks(&a, &b);
			push_to_stack_a(&a, &b);
		}
		free_stack(&a);
		free_stack(&b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (handle_arg(av[i], &a) == 1)
		{
			free_stack(&a);
			exit(1);
		}
		i++;
	}
	help_main(a, b);
}
