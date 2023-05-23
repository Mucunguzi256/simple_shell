#include "main.h"

/**
 * main - program entry
 * @argc: argument count
 * @argv: vector array
 * Return: 0
*/

int main(int argc, char **argv)
{
	char command[MAX_COMMAND_LENGTH];
	char **tokens;
	char *line;
	
	while (1)
	{
		_puts("$ ");
		fflush(stdout);
		line = custom_getline();
		
		if (line == NULL)
		{
			_putchar('\n');
			break;
		}
		line[custom_strcspn(line, "\n")] = '\0';
		tokens = parse_command(line);
		
		if (tokens[0] == NULL)
		{
			free(tokens);
			continue;
		}
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free(tokens);
			break;
		}
		else if (_strcmp(tokens[0], "env") == 0)
		{
			free(tokens);
		       	print_environment();
		}
		else if (_strcmp(tokens[0], "setenv") == 0)
		{
			if (tokens[1] != NULL && tokens[2] != NULL && tokens[3] == NULL)
			{
				custom_setenv(tokens[1], tokens[2]);
			}
			else
			{
				_fprintf(stderr, "setenv: invalid arguments\n");
			}
			free(tokens);
		}
        else if (_strcmp(tokens[0], "unsetenv") == 0)
        {
            if (tokens[1] != NULL && tokens[2] == NULL)
            {
                custom_unsetenv(tokens[1]);
            }
            else
            {
                _fprintf(stderr, "unsetenv: invalid argument\n");
            }
            free(tokens);
        }
        else
        {
            execute_command(tokens);
            free(tokens);
        }

        free(line);
    }

    return 0;
}
