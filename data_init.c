/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:00:45 by egatien           #+#    #+#             */
/*   Updated: 2025/01/07 13:31:15 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void param_init(p_struct *param)
{

	param->width = WIDTH;
	param->height = HEIGHT;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->width, param->height, "fdf");
}
m_point *newpoint(int x, int y, v_struct z)
{
	m_point	*node;

	node = malloc(sizeof(m_point));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->colorZ.z_value = z.z_value;
	node->next = NULL;
	return (node);
}

m_point *add_point_to_list(m_point *matrix, m_point *new_point)
{
	if (!matrix)
		return (new_point);
	m_point *temp = matrix;
	while (temp->next)
		temp = temp->next;
	temp->next = new_point;
	return (matrix);
}

void free_points(m_point *matrix)
{
	m_point *temp;

	while (matrix)
	{
		temp = matrix;
		matrix = matrix->next;
		free(temp);
	}
}

