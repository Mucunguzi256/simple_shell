#include <shell.h>
#include <stdlib.h>
#include <stdlib.h>

/**
 * main - simple shell program entry point
 *
 * this program creates a chile process and runs getline command when compiled and executed while reading input from stdin which is a path to the executable
 *
 * Return: Always 0
 */

int main(int argc, char *argv[], char **env)
{
	char *buff = NULL, prompt = "$ ";
	size_t buff_size = 0;
	ssize_t bytes;
	pid_t wpid;
	int wstatus;
	bool from_pipe = false;
	struct stat statbuf;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) = 0)
			from_pipe = true;
		write(STDOUT_FILENO, prompt, 2);
		bytes = getline(&buff, &buff_size, stdin);
		if (bytes == -1)
		{
			perror("Error (getline)");
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (buff[bytes - 1] == '\n')
			buff[bytes - 1] = \0';

