#include "fdf.h"

void free_all(char **test)
{
	int		i;

	i = 0;
	if (test == NULL)
		return;
	while (test[i] != NULL)
	{
	free(test[i]);
	i++;
	}
	free(test);
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
	x = 300;
	i = 0;
	if (y > 0) 
		y += 50;
	if (y == 0)
		y += 50;
	matrix = newpoint(x, y, parsenbr(line[i]));
	i++;
	x += 20;
	if (!matrix)
		return (NULL);
	if (countcols <= 1)
		return (matrix);  
	while (i < countcols)
	{
		m_point *new_point = newpoint(x, y, parsenbr(line[i]));
		matrix = add_point_to_list(matrix, new_point);
		i++;
		x += 20;
	}
	return (matrix);  // retourne la liste chaînée complète
}

