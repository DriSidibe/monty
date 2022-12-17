#ifndef __OPCODE_HANDDLER__
#define __OPCODE_HANDDLER__

#include "alx_given_structures.h"

stack_t *push(stack_t **stack, int i);
void pall(stack_t **stack);
void pint(stack_t **stack, int line_number);
void pop(stack_t **stack, int line_number);
void swap(stack_t **stack, int line_number);
void add(stack_t **stack, int line_number);

#endif
