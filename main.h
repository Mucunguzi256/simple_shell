#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>

#define MAX_COMMAND_LENGTH 100

int _putchar(char c);

char **parse_command(char *command);
char *custom_getline();
void execute_command(char **command);
void print_environment(void);
int custom_setenv(const char *variable, const char *value);
int custom_unsetenv(const char *variable);
int _strcmp(char *s1, char *s2);
size_t custom_strcspn(const char *str, const char *delim);
char *findCharacter(const char *str, char character);
void _puts(char *str);
void _fprintf(FILE *stream, const char *format, ...);

#endif
