#ifndef __TEST_ARGS__
#define __TEST_ARGS__

int verify_args(int argc, char *argv[]);
char *verify_instruction(char *instruction, int line_number);
int error(const char *msg, const char *param1);

#endif
