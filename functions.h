#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include "alx_given_structures.h"

char *_get_first_word(char *s, char *str, char d, int j);
char *_remove_spaces(char *s, char *str);
int is_in_op_list(char *s);
char *get_operand(char *s, int op_len);
stack_t *exe_inst(stack_t *stack, char *opcode, char *param, int line_number);
int is_param_valid(char *param);

#endif
