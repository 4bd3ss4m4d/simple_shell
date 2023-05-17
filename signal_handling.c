#include "simple_shell.h"

int eof_handler(command_entry_t *entry)
{
        char new_line[] = {'\n', '\0'};
        int nbytes = _strlen(new_line);

        if (entry == NULL)
        {
                return (1);
        }
        else
        {
                if (write(STDOUT_FILENO, new_line, nbytes) == -1)
                {
                        return (-1);
                }
        }

        return (0);
}

void sigint_handler(int signum __attribute__((unused)))
{
        char new_line[] = {'\n', '\0'};
        int nbytes = _strlen(new_line);
        write(STDOUT_FILENO, new_line, nbytes);
        display_prompt();
}