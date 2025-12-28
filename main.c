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

// void	print_stack(t_stack *b)
// {
// 	t_stack	*tmp;

// 	tmp = b;
// 	while (tmp)
// 	{
// 		printf("%d -> ", tmp->data);
// 		tmp = tmp->next;
// 	}
// 	printf("NULL\n");
// }

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

static void	help_main(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (!chech_is_sort(a))
	{
		if (size < 6)
			small_sort(&a, &b);
		else if (size > 6)
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
		handle_arg(av[i], &a);
		i++;
	}
	help_main(a, b);
}
