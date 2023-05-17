#include "simple_shell.h"
#include <stdlib.h>

void empty_command_entry(command_entry_t *entry)
{
        if (entry)
        {
                entry->shell_name = NULL;
                entry->command = NULL;
                entry->pid = 0;
                entry->is_interactive = false;
        }
}
