/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:39:30 by egatien           #+#    #+#             */
/*   Updated: 2025/01/08 13:02:00 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H 
# define FDF_H
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
# define WIDTH 800 // = axe x
# define HEIGHT 600// = axe y

typedef struct valuestruct // structure pour les valeurs collectés de split -> color = valeur hexidecimal apres la virgule SI IL Y EN A  
{
	int color;
	int z_value;
}v_struct;

typedef struct m_point
{
	int x;
	int y;
	v_struct colorZ;
	struct m_point *next;
}m_point;

typedef struct t_struct
{
	void *win;
	void *mlx;
	int   width;
	int	 height;
} p_struct;

void		traceline(m_point *pointmat,p_struct param);
int			matlen(char **str);
void		free_all(char **line);
char		**parse (char *file_path);
void		param_init(p_struct *param);
v_struct	parsenbr(char *charnbr);
m_point		*newpoint(int x, int y, v_struct z);
m_point		*pointSpaceInit();
void		iso(int *x, int *y, int z);
int			countline(char *filepath);
m_point 	*add_point_to_list(m_point *matrix, m_point *new_point);
m_point		*ft_putfdf(char **line);
void		free_points(m_point *matrix);
void		tracevertical(m_point *matpoint, m_point *secondmatpoint, p_struct param);
int			ft_lstsizempoint(m_point *lst);

#endif