#include <stdio.h>
#include <stdlib.h>

#include "opcode_handdler.h"
#include "alx_given_structures.h"

/**
 * push - pushes an element to the stack.
 * @stack: the stack
 * @i: the parameter
 *
 * Return: the stack
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
void pall(stack_t **stack)
{
	stack_t *head = *stack;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	*stack = head;
}

/**
 * pint - prints all the elements at the top of the stack.
 * @stack: the stack.
 * @line_number: the line number
 */
void pint(stack_t **stack, int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: the stack
 * @line_number: the current line number
 */
void pop(stack_t **stack, int line_number)
{
	stack_t *tmp_node;
	int index = 0;

	tmp_node = *stack;
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	while (index != 0)
	{
		if (tmp_node == NULL)
			exit(-1);
		tmp_node = tmp_node->next;
		index--;
	}

	if (tmp_node == *stack)
	{
		*stack = tmp_node->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
	}
	else
	{
		tmp_node->prev->next = tmp_node->next;
		if (tmp_node->next != NULL)
			tmp_node->next->prev = tmp_node->prev;
	}
	free(tmp_node);
}
