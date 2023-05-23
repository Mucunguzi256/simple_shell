#include "main.h"

/**
 * execute_command - calls fork function
 * @command: cmd parameter
 * Return: nothing
*/

void execute_command(char **command)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0)
    {
        if (execvp(command[0], command) == -1)
        {
            _fprintf(stderr, "%s: command not found\n", command[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}
