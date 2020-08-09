/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doc_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:46:39 by ade-temm          #+#    #+#             */
/*   Updated: 2020/03/10 11:20:03 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			is_whitespace(char c)
{
	if (c == 32 || c == 9 || (c <= 13 && c >= 11))
		return (0);
	return (1);
}

int			ft_is_num(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 || s2)
	{
		while ((unsigned char)s1[i] && (unsigned char)s2[i] && i < n)
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			i++;
		}
		if (i == n)
			return (0);
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

void		check_size(t_map *tab)
{
	if (tab->doc->res_x > 2560)
		tab->doc->res_x = 2560;
	if (tab->doc->res_y > 1440)
		tab->doc->res_y = 1440;
}

void		parse_resolution(char *str, t_map *tab)
{
	if (tab->doc->res == 1)
		ft_error(-1);
	tab->doc->res_x = ft_atoi(str + 1);
	while (*(str + 1) != ' ')
		str++;
	while (ft_is_num(*(str + 1)) == 0)
		str++;
	while (ft_is_num(*(str + 1)) == 1)
		str++;
	tab->doc->res_y = ft_atoi(str + 1);
	while (ft_is_num(*(str + 1)) == 0)
		str++;
	while (ft_is_num(*(str + 1)) == 1)
		str++;
	while (is_whitespace(*(str + 1)) == 0)
		str++;
	if (*(str + 1))
		ft_error(0);
	check_size(tab);
	if (!tab->doc->res_x || !tab->doc->res_y)
		ft_error(0);
	tab->doc->res = 1;
}
