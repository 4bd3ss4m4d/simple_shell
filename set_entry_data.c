#include "simple_shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void set_command_entry_data(command_entry_t *entry)
{
        entry->pid = getpid();
        entry->is_interactive = display_prompt();
        if (entry->is_interactive)
        {
                entry->command = read_command();
        }
        else
        {
                entry->command = NULL;
        }
}

bool display_prompt(void)
{
        char *prompt_text = "$ ";
        int nbytes = _strlen(prompt_text), nbytes_written;

        /* Check if standard input is a terminal */
        if (isatty(STDIN_FILENO))
        {
                nbytes_written = write(STDOUT_FILENO, prompt_text, nbytes);
                if (nbytes_written == -1)
                {
                        perror("Error writing prompt");
                        return (false);
                }

                fflush(stdout);
                return (true);
        }

        return (false);
}

char *read_command(void)
{
        char *command = NULL;
        size_t len_command = 0;
        ssize_t nchars_command;

        /* Read command */
        nchars_command = getline(&command, &len_command, stdin);

        /* Handle the EOF (CTRL + D) */
        if (nchars_command == EOF)
        {
                free(command);
                return (NULL);
        }

        /* Remove newline character if it exists */
        if (nchars_command > 1 && command[nchars_command - 1] == '\n')
        {
                command[nchars_command - 1] = '\0';
        }

        return (command);
}