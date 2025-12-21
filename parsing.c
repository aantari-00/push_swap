/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 04:10:59 by aantari           #+#    #+#             */
/*   Updated: 2025/12/21 07:04:21 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

check_args(int ac, char **av)
{
    size_t  i;
    size_t  j;
    char    **arr;
    
    i = 1;
    j = 0;
    if (ac == 1)
        return;    
    while(i < ac - 1)
    {
        while(av[i][j] != '\0')
        {
            if(av[i][j] == 32)
                *arr = ft_split(av[i],32);
                break;    
            j++;
        }
        if(av[i][j] == '\0')
            *arr = av[i];
        i++;
    }    
        
}
void    is_number(char *str)
{
    size_t  i;

    i = 0;
    if(str[i] == '+' || str[i] == '-')
        i++;
    while(!str[i])
    {
        if(str[i] <=48 && str[i]>=57)
        {
           write(1,"Error",5); 
           return;
        }
        i++;
    }
}

