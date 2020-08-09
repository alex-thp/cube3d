/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 09:47:03 by ade-temm          #+#    #+#             */
/*   Updated: 2020/06/27 10:09:52 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gnl/get_next_line.h"
#include <stdio.h>

int			check_around(t_map *tab, int i, int j)
{
	int		tmp;
	int		tmp2;

	tmp = 0;
	tmp2 = 0;
	while (tab->map[tmp])
		tmp++;
	while (tab->map[i][tmp2])
		tmp2++;
	if (i == 0)
		return (1);
	if (j == 0)
		return (1);
	if (i == tmp - 1)
		return (1);
	if (j == tmp2 - 1)
		return (1);
	tmp = ft_strlen(tab->map[i - 1]);
	tmp2 = ft_strlen(tab->map[i + 1]);
	if (j > tmp || j > tmp2)
		return (1);
	if (is_valid(tab, i, j) == 1)
		return (1);
	return (0);
}

void		check_map(t_map *tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab->map[i])
	{
		j = 0;
		while (tab->map[i][j])
		{
			if (is_okay(tab->map[i][j]) == 0)
			{
				if (check_around(tab, i, j) == 1)
					ft_error(6);
				if (is_correct(tab->map[i][j]) == 1)
					ft_error(10);
			}
			j++;
		}
		i++;
	}
}

void		parse_doc(char *str, t_map *tab)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	tab->doc->parsing_map = 0;
	tab->check_gnl = 1;
	while (tab->check_gnl > 0)
	{
		tab->check_gnl = get_next_line(fd, &line);
		parse_line(line, tab);
		free(line);
	}
	tab->map = ft_split(tab->doc->map, '.');
	check_parse(tab);
}

void		check_doc(char *str, t_map *tab)
{
	tab->doc->res = 0;
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4) != 0)
		ft_error(5);
	else
		parse_doc(str, tab);
}
