#include "push_swap.h"
#include <stdio.h>

int main(void)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    /* build stack a */
    push_back(&a, 3);
    push_back(&a, 1);
    push_back(&a, 2);

    printf("Before:\n");
    print_stack("a", a);
    print_stack("b", b);

    /* test rules */
    sa(&a);
    pb(&a, &b);
    ra(&a);
    rra(&a);
    pa(&a, &b);

    printf("\nAfter:\n");
    print_stack("a", a);
    print_stack("b", b);

    return (0);
}

