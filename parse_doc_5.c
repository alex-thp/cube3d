/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doc_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:53:52 by ade-temm          #+#    #+#             */
/*   Updated: 2020/07/01 10:24:29 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_error_2(int i)
{
	if (i == 6)
		ft_putstr_fd("Error\nMap not correct\n", 1);
	if (i == 7)
		ft_putstr_fd("Error\nMap should be rectangular\n", 1);
	if (i == 8)
		ft_putstr_fd("Error\nstructures can't be malloced\n", 1);
	if (i == 9)
		ft_putstr_fd("Error\nNo map included in line command\n", 1);
	if (i == 10)
		ft_putstr_fd("Error\nBad starting position\n", 1);
	if (i == 11)
		ft_putstr_fd("Error\nDouble definition of texture\n", 1);
	if (i == 12)
		ft_putstr_fd("Error\nProblem with color definition\n", 1);
	if (i == 13)
		ft_putstr_fd("Error\nFile not correct\n", 1);
	if (i == 14)
		ft_putstr_fd("Error\nDouble definition of a color\n", 1);
	exit(0);
}

void		ft_error(int i)
{
	if (i == -1)
		ft_putstr_fd("Error\nAvoid defining resolution twice\n", 1);
	if (i == 0)
		ft_putstr_fd("Error\nPlease make sure you selected a resolution\n", 1);
	if (i == 1)
		ft_putstr_fd("Error\nTexture not found\n", 1);
	if (i == 2)
		ft_putstr_fd("Error\nBad red value for sky/floor\n", 1);
	if (i == 3)
		ft_putstr_fd("Error\nBad green value for sky/floor\n", 1);
	if (i == 4)
		ft_putstr_fd("Error\nBad blue value for sky/floor\n", 1);
	if (i == 5)
		ft_putstr_fd("Error\nBad extention for map document\n", 1);
	if (i > 5)
		ft_error_2(i);
	exit(0);
}

int			is_correct(char c)
{
	if (c < '0' || c > '2')
	{
		if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ')
			return (1);
	}
	return (0);
}

int			is_okay(char c)
{
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

int			is_valid(t_map *tab, int i, int j)
{
	if (tab->map[i][j + 1] == ' ' || tab->map[i][j + 1] == 0)
		return (1);
	if (tab->map[i][j - 1] == ' ' || tab->map[i][j - 1] == 0)
		return (1);
	if (tab->map[i - 1][j] == ' ' || tab->map[i - 1][j] == 0)
		return (1);
	if (tab->map[i + 1][j] == ' ' || tab->map[i + 1][j] == 0)
		return (1);
	return (0);
}
