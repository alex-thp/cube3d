/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doc_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:48:24 by ade-temm          #+#    #+#             */
/*   Updated: 2020/06/27 10:58:42 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_texture_2(t_map *tab, int i, char *text)
{
	if (i == 3)
	{
		if (tab->doc->we)
			ft_error(11);
		tab->doc->we = (text + 2);
	}
	else if (i == 4)
	{
		if (tab->doc->ea)
			ft_error(11);
		tab->doc->ea = (text + 2);
	}
	else if (i == 5)
	{
		if (tab->doc->s)
			ft_error(11);
		tab->doc->s = (text + 2);
	}
}

void		parse_texture(char *str, t_map *tab, int i)
{
	char	*text;

	text = ft_strdup(str);
	while (is_whitespace(*(text)) == 0)
		text++;
	text += 2;
	while (is_whitespace(*(text)) == 0)
		text++;
	if (i == 1)
	{
		if (tab->doc->no)
			ft_error(11);
		tab->doc->no = (text + 2);
	}
	else if (i == 2)
	{
		if (tab->doc->so)
			ft_error(11);
		tab->doc->so = (text + 2);
	}
	parse_texture_2(tab, i, text);
}

int			is_it_map(char *str, t_map *tab)
{
	if (ft_is_num(*str) == 1 || *str == ' ')
	{
		tab->doc->parsing_map = 1;
		return (8);
	}
	if ((tab->doc->parsing_map == 0 || tab->check_gnl == 0) && *str == 0)
		return (9);
	return (-1);
}

int			what_is_it(char *str, t_map *tab)
{
	while (is_whitespace(*str) == 0)
		str++;
	if (ft_strncmp(str, "R", 1) == 0 && tab->doc->parsing_map == 0)
		return (0);
	else if (ft_strncmp(str, "NO", 2) == 0 && tab->doc->parsing_map == 0)
		return (1);
	else if (ft_strncmp(str, "SO", 2) == 0 && tab->doc->parsing_map == 0)
		return (2);
	else if (ft_strncmp(str, "WE", 2) == 0 && tab->doc->parsing_map == 0)
		return (3);
	else if (ft_strncmp(str, "EA", 2) == 0 && tab->doc->parsing_map == 0)
		return (4);
	else if (ft_strncmp(str, "S", 1) == 0 && tab->doc->parsing_map == 0)
		return (5);
	else if (ft_strncmp(str, "F", 1) == 0 && tab->doc->parsing_map == 0)
		return (6);
	else if (ft_strncmp(str, "C", 1) == 0 && tab->doc->parsing_map == 0)
		return (7);
	else
		return (is_it_map(str, tab));
	return (0);
}

void		parse_map(t_map *tab, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tab->doc->map))
	{
		tab->doc->map = malloc(1);
		tab->doc->map[0] = 0;
	}
	while (line[i])
	{
		if (ft_is_num(line[i]) != 1 && line[i] != 'N' && line[i] != 'S'
		&& line[i] != 'E' && line[i] != 'W' && line[i] != ' ')
			ft_error(6);
		i++;
	}
	tmp = ft_strjoin_gnl(tab->doc->map, line, 2147483647);
	tab->doc->map = ft_strjoin_gnl(tmp, ".", 2147483647);
}
