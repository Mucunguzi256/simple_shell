#include "main.h"

/**
 * parser_command - gets command
 * @command: command inputed
 * Return: token
*/
char **parse_command(char *command)
{
    char *token;
    char **tokens = malloc(MAX_COMMAND_LENGTH * sizeof(char *));
    int token_count = 0;
    
    token = strtok(command, " ");

    while (token != NULL)
    {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    tokens[token_count] = NULL;

    return (tokens);
}

/**
 * custom_getline  - get text line
 * Return: line
*/
char *custom_getline() 
{
    static char buffer[MAX_COMMAND_LENGTH];
    static int buffer_index = 0;
    static int buffer_size = 0;
    int line_index = 0;
    char *line;

    if (buffer_index >= buffer_size)
    {
        // Buffer is empty, read new input
        buffer_size = read(STDIN_FILENO, buffer, MAX_COMMAND_LENGTH);
        buffer_index = 0;

        if (buffer_size <= 0) 
	{
            // Error or end of file
            return NULL;
        }
    }

    line = malloc(MAX_COMMAND_LENGTH * sizeof(char));
    

    while (buffer_index < buffer_size && buffer[buffer_index] != '\n')
    {
        line[line_index++] = buffer[buffer_index++];
    }

    line[line_index] = '\0';
    buffer_index++;

    return (line);
}
