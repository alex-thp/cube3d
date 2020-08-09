/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:52:58 by ade-temm          #+#    #+#             */
/*   Updated: 2020/03/07 09:00:02 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_get_sprite(t_map *tab)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (tab->map[i])
	{
		j = 0;
		while (tab->map[i][j])
		{
			if (tab->map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	ft_create_tab_sprite(tab, count);
}

void		ft_calc_var_sprite_2(t_map *tab)
{
	if (tab->sprite_drawstarty < 0)
		tab->sprite_drawstarty = 0;
	if (tab->sprite_drawendy >= tab->doc->res_y)
		tab->sprite_drawendy = tab->doc->res_y - 1;
	tab->sprite_width_percue = abs((int)(tab->doc->res_y / tab->transformy));
	tab->sprite_drawstartx = -(tab->sprite_width_percue / 2) + tab->screenx;
	tab->sprite_drawendx = (tab->sprite_width_percue / 2) + tab->screenx;
	if (tab->sprite_drawstartx < 0)
		tab->sprite_drawstartx = 0;
	if (tab->sprite_drawendx >= tab->doc->res_x)
		tab->sprite_drawendx = tab->doc->res_x - 1;
	tab->startx = tab->sprite_drawstartx;
}

void		ft_calc_var_sprite(t_map *tab, int i)
{
	tab->spritex = (tab->sprite[i].pos_x - tab->pos_x);
	tab->spritey = (tab->sprite[i].pos_y - tab->pos_y);
	tab->invdet = 1.0 / (tab->planex * tab->dist->diry -
	tab->dist->dirx * tab->planey);
	tab->transformx = tab->invdet * (tab->dist->diry * tab->spritex
	- tab->dist->dirx * tab->spritey);
	tab->transformy = tab->invdet * (-tab->planey *
	tab->spritex + tab->planex * tab->spritey);
	tab->vmv = (int)((float)(*tab->texture[4].width) / tab->transformy);
	tab->screenx = (int)((tab->doc->res_x / 2) *
	(1 + 2 * tab->transformx / tab->transformy));
	tab->height_sprite_percue = (abs((int)(tab->doc->res_y
	/ tab->transformy)) / 1);
	tab->sprite_drawstarty = (-tab->height_sprite_percue / 2
	+ tab->doc->res_y / 2) + tab->vmv;
	tab->sprite_drawendy = (tab->height_sprite_percue / 2
	+ tab->doc->res_y / 2) + tab->vmv;
	ft_calc_var_sprite_2(tab);
}

void		ft_do_while_sprite(t_map *tab)
{
	tab->sprite_d = (tab->starty - tab->vmv) * 256 -
	tab->doc->res_y * 128 + tab->height_sprite_percue * 128;
	tab->texy = tab->sprite_d * *tab->texture[4].height /
	tab->height_sprite_percue / 256;
	if (tab->texture[4].img[*tab->texture[4].width * tab->texy +
	tab->texx] != tab->texture[4].img[1])
		tab->mlx.var[tab->starty * tab->doc->res_x +
		tab->doc->res_x - tab->startx] =
		tab->texture[4].img[*tab->texture[4].width *
		tab->texy + tab->texx];
}

void		ft_print_sprite(t_map *tab, int i)
{
	ft_calc_var_sprite(tab, i);
	while (tab->startx < tab->sprite_drawendx)
	{
		tab->texx = (int)(256 * (tab->startx - (-tab->sprite_width_percue / 2 +
		tab->screenx)) * (((float)*tab->texture[4].width /
		tab->sprite_width_percue))) / 256;
		if (tab->startx >= 0 && tab->startx < tab->doc->res_x && tab->transformy
		< tab->zbuffer[tab->startx] && tab->transformy > 0)
		{
			tab->starty = tab->sprite_drawstarty;
			while (tab->starty < tab->sprite_drawendy)
			{
				ft_do_while_sprite(tab);
				tab->starty++;
			}
		}
		tab->startx++;
	}
}
