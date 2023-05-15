#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdbool.h>

/* String functions Prototypes */
int _strlen(char *s);

/* main functions Prototypes*/
bool display_prompt(void);
int eof_handler(char *commandptr);
void sigint_handler(int signum __attribute__((unused)));

#endif /* SIMPLE_SHELL_H */
