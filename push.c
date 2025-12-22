#include "push_swap.h"

static int	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*first;

	if (!stack1 || !*stack1)
		return (0);
	first = *stack1;
	*stack1 = first->next;
	first->next = *stack2;
	*stack2 = first;
	return (1);
}
void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
void	pa(t_stack **a, t_stack **b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}