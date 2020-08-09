/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doc_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:51:23 by ade-temm          #+#    #+#             */
/*   Updated: 2020/07/01 10:31:56 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_color		ft_parse_color_2(t_color stuff, char *str)
{
	while (ft_is_num(*str) == 1)
		str++;
	while (is_whitespace(*str) == 0)
		str++;
	if (*str == ',')
		str++;
	while (is_whitespace(*str) == 0)
		str++;
	if (ft_is_num(*str) != 1)
		ft_error(12);
	stuff.blue = ft_atoi(str);
	while (ft_is_num(*str) == 1)
		str++;
	while (is_whitespace(*str) == 0)
		str++;
	if (*str)
		ft_error(12);
	return (stuff);
}

t_color		ft_parse_color(t_color stuff, char *str)
{
	str += 1;
	while (is_whitespace(*str) == 0)
		str++;
	if (ft_is_num(*str) != 1)
		ft_error(12);
	stuff.red = ft_atoi(str);
	while (ft_is_num(*str) == 1)
		str++;
	while (is_whitespace(*str) == 0)
		str++;
	if (*str == ',')
		str++;
	while (is_whitespace(*str) == 0)
		str++;
	if (ft_is_num(*str) != 1)
		ft_error(12);
	stuff.green = ft_atoi(str);
	return (ft_parse_color_2(stuff, str));
}

int			ft_get_color(t_color stuff)
{
	return (stuff.red * (256 * 256) + stuff.green * 256 + stuff.blue);
}

void		parse_line(char *str, t_map *tab)
{
	int		i;

	i = what_is_it(str, tab);
	if (i == -1)
		ft_error(6);
	if (i == 0)
		parse_resolution(str, tab);
	else if (i >= 1 && i <= 5)
		parse_texture(str, tab, i);
	else if (i == 6)
	{
		ft_check(tab, i);
		tab->doc->sol = ft_parse_color(tab->doc->sol, str);
		tab->doc->sol.total = ft_get_color(tab->doc->sol);
	}
	else if (i == 7)
	{
		ft_check(tab, i);
		tab->doc->plafond = ft_parse_color(tab->doc->plafond, str);
		tab->doc->plafond.total = ft_get_color(tab->doc->plafond);
	}
	else if (i == 8)
		parse_map(tab, str);
}

void		check_parse(t_map *tab)
{
	if (tab->doc->sol.red < 0 || tab->doc->sol.red > 255)
		ft_error(2);
	if (tab->doc->sol.green < 0 || tab->doc->sol.green > 255)
		ft_error(3);
	if (tab->doc->sol.blue < 0 || tab->doc->sol.blue > 255)
		ft_error(4);
	if (tab->doc->plafond.red < 0 || tab->doc->plafond.red > 255)
		ft_error(2);
	if (tab->doc->plafond.green < 0 || tab->doc->plafond.green > 255)
		ft_error(3);
	if (tab->doc->plafond.blue < 0 || tab->doc->plafond.blue > 255)
		ft_error(4);
	check_map(tab);
}
