/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:30:04 by ade-temm          #+#    #+#             */
/*   Updated: 2020/03/07 08:59:52 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			assign_var(t_map *tab, int x, int y)
{
	if (tab->map[x][y] == 'E')
		tab->angle = 90.1;
	if (tab->map[x][y] == 'N')
		tab->angle = 180.1;
	if (tab->map[x][y] == 'W')
		tab->angle = 270.1;
	if (tab->map[x][y] == 's')
		tab->angle = 0.1;
	tab->pos_y = y + 0.5;
	tab->pos_x = x + 0.5;
	tab->map[x][y] = '0';
	tab->check_pos += 1;
}

void			position(t_map *tab)
{
	int		x;
	int		y;

	x = 0;
	while (tab->map[x])
	{
		y = 0;
		while (tab->map[x][y])
		{
			if (ft_is_num(tab->map[x][y]) == 0 && tab->map[x][y] != ' ')
				assign_var(tab, x, y);
			y++;
		}
		x++;
	}
	if (tab->check_pos != 1)
		ft_error(10);
}

void			ft_init_ray(t_map *tab)
{
	tab->dist->res_x = tab->doc->res_x;
	tab->dist->res_y = tab->doc->res_y;
	tab->dist->camera = (2 * (double)tab->dist->x
	/ (double)tab->dist->res_x) - 1;
	tab->dist->raydirx = cos((tab->angle + (30 * tab->dist->camera))
	* (M_PI / 180));
	tab->dist->raydiry = sin((tab->angle + (30 * tab->dist->camera))
	* (M_PI / 180));
	tab->dist->deltadistx = sqrt(1 + (tab->dist->raydiry * tab->dist->raydiry)
	/ (tab->dist->raydirx * tab->dist->raydirx));
	tab->dist->deltadisty = sqrt(1 + (tab->dist->raydirx * tab->dist->raydirx)
	/ (tab->dist->raydiry * tab->dist->raydiry));
	tab->dist->hit = 0;
	tab->map_x = (int)tab->pos_x;
	tab->map_y = (int)tab->pos_y;
}

void			calc_dist_xy(t_map *tab)
{
	if (tab->dist->raydirx < 0)
	{
		tab->dist->stepx = -1;
		tab->dist->sidedistx = (tab->pos_x - tab->map_x)
		* tab->dist->deltadistx;
	}
	else
	{
		tab->dist->stepx = 1;
		tab->dist->sidedistx = (tab->map_x + 1.0 - tab->pos_x)
		* tab->dist->deltadistx;
	}
	if (tab->dist->raydiry < 0)
	{
		tab->dist->stepy = -1;
		tab->dist->sidedisty = (tab->pos_y - tab->map_y)
		* tab->dist->deltadisty;
	}
	else
	{
		tab->dist->stepy = 1;
		tab->dist->sidedisty = (tab->map_y + 1.0 - tab->pos_y)
		* tab->dist->deltadisty;
	}
}

void			wall_distance(t_map *tab)
{
	if (tab->dist->side == 0)
		tab->dist->walldist = fabs((tab->map_x - tab->pos_x +
		(1.0 - (double)tab->dist->stepx) / 2.0) / tab->dist->raydirx);
	else
		tab->dist->walldist = fabs((tab->map_y - tab->pos_y +
		(1.0 - (double)tab->dist->stepy) / 2.0) / tab->dist->raydiry);
	if (tab->dist->side == 1)
		ft_get_column(tab, 'y');
	else
		ft_get_column(tab, 'x');
	tab->dist->walldistnofish = tab->dist->walldist *
	(ft_no_fish_eye(tab));
	tab->dist->hauteur_line = (int)(tab->doc->res_y /
	tab->dist->walldistnofish);
	tab->dist->draw_start = (int)(-(tab->dist->hauteur_line
	/ 2) + tab->dist->res_y / 2);
	tab->dist->draw_end = (int)((tab->dist->hauteur_line /
	2) + tab->dist->res_y / 2);
	tab->zbuffer[tab->dist->x] = tab->dist->walldist;
}
