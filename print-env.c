#include "main.h"

/**
 * print_environment - print the env
*/

void print_environment() {
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

/**
 * custom_setenv - set environment variables
 * @variable: param 1
 * @value: param 2
 * Return: 0
*/

int custom_setenv(const char *variable, const char *value)
{
    if (variable == NULL || value == NULL)
    {
        _fprintf(stderr, "setenv: invalid arguments\n");
        return (-1);
    }

    if (custom_setenv(variable, value) == -1)
    {
        _fprintf(stderr, "setenv: failed to set environment variable\n");
        return (-1);
    }

    return (0);
}

/**
 * custom_unsetenv - unset environment
 * @variable: param
 * Return: 0
*/
int custom_unsetenv(const char *variable)
{
    if (variable == NULL)
    {
        _fprintf(stderr, "unsetenv: invalid argument\n");
        return (-1);
    }

    if (custom_unsetenv(variable) == -1)
    {
        _fprintf(stderr, "unsetenv: failed to unset environment variable\n");
        return (-1);
    }

    return (0);
}
