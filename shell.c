#include "main.h"
/**
 * main - this is the simple shell main function
 * Return: 0 always success
 */
int main(void)
{
	ssize_t read = 0;
	size_t size = 0;
	char *buffer = NULL;
	int fun = 0, cont = 0, xflag = 0;

	while (1)
	{
		size = 0;
		buffer = NULL;

		if (isatty(0))
			write(STDIN_FILENO, "$ ", 2);
		signal(SIGINT, handle_sigint);
		read = getline(&buffer, &size, stdin);
		cont++;
		if (_read(read, &buffer) == 0)
			return (0);
		if (buffer && buffer[0] != '\n')
		{
			fun = _buff(buffer, &cont, &xflag);
			if (fun == -1)
			{
				free(buffer);
				exit(0);
			}
			if (fun == -2)
				break;
		}
		else
			free(buffer);
	}
	free(buffer);
	return (0);
}
