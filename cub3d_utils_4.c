/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:38:15 by ade-temm          #+#    #+#             */
/*   Updated: 2020/03/07 08:59:50 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				read_xpm_texture_2(t_map *tab, int num, int *size)
{
	int		i;
	int		j;

	if (!(tab->texture[num].texture_w))
		ft_error(1);
	tab->texture[num].width = &size[0];
	tab->texture[num].height = &size[1];
	tab->texture[num].img =
	(int*)mlx_get_data_addr(tab->texture[num].texture_w,
	&j, &i, &j);
	tab->texture[num].size = j;
	return (0);
}

int				read_xpm_texture(t_doc *doc, t_map *tab, int num)
{
	int		*size;
	int		i;
	char	*str;

	i = 4;
	if (!(size = malloc(sizeof(int) * 2)))
		return (0);
	size[0] = 0;
	size[1] = 0;
	if (num == 0)
		str = doc->no;
	if (num == 1)
		str = doc->so;
	if (num == 2)
		str = doc->we;
	if (num == 3)
		str = doc->ea;
	if (num == 4)
		str = doc->s;
	tab->texture[num].texture_w =
	mlx_xpm_file_to_image(tab->mlx.ptr, str, &size[0], &size[1]);
	return (read_xpm_texture_2(tab, num, size));
}

void			calc_dist_2(t_map *tab)
{
	if (tab->dist->side == 0 && tab->dist->stepx < 0)
		tab->num = 0;
	if (tab->dist->side == 0 && tab->dist->stepx > 0)
		tab->num = 1;
	if (tab->dist->side == 1 && tab->dist->stepy < 0)
		tab->num = 2;
	if (tab->dist->side == 1 && tab->dist->stepy > 0)
		tab->num = 3;
	wall_distance(tab);
}

void			calc_dist(t_map *tab)
{
	ft_init_ray(tab);
	calc_dist_xy(tab);
	while (tab->dist->hit == 0)
	{
		if (tab->dist->sidedistx < tab->dist->sidedisty)
		{
			tab->dist->sidedistx += tab->dist->deltadistx;
			tab->map_x += tab->dist->stepx;
			tab->dist->side = 0;
		}
		else
		{
			tab->dist->sidedisty += tab->dist->deltadisty;
			tab->map_y += tab->dist->stepy;
			tab->dist->side = 1;
		}
		if (tab->map[tab->map_x][tab->map_y] == '1')
			tab->dist->hit = 1;
	}
	calc_dist_2(tab);
}

int				check_game(t_map *tab)
{
	if (tab->moove.tourner_d == 1 || tab->moove.tourner_g == 1)
		ft_turn(tab);
	if (tab->moove.droite)
		ft_moove_r(tab);
	if (tab->moove.gauche)
		ft_moove_l(tab);
	if (tab->moove.avancer)
		ft_moove_f(tab);
	if (tab->moove.reculer)
		ft_moove_b(tab);
	tab->dist->x = 0;
	return (0);
}
