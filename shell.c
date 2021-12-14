#include "main.h"

/**
 * main - this is the simple shell main function
 * Return: 0 always success
 */

int main(void)
{
	ssize_t read = 0;
	char *buffer = NULL, **array;
	size_t size = 0;
	int result, tok_size = 0, len = 0, cont = 0;
	int xflag = 0;

	while (1)
	{
		size = 0;
		buffer = NULL;

		if (isatty(0))
			write(STDIN_FILENO, "$ ", 2);
		signal(SIGINT, handle_sigint);
		read = getline(&buffer, &size, stdin);
		cont++;
		if (read == -1)
		{
			if (isatty(0))
				write(STDIN_FILENO, "\n", 1);
			free(buffer);
			return (0);
		}
		if (read == 0)
		{
			if (isatty(0))
			{
				write(STDIN_FILENO, "\n", 1);
				continue;
			}
		}
		if (buffer && buffer[0] != '\n')
		{
			len = _strlen(buffer);
			if (buffer[len - 1] == '\n')
				buffer[len - 1] = '\0';

			tok_size = toksize(buffer);
			if (tok_size == -1)
				break;
			if (tok_size == 0)
				continue;
			array = tokenize(buffer);
			if (_strcom (array[0], "cd") == 0)
			{
				_cd(array[1]);
			}
			else
			{
				result = str_comp(array, tok_size);
				if (result == 0)
				{
					free(array);
					free(buffer);
					exit(xflag);
				}
				xflag = 0;
				if (result == 2)
				{
					free(array);
					free(buffer);
					continue;
				}
				else if (result == 1)
				{
					print_env();
					free(array);
					free(buffer);
					continue;
				}
				xflag = path(array, cont);
			}
			if (buffer && buffer[0] == '\n')
			{
				free(buffer);
				continue;
			}
			free(buffer);
			free(array);
		}
	}
	return (0);
}
