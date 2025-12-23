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

int	main(int ac, char **av)
{
	char	**str;
	t_stack	*a;

	int i, j;
	a = NULL;
	i = 1;
	while (i < ac)
	{

		if (av[i][0] == '\0' || just_space(av[i]))
			print_error();
		
		if(check_space(av[i]))
		{
			str = ft_split(av[i], ' ');
			if (!str)
				return (0);
			j = 0;
			while (str[j])
			{
				runfunc(str[j], &a);
				j++;
			}
		}
		else
			runfunc(av[i],&a);
		i++;
	}
	print_stack(a);
}
