/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:41:05 by ade-temm          #+#    #+#             */
/*   Updated: 2020/06/27 09:50:05 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			init_dir(t_map *tab)
{
	tab->dist->dirx = cos(tab->angle * M_PI / 180);
	tab->dist->diry = sin(tab->angle * M_PI / 180);
	tab->planex = cos((tab->angle + 90) * M_PI / 180);
	tab->planey = sin((tab->angle + 90) * M_PI / 180);
}

void			init_image(t_map *tab)
{
	int		i;

	i = 0;
	tab->first_round = 1;
	tab->moove.speed = 0.1;
	tab->mlx.ptr = mlx_init();
	tab->mlx.win = mlx_new_window(tab->mlx.ptr, tab->doc->res_x,
	tab->doc->res_y, "Cub3d");
	tab->mlx.img = mlx_new_image(tab->mlx.ptr, tab->doc->res_x,
	tab->doc->res_y);
	tab->mlx.var = (int*)mlx_get_data_addr(tab->mlx.img, &i,
	&i, &i);
	init_dir(tab);
}

int				ft_close(void)
{
	exit(0);
	return (0);
}

int				appuyer(int keycode, t_map *tab)
{
	if (keycode == 53)
		ft_close();
	if (keycode == 257)
		tab->moove.speed = 0.3;
	if (keycode == 123)
		tab->moove.tourner_d = 1;
	else if (keycode == 124)
		tab->moove.tourner_g = 1;
	else if (keycode == 13)
		tab->moove.avancer = 1;
	else if (keycode == 1)
		tab->moove.reculer = 1;
	else if (keycode == 2)
		tab->moove.droite = 1;
	else if (keycode == 0)
		tab->moove.gauche = 1;
	return (0);
}

int				relacher(int keycode, t_map *tab)
{
	if (keycode == 257)
		tab->moove.speed = 0.1;
	if (keycode == 123)
		tab->moove.tourner_d = 0;
	else if (keycode == 124)
		tab->moove.tourner_g = 0;
	else if (keycode == 13)
		tab->moove.avancer = 0;
	else if (keycode == 1)
		tab->moove.reculer = 0;
	else if (keycode == 2)
		tab->moove.droite = 0;
	else if (keycode == 0)
		tab->moove.gauche = 0;
	return (0);
}
