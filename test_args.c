#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "monty.h"
#include "functions.h"

char valid_opcodes[][255] = {"push", "pall", "pint", "pop"};
int instruction_max_size = 64;

/**
 * error - print errors
 * @msg: the error
 * @param1: the parameter 1
 *
 * Return: O if all right
 */
int error(const char *msg, const char *param1)
{
	printf("%s%s\n", msg, param1);
	exit(1);
}

/**
 * verify_instruction - verify the instruction
 * @instruction: the instruction
 * @line_number: the line number
 *
 * Return: result
 */
char *verify_instruction(char *instruction, int line_number)
{
	char *str = NULL;
	char *str2 = NULL;

	str = malloc(sizeof(char) * instruction_max_size);
	str2 = malloc(sizeof(char) * instruction_max_size);
	if (str == NULL || str2 == NULL)
		error("Error: malloc failed", "");

	str = _get_first_word(instruction, str, ' ', 0);
	str = _remove_spaces(str, str2);
	if (is_in_op_list(str2) == 1)
	{
		printf("L%d: unknown instruction %s", line_number, str2);
		exit(1);
	}

	return (str2);
}

/**
 * verify_args - verify args
 * @argc: the number of parameter
 * @argv: list of paraemter
 *
 * Return: 0 if all right
 */
int verify_args(int argc, char *argv[])
{
	if (argc != 2)
		error("USAGE: monty file", "");

	if (access(argv[1], R_OK))
		error("Error: Can't open file ", argv[1]);

	return (0);
}
