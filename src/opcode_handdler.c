#include <stdio.h>
#include <stdlib.h>

#include "../includes/opcode_handdler.h"
#include "../includes/alx_given_structures.h"

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @line_number: the number to push.
 */
stack_t *push(stack_t **stack, int i)
{
	stack_t *added_node = NULL;

	added_node = malloc(sizeof(stack_t));
	if (added_node == NULL)
	{
		printf("Error: malloc failed");
		exit(1);
	}
	if (*stack == NULL)
	{
		added_node->next = NULL;
		added_node->prev = NULL;
		added_node->n = i;
	}
	else
	{
		added_node->next = *stack;
		added_node->prev = NULL;
		added_node->n = i;
		(*stack)->prev = added_node;
	}
	*stack = added_node;
	return (*stack);
}

/**
 * pall - prints all the elements of the stack.
 * @stack: the stack.
 */
void *pall(stack_t **stack)
{
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
}
