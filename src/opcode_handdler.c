#include <stdio.h>
#include <stdlib.h>

#include "../icludes/opcode_handdler.c"

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @line_number: the number to push.
 */
stack_t push(stack_t **stack, unsigned int line_number)
{
	stack_t *added_node = NULL;

	added_node = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		added_node->next = NULL;
		added_node->prev = NULL;
		added_node->n = line_number;
	}
	else
	{
		added_node->next = *stack;
		added_node->prev = NULL;
		added_node->n = line_number;
		(*stack)->prev = added_node;
	}

	return (added_node);
}

/**
 * pall - prints all the elements of the stack.
 * @stack: the stack.
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
