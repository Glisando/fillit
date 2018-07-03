/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:16:28 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/25 16:49:09 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_display_result(char **map)
{
	int p;

	p = 0;
	while (map[p] != NULL)
	{
		ft_putstr(map[p]);
		ft_putstr("\n");
		p++;
	}
}

void		ft_solve(char **map, t_fig **figures, t_map *t_cord)
{
	if (ft_backtrack(map, t_cord, 0, figures) != 1)
	{
		ft_strdel(map);
		ft_map(figures, t_cord->j + 1);
	}
	else
		ft_display_result(map);
}

void		ft_map(t_fig **figures, int size)
{
	char	**map;
	int		x;
	int		y;
	t_map	*t_cord;

	y = 0;
	t_cord = (t_map*)malloc(sizeof(t_map));
	map = (char**)malloc(sizeof(char*) * size + 1);
	while (y < size)
	{
		map[y] = (char*)malloc(sizeof(char) * size + 1);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	t_cord->i = 0;
	t_cord->j = 0;
	t_cord->size = size;
	ft_solve(map, figures, t_cord);
}
