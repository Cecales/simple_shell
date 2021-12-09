#include "main.h"
/**
 * main - this is the simple shell main function
 * Return: 0 always success
 */

int main(void)
{
	ssize_t read = 0;
	char *buffer = NULL, **array = NULL;
	size_t size = 0;
	int result, tok_size = 0, cont = 0, xflag = 0;

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
			if (buffer[_strlen(buffer) - 1] == '\n')
				buffer[_strlen(buffer) - 1] = '\0';
			tok_size = toksize(buffer);
			if (tok_size == -1)
				break;
			if (tok_size == 0)
				continue;
			array = tokenize(buffer);
			if (_strcom(array[0], "cd") == 0)
				_cd(array[1]);
			else
			{
				result = str_comp(array, tok_size);
				xflag = _result(&array, &buffer, xflag, result);
				if (result < 0)
					exit(xflag);
				xflag = path(array, cont);
			}
			free(array);
		}
	}
	return (0);
}
