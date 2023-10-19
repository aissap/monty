#include "monty.h"
#include <stdio.h>

void mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    
    stack_t *temp = (*stack)->next;
    free(*stack);
    temp->prev = NULL;
    *stack = temp;
}
