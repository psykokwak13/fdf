#include "fdf.h"

int hex_to_int(const char *hex_str)
{
	int result;
	int digit;
	char c;

	result = 0;
	while (*hex_str != ',')
		hex_str++;
	hex_str = hex_str + 3;
	while (*hex_str != '\0') {
		c = *hex_str;
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			digit = c - 'a' + 10;
		else
			return (-1);
		result = result * 16 + digit;
		hex_str++;
	}

	return (result);
}

v_struct	parsenbr(char *charnbr)
{
	int			i;
	v_struct	valuestruct;

	valuestruct.color = 0;
	valuestruct.z_value = 0;
	if (!charnbr)
		return (valuestruct);
	i = 0;
	while (charnbr[i] != '\0')
	{
		if (charnbr[i] == ',')
			valuestruct.color = hex_to_int(charnbr);
		i++;
	}
	valuestruct.z_value = ft_atoi(charnbr) * 10;
	return (valuestruct);
}
char	**parse (char *file_path, p_struct *param, int *fd)
{
	char	**number;
	char *datafile;

	if (*fd == 42)
		*fd = open(file_path, O_RDONLY);
	if (*fd == -1)
		{
			close(*fd);
			closewindow(param);
		}
	datafile = get_next_line(*fd);
	number = NULL;
	if (datafile)
	{
	number = ft_split(datafile,' ');
	free(datafile);
	}
	return (number);
}

int ft_lstsizempoint(m_point *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
