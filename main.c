#include "push_swap.h"
int	main(int ac, char **av)
{
	char	**str;
	

	int i, j;
	i = 1;
	if (ac == 1)
		return (0);
	while (i < ac - 1)
	{
		str = ft_split(av[i], 32);
		j = 0;
		while (!str[j])
		{
			runfunc(str[j]);
            j++;
		}
		i++;
	}
}
