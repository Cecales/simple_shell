#include  "main.h" 

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
	temp[0] = malloc(sizeof(char) * (count + 1));
	if (temp[0] == NULL)
	{
		free(temp[0]);
		return;
	}
	for (; a < count; a++)
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

/**
 * _cd - function to imite the cd linux function
 * @arg: str
 */

void _cd(char *arg)
{
	int cd = 0;

	if (!arg)
		obt_dir();
	else
	{
		cd = chdir(arg);
		if (cd == 0)
			printf("ok\n");
		else
		{
			error(arg, _strlen(arg), 0);
		}
	}
}
