/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doc_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-temm <ade-temm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:30:32 by ade-temm          #+#    #+#             */
/*   Updated: 2020/07/01 10:31:44 by ade-temm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_check(t_map *tab, int i)
{
	if (i == 6)
	{
		if (tab->doc->sol.green != -1 || tab->doc->sol.red != -1
		|| tab->doc->sol.blue != -1)
			return (ft_error(14));
	}
	else if (i == 7)
	{
		if (tab->doc->plafond.green != -1 || tab->doc->plafond.red != -1
		|| tab->doc->plafond.blue != -1)
			return (ft_error(14));
	}
}
