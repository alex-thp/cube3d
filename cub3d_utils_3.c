/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:18:25 by ade-temm          #+#    #+#             */
/*   Updated: 2020/03/07 08:59:49 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double			ft_no_fish_eye(t_map *tab)
{
	double	result;

	result = ((((double)tab->dist->x /
	(double)tab->dist->res_x) * 60.0) - 30.0);
	result *= M_PI / 180;
	result = cos(result);
	return (result);
}

void			ft_get_column(t_map *tab, char c)
{
	double		angle;

	angle = (double)tab->dist->x / tab->dist->res_x;
	angle = (tab->angle - 30) + angle * 60;
	if (c == 'y')
		tab->texture[tab->num].column = (double)cos((angle) * M_PI / 180)
		* (double)tab->dist->walldist + (double)tab->pos_x - (int)tab->pos_x;
	else if (c == 'x')
		tab->texture[tab->num].column = (double)sin((angle) * M_PI / 180)
		* (double)tab->dist->walldist + ((double)tab->pos_y - (int)tab->pos_y);
	tab->texture[tab->num].column = tab->texture[tab->num].column
	- (int)tab->texture[tab->num].column;
	tab->texture[tab->num].column = tab->texture[tab->num].column
	* *(tab->texture[tab->num].width);
}

int				ft_get_pixel_from_texture(t_map *tab)
{
	int		result;
	int		pos;

	pos = (int)(tab->texture[tab->num].column + tab->texture[tab->num].line
	* *(tab->texture[tab->num].width));
	if (pos < 0)
		pos = 0;
	result = tab->texture[tab->num].img[pos];
	return (result);
}

void			ft_get_line(t_map *tab, int i)
{
	double	tmp;
	double	pos;
	int		ds;
	int		de;

	ds = tab->dist->draw_start;
	de = tab->dist->draw_end;
	tmp = (double)(de - ds);
	pos = i - ds;
	tab->texture[tab->num].line = pos
	* *(tab->texture[tab->num].height) / tmp;
}

void			display_ray(t_map *tab)
{
	int		i;

	i = 0;
	while (i < tab->dist->draw_start)
	{
		tab->mlx.var[i * tab->doc->res_x + tab->doc->res_x
		- tab->dist->x] = tab->doc->plafond.total;
		i++;
	}
	while (i < tab->dist->draw_end && i < tab->doc->res_y - 1)
	{
		ft_get_line(tab, i);
		tab->mlx.var[i * tab->doc->res_x + tab->doc->res_x
		- tab->dist->x] = ft_get_pixel_from_texture(tab);
		i++;
	}
	while (i < tab->doc->res_y - 1)
	{
		tab->mlx.var[i * tab->doc->res_x + tab->doc->res_x
		- tab->dist->x] = tab->doc->sol.total;
		i++;
	}
	tab->dist->x += 1;
}
