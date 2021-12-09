#include "main.h"
/**
 * _read - read
 * @rea: read
 * @buffer: buffer
 * Return: 0 always success
 */
int _read(int rea, char **buffer)
{
	if (rea == -1)
	{
		if (isatty(0))
			write(STDIN_FILENO, "\n", 1);
		free(buffer[0]);
		return (0);
	}
	if (rea == 0)
	{
		if (isatty(0))
		{
			write(STDIN_FILENO, "\n", 1);
		}
	}
	return (1);
}
/**
 * _result - this is the simple shell main function
 * @ar: str
 * @buf: str
 * @xfla: ban
 * @resul: comp
 * Return: 0 always success
 */

int _result(char ***ar, char **buf, int xfla, int resul)
{
	if (resul == 0)
	{
		free(ar[0]);
		free(buf[0]);
		return (-1);
	}
	xfla = 0;
	if (resul == 2)
	{
		free(ar[0]);
		free(buf[0]);
	}
	else if (resul == 1)
	{
		print_env();
		free(ar[0]);
		free(buf[0]);
	}
	return (xfla);
}

/**
 * direc_fat - Struct to handle the built-ins commands
 * @str: str
 * @temp: str
 */
void direc_fat(char *str, char **temp)
{
	int count = 0, a = 0, count_sla = 0;

	for (; str[count]; count++)
	{
		if (str[count] == 47)
			count_sla++;
		if (count_sla == 3)
			break;
	}
	temp[0] = malloc(count * sizeof(char));
	for (; a <= count; a++)
		temp[0][a] = str[a];
}
/**
 * obt_dir - Struct to handle the built-ins commands
 */
void obt_dir(void)
{
	char ob_directorio[1024],  *direc = NULL;

	getcwd(ob_directorio, sizeof(ob_directorio));
	if (ob_directorio == NULL)
	{
		printf("error al obtener el directorio");
		return;
	}
	direc_fat(ob_directorio, &direc);
	chdir(direc);
	free(direc);
}
