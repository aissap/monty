#include "monty.h"
/**
 * mod_op - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number in Monty file
 * Return: no return
*/
void mod_op(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int stack_len = 0, result;

    temp = *stack;
    while (temp)
    {
        temp = temp->next;
        stack_len++;
    }
    if (stack_len < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    if (temp->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    result = temp->next->n % temp->n;
    temp->next->n = result;
    *stack = temp->next;
    free(temp);
}
