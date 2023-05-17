#include "simple_shell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc __attribute__((unused)), char **argv, char **env __attribute__((unused)))
{
        command_entry_t command_entry;

        /* Handle SIGINT (CTRL + C) */
        signal(SIGINT, sigint_handler);

        while (true)
        {
                /* Set the name of the shell */
                command_entry.shell_name = argv[0];

                /* Set command entry data */
                set_command_entry_data(&command_entry);

                /* If file is not a Terminal */
                if (!command_entry.is_interactive)
                {
                        empty_command_entry(&command_entry);
                        exit(EXIT_FAILURE);
                }
                /* Handle End-Of-File EOF (CTRL + D) */
                else if ((command_entry.command == NULL) && (command_entry.is_interactive))
                {
                        eof_handler(&command_entry);
                        exit(EXIT_SUCCESS);
                }

                printf("shell_name: %s\n", command_entry.shell_name);
                printf("pid: %d\n", command_entry.pid);
                printf("is_interactive: %d\n", command_entry.is_interactive);
                printf("command: %s\n", command_entry.command);
        }
}