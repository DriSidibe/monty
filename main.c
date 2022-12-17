#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "test_args.h"
#include "alx_given_structures.h"
#include "monty.h"
#include "functions.h"

int nbr_opcode = 7;

/**
 * main - the main function of the programm
 * @argc: the number of argument
 * @argv: the list of arguments
 *
 * Return: 0 if all right
 */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *instruction = NULL;
	int line_number = 1;
	char *opcode = NULL;
	char *operand = NULL;
	stack_t *stack = NULL;

	verify_args(argc, argv);

	file = fopen(argv[1], "r");
	instruction = malloc(sizeof(char) * instruction_max_size);
	if (instruction == NULL)
		error("Error: malloc failed", "");

	opcode = malloc(sizeof(char) * instruction_max_size);
	operand = malloc(sizeof(char) * instruction_max_size);
	if (opcode == NULL || operand == NULL)
		error("Error: malloc failed", "");


	while (fgets(instruction, instruction_max_size, file) != NULL)
	{
		opcode = verify_instruction(instruction, line_number);
		operand = get_operand(instruction, strlen(opcode));
		stack = exe_inst(stack, opcode, operand, line_number);
		line_number++;
	}

	return (EXIT_SUCCESS);
}
