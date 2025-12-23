/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:09:01 by aantari           #+#    #+#             */
/*   Updated: 2025/12/23 04:39:11 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;
//--> func rules;
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
//--> func stack utils
t_stack				*new_node(int value);
void				add_back(t_stack **stack, t_stack *newnode);
// int					stack_size(t_stack **stack);
t_stack				*last_node(t_stack **stack);
void				free_stack(t_stack **stack);
//--> func parsing
void				runfunc(char *str, t_stack **a);
long				ft_atoi(const char *nptr);
int					print_error(void);
int					just_space(char *str);
int	check_space(char *str);
	/*split*/
	char **ft_split(char *s, char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
#endif
