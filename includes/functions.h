#ifndef __FUNCTIONS__
#define __FUNCTIONS__

char *_get_first_word(char *s, char *str, char d, int j);
char *_remove_spaces(char *s, char *str);
int is_in_op_list(char *s);
char *get_operand(char *s, int op_len);
int execute_instruction(char opcode, int param);

#endif
