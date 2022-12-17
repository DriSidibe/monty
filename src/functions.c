#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/functions.h"
#include "../includes/monty.h"
#include "../includes/test_args.h"
#include "../includes/alx_given_structures.h"
#include "../includes/opcode_handdler.h"


/**
 * _get_first_word - get the first word of a string
 * @s: the string
 * @str: ...
 * @d: the delimiter
 * @j: the cursor
 *
 * Return: a pointer to the word
 */
char *_get_first_word(char *s, char *str, char d, int j)
{
	int i, k = 0;

	if (str != NULL)
	{
		for (i = j; s[i] != '\0'; i++)
		{
			str[k] = s[i];
			if (s[i] != ' ')
				if (s[i + 1] == d || s[i + 1] == '\0' || s[i + 1] == '\n')
					return (str);
			k++;
		}
	}
	else
		return (NULL);

	return (str);
}

/**
 * _remove_spaces - remove space before
 * @s: the string
 * @str: storage
 *
 * Return: the result
 */
char *_remove_spaces(char *s, char *str)
{
	int i, k = 0;

	if (str != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] != ' ')
				break;
			k++;
		}
		str = _get_first_word(s, str, ' ', k);
	}
	else
		return (NULL);
	return (str);
}

/**
 * is_in_op_list - verify if it's an op_code
 * @s: the opcode
 *
 * Return: 0 if true
 */
int is_in_op_list(char *s)
{
	int i = 0;

	if (strcmp(s, "") != 0)
	{
		for (i = 0; i < nbr_opcode; i++)
		{
			if (strcmp(valid_opcodes[i], s) == 0)
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

/**
 * get_operand - get the operands
 * @s: the instruction
 * @op_len: opcode len
 *
 * Return: the result
 */
char *get_operand(char *s, int op_len)
{
	char *res = NULL;
	char *str = NULL;
	int i, k = 0;

	res = malloc(sizeof(char) * 255);
	str = malloc(sizeof(char) * 255);
	if (res == NULL || str == NULL)
		error("Error: malloc failed", "");

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
			break;
		k++;
	}

	res = _get_first_word(s, str, ' ', k + op_len);

	return (res);
}

/**
 * execute_instruction - execute the instruction
 * @stack: monty stack
 * @opcode: the opcode
 * @param: the parameter
 *
 * Return: the stack
 */
stack_t *execute_instruction(stack_t *stack, char *opcode, int param)
{
	if (strcmp(opcode, "push") == 0)
		stack = push(&stack, param);
	else if (strcmp(opcode, "pall") == 0)
		pall(&stack);

	return (stack);
}
