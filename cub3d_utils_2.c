/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:05:39 by ade-temm          #+#    #+#             */
/*   Updated: 2020/03/07 08:59:48 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_turn(t_map *tab)
{
	if (tab->moove.tourner_d == 1)
	{
		tab->angle += 3;
		tab->angle = tab->angle > 360 ?
		tab->angle - 360 : tab->angle;
		tab->oldplanex = tab->planex;
		tab->planex = tab->planex * cos(3 * (M_PI / 180))
		- tab->planey * sin(3 * (M_PI / 180));
		tab->planey = tab->oldplanex * sin(3 * (M_PI / 180))
		+ tab->planey * cos(3 * (M_PI / 180));
	}
	if (tab->moove.tourner_g == 1)
	{
		tab->angle -= 3;
		tab->angle = tab->angle < 0 ?
		360 - tab->angle : tab->angle;
		tab->oldplanex = tab->planex;
		tab->planex = tab->planex * cos(-3 * (M_PI / 180))
		- tab->planey * sin(-3 * (M_PI / 180));
		tab->planey = tab->oldplanex * sin(-3 * (M_PI / 180))
		+ tab->planey * cos(-3 * (M_PI / 180));
	}
}

void			ft_moove_r(t_map *tab)
{
	if (tab->moove.droite)
	{
		tab->planex = cos((tab->angle + 90) * M_PI / 180);
		tab->planey = sin((tab->angle + 90) * M_PI / 180);
		if (tab->map[(int)(tab->pos_x - cos((tab->angle + 90)
		* M_PI / 180) * tab->moove.speed)]
			[(int)(tab->pos_y - sin((tab->angle + 90) * M_PI
			/ 180) * tab->moove.speed)] == '0')
		{
			tab->pos_x -= cos((tab->angle + 90) * M_PI / 180)
			* tab->moove.speed;
			tab->pos_y -= sin((tab->angle + 90) * M_PI / 180)
			* tab->moove.speed;
		}
	}
}

void			ft_moove_l(t_map *tab)
{
	if (tab->moove.gauche)
	{
		tab->planex = cos((tab->angle + 90) * M_PI / 180);
		tab->planey = sin((tab->angle + 90) * M_PI / 180);
		if (tab->map[(int)(tab->pos_x + cos((tab->angle + 90)
		* M_PI / 180) * tab->moove.speed)]
			[(int)(tab->pos_y + sin((tab->angle + 90) * M_PI
			/ 180) * tab->moove.speed)] == '0')
		{
			tab->pos_x += cos((tab->angle + 90) * M_PI / 180)
			* tab->moove.speed;
			tab->pos_y += sin((tab->angle + 90) * M_PI / 180)
			* tab->moove.speed;
		}
	}
}

void			ft_moove_f(t_map *tab)
{
	if (tab->moove.avancer)
	{
		if (tab->map[(int)(tab->pos_x + cos((tab->angle)
		* M_PI / 180) * tab->moove.speed)]
			[(int)(tab->pos_y + sin((tab->angle) * M_PI
			/ 180) * tab->moove.speed)] == '0')
		{
			tab->pos_x += cos((tab->angle) * M_PI / 180)
			* tab->moove.speed;
			tab->pos_y += sin((tab->angle) * M_PI / 180)
			* tab->moove.speed;
		}
	}
}

void			ft_moove_b(t_map *tab)
{
	if (tab->moove.reculer)
	{
		if (tab->map[(int)(tab->pos_x - cos((tab->angle)
		* M_PI / 180) * tab->moove.speed)]
			[(int)(tab->pos_y - sin((tab->angle) * M_PI
			/ 180) * tab->moove.speed)] == '0')
		{
			tab->pos_x -= cos((tab->angle) * M_PI / 180)
			* tab->moove.speed;
			tab->pos_y -= sin((tab->angle) * M_PI / 180)
			* tab->moove.speed;
		}
	}
}
