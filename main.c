#include "push_swap.h"
#include <stdio.h>
static void    print_stack(t_stack *a)
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
    t_stack     *a;
	
    a = NULL;
	int i, j;
	i = 1;
	if (ac == 1)
		print_error();
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		j = 0;
		while (str[j])
		{
			runfunc(str[j], &a);
            j++;
		}
		i++;
	}
    print_stack(a);

}
