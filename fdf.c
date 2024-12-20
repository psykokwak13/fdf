/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egatien <egatien@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:40:06 by egatien           #+#    #+#             */
/*   Updated: 2024/12/20 18:47:39 by egatien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
p_struct param_init()
{
	p_struct param;

	param.width = WIDTH;
	param.height = HEIGHT;

	return (param);
}

int	key_hook(int keycode)
{
	if (keycode == 65307)
	{
		ft_putstr_fd("Window is close gg\n",1);
		exit(0);
	}
	return (1);
}
int	closewindow()
{
	ft_putstr_fd("Window is close gg\n",1);
	exit(0);
}

int	fdf(char *filepath)
{
	p_struct param;
	param = param_init();
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, param.width, param.height, "test");
	mlx_key_hook(param.win,key_hook,&param);
	mlx_expose_hook(param.win,key_hook,&param);
	mlx_hook(param.win, 17, 0, closewindow, &param);
	mlx_loop(param.mlx);
	parsing(filepath);
	return (1);

}
int	main (int ac, char **av)
{
	if (ac == 2)
		fdf(av[1]);
	else
	closewindow();
}

