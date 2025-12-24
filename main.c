#include "push_swap.h"
#include <stdio.h>
static void	print_stack(t_stack *a)
{
	while (a)
	{
		printf("%d\n", a->data);
		a = a->next;
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
	int		i;

	a = NULL;
	if (ac == 1)
		return 0;

	i = 1;
	while (i < ac)
	{
		handle_arg(av[i], &a);
		i++;
	}
	print_stack(a);
	free_stack(&a);
}

