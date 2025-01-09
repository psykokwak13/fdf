#include "fdf.h"

void free_all(char **test)
{
	int		i;
	char	**str;
	
	i = 0;
	str = test;
	if (str == NULL)
		return;
	while (str[i] != NULL)
	{
	free(str[i]);
	str[i] = NULL;
	i++;
	}
	if (str)
		free(str);
}
int	matlen(char **str)
{
	int	i;
	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
int	countline(char *filepath)
{
	int count;
	int fd;
	char *line;
	count = 0;
	fd = open(filepath,O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}
m_point	*ft_putfdf(char **line)
{
	m_point	*matrix;
	int				i;
	int				x;
	int				countcols;
	static int		y;
	countcols = matlen(line);
	x = 700;
	i = 0;
	if (y >= 0) 
		y += 20;

	matrix = newpoint(x, y, parsenbr(line[i]));
	i++;
	if (!matrix)
		return (NULL);
	if (countcols <= 1)
		return (matrix);  
	while (i < countcols)
	{
		x += 20;
		m_point *new_point = newpoint(x, y, parsenbr(line[i]));
		matrix = add_point_to_list(matrix, new_point);
		i++;
	}
	return (matrix);  // retourne la liste chaînée complète
}

