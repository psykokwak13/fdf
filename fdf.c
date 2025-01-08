/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:40:06 by egatien           #+#    #+#             */
/*   Updated: 2025/01/08 13:12:11 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, p_struct *param)
{
	if (keycode == 65307)
	{
		ft_putstr_fd("Window is close gg\n",1);
		if (param->win)
			mlx_destroy_window(param->mlx,param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	return (1);
}
int	closewindow(p_struct *param)
{
	if (param->win)
		mlx_destroy_window(param->mlx,param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	ft_putstr_fd("Window is close gg\n",1);
	exit(0);
}

int	fdf(char *filepath)
{
	p_struct	param;
	m_point		*matpoint;
	char		**line;
	int			numberline;
	m_point		*secondmatpoint;
	
	numberline = countline(filepath);
	param_init(&param);
	mlx_key_hook(param.win,key_hook,&param);
	mlx_expose_hook(param.win,key_hook,&param);
	mlx_hook(param.win, 17, 0, closewindow, &param);
	line = parse(filepath);
	matpoint = ft_putfdf(line);
	free_all(line);
	while (numberline > 1)
	{
	line = parse(filepath);
	secondmatpoint = ft_putfdf(line);
	traceline(secondmatpoint, param);
	if (matpoint)
	{
		traceline(matpoint, param);
		tracevertical(matpoint, secondmatpoint, param);
		free_points(matpoint);
	}
	free_all(line);
	numberline--;
	if (numberline > 1)
	{
	line = parse(filepath);
	matpoint = ft_putfdf(line);
	traceline(matpoint, param);
	tracevertical(matpoint, secondmatpoint, param);
	free_points(matpoint);
	free_all(line);
	}
	free_points(secondmatpoint);
	numberline--;
	}
	mlx_loop(param.mlx);
	return (1);
}
int	main (int ac, char **av)
{
	if (ac == 2)
		fdf(av[1]);
	else
		exit(0);
}

