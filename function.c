#include "main.h"
/**
 * _buff - this is the simple shell main function
 * @buffer: str
 * @cont: str
 * @xflag: ban
 * Return: 0 always success
 */
int _buff(char *buffer, int *cont, int *xflag)
{
	char **array = NULL;
	int result = 0, tok_size = 0, buff = 0;

	if (buffer[_strlen(buffer) - 1] == '\n')
		buffer[_strlen(buffer) - 1] = '\0';
	tok_size = toksize(buffer);
	if (tok_size == -1)
		return (-2);
	tokenize(buffer, &array);
	printf("------------------tokenize-----------------------\n");
	printf("---------en tokenize esta %s----------------------\n", array[0]);
	printf("------------------tokenize-----------------------\n");

	if (_strcom(array[0], "cd") == 0)
		_cd(array[1]);
	else
	{
		result = str_comp(array, tok_size);
		printf("result//////////////////////////////////////////////////////////////////%d\n", result);
		if (result == 0)
		{
			free(array);
			return (-1);
		}
		xflag[0] = 0;
		if (result == 2)
		{
			free(array);
			free(buffer);
		}
		else if (result == 1)
		{
			print_env();
			free(array);
			free(buffer);
		}
		else
		{
			printf("------------------else-----------------------\n");
			printf("---------en esle esta %s----------------------\n", array[0]);
			printf("------------------else-----------------------\n");
			xflag[0] = path(array, cont[0], &buff);
		}
	}
	free(buffer);
	_free(array);
	printf("tamaño de array es de -------%lu\n", sizeof(array));
	free(array);
	return (0);
}

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
 * _wh - wh
 * @array: read
 * @ex_status: status
 * @cont: count
 * @c_pid: pid
 */
void _wh(char ***array, int *ex_status, int *cont, pid_t *c_pid)
{
	printf("entro a _wh-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
	if (access(array[0][0], X_OK) == 0)
		ex_status[0] = exec(c_pid[0], array[0], cont[0], array[0][0]);
	else
			error(array[0][0], cont[0], 1);
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
	temp[0] = malloc(sizeof(char) * count);
	if (temp[0] == NULL)
	{
		free(temp[0]);
		return;
	}
	for (; str[a]; a++)
		temp[0][a] = str[a];
	temp[0][a] = '\0';
}
/**
 * obt_dir - Struct to handle the built-ins commands
 */
void obt_dir(void)
{
	char ob_directorio[512],  *direc = NULL;

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
