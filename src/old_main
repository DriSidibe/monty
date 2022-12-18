#include <stdlib.h>
#include <stdio.h>
#include "monty.h"
#include "functions.h"

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	instruction_t *instruction = NULL;
	char *instr;
	char *str;
	char *opcode;
	int line_number = 0;
	int instruction_max_size = 64;

	instruction = malloc(sizeof(instruction_t));
	if (instruction == NULL)
		return (EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (argc > 2)
	{
		fprintf(stderr, "%s", "USAGE: monty file\n");
		free(instr);
		free(instruction);
		return (EXIT_FAILURE);
	}

	if (file == NULL)
	{
		printf("Error: Can't open file %d", argv[1]);
		return (EXIT_FAILURE);
	}

	instr = malloc(sizeof(char) * instruction_max_size);
	str = malloc(sizeof(char) * instruction_max_size);
	opcode = malloc(sizeof(char) * instruction_max_size);
	if (intr == NULL || str == NULL || opcode == NULL)
	{
		printf("Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	while (fgets(instr, instruction_max_size, file) != NULL)
	{
		opcode = _get_first_word(instr, str, ' ', 0));
		if (opcode == "push")
			stack = push(&stack, line_number);
		else if (opcode == "pall")
			pall(&stack, line_number);
		line_number++;
	}

	free(instr);
	free(instruction);
	free(opcode)
	free(str);

	return (EXIT_SUCCESS);
}
