/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:39:30 by egatien           #+#    #+#             */
/*   Updated: 2024/12/20 18:47:51 by egatien          ###   ########.fr       */
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
# define WIDTH 800
# define HEIGHT 600

typedef struct m_point
{
	int x;
	int y;
	int z;
}m_point;

typedef struct t_struct
{
	void *win;
	void *mlx;
	int   width;
	int	 height;
} p_struct;


#endif