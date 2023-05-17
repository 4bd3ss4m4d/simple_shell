#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdbool.h>
#include <unistd.h>

typedef struct command_entry
{
        char *shell_name;
        pid_t pid;
        bool is_interactive;
        char *command;
} command_entry_t;

/* String utility functions */
int _strlen(char *s);

/* Display prompt */

/* Set Data */
void set_command_entry_data(command_entry_t *entry);
bool display_prompt(void);
char *read_command(void);

/* empty data */
void empty_command_entry(command_entry_t *entry);

/* Signal Handling */
int eof_handler(command_entry_t *entry);
void sigint_handler(int signum __attribute__((unused)));

#endif /* SIMPLE_SHELL_H */