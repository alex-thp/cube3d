/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:54:42 by ade-temm          #+#    #+#             */
/*   Updated: 2020/06/27 09:55:15 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				loop_game(t_map *tab)
{
	int		i;

	i = 0;
	check_game(tab);
	if (tab->first_round || tab->moove.tourner_d || tab->moove.tourner_g
	|| tab->moove.avancer || tab->moove.reculer || tab->moove.gauche ||
	tab->moove.droite)
	{
		tab->first_round = 0;
		while (tab->dist->x <= tab->doc->res_x)
		{
			calc_dist(tab);
			display_ray(tab);
		}
		init_dir(tab);
		while (i < tab->nb_sprite)
		{
			ft_sort_sprite(tab);
			ft_print_sprite(tab, i);
			i++;
		}
	}
	mlx_put_image_to_window(tab->mlx.ptr, tab->mlx.win,
	tab->mlx.img, 0, 0);
	return (0);
}

int				init_main(t_map *tab)
{
	t_doc	*doc;
	t_pos	*dist;

	if (!(doc = (t_doc*)ft_calloc(sizeof(t_doc), 1)))
		return (-1);
	if (!(dist = (t_pos*)malloc(sizeof(t_pos))))
		return (-1);
	tab->doc = doc;
	tab->doc->map = NULL;
	tab->doc->no = NULL;
	tab->doc->so = NULL;
	tab->doc->we = NULL;
	tab->doc->ea = NULL;
	tab->doc->s = NULL;
	tab->doc->sol.green = -1;
	tab->doc->plafond.green = -1;
	tab->doc->sol.blue = -1;
	tab->doc->plafond.blue = -1;
	tab->doc->sol.red = -1;
	tab->doc->plafond.red = -1;
	tab->dist = dist;
	tab->check_pos = 0;
	tab->doc->sol.total = ft_get_color(tab->doc->sol);
	tab->doc->plafond.total = ft_get_color(tab->doc->plafond);
	return (0);
}

int				main(int ac, char **av)
{
	int		fd;
	t_map	*tab;

	if (ac < 2)
		ft_error(9);
	if (!(tab = (t_map*)ft_calloc(sizeof(t_map), 1)))
		return (-1);
	if (init_main(tab) == -1)
		ft_error(8);
	check_doc(av[1], tab);
	if (!(tab->zbuffer = malloc(sizeof(double) * (tab->doc->res_x + 1))))
		return (-1);
	position(tab);
	init_image(tab);
	fd = -1;
	while (++fd < 5)
		read_xpm_texture(tab->doc, tab, fd);
	ft_get_sprite(tab);
	mlx_hook(tab->mlx.win, 2, 0, appuyer, tab);
	mlx_hook(tab->mlx.win, 3, 0, relacher, tab);
	mlx_hook(tab->mlx.win, 17, 0, ft_close, tab);
	mlx_loop_hook(tab->mlx.ptr, &loop_game, tab);
	if (ac == 3 && ft_strncmp(av[2], "--save", 7) == 0)
		ft_make_screenshot(tab);
	mlx_loop(tab->mlx.ptr);
}
