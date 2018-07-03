/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:57:52 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/26 19:43:01 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_put_fig(char **map, t_map *t_cord, t_fig *fig)
{
	int k;

	k = 0;
	while (k < 4)
	{
		map[t_cord->j + fig->y[k]][t_cord->i + fig->x[k]] = fig->letter;
		k++;
	}
	return (map);
}

char	**ft_remove_fig(char **map, int remi, int remj, t_fig *fig)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		map[remj + fig->y[k]][remi + fig->x[k]] = '.';
		k++;
	}
	return (map);
}

int		ft_findplace(char **map, t_map *t_cord, t_fig *fig)
{
	int k;

	k = 0;
	while (k < 4 && (t_cord->j + fig->y[k] < t_cord->size &&
				t_cord->i + fig->x[k] < t_cord->size))
	{
		if (map[t_cord->j + fig->y[k]][t_cord->i + fig->x[k]] != '.')
			break ;
		k++;
	}
	if (k == 4)
	{
		map = ft_put_fig(map, t_cord, fig);
		return (1);
	}
	return (0);
}

int		ft_backtrack(char **map, t_map *t_cord, int f, t_fig **fig)
{
	int		remj;
	int		remi;
//
	if (fig[f] == NULL)
		return (1);
	t_cord->j = 0;
	while (t_cord->j < t_cord->size)
	{
		t_cord->i = -1;
		while (++t_cord->i < t_cord->size)
		{
			if (ft_findplace(map, t_cord, fig[f]))
			{
				remi = t_cord->i;
				remj = t_cord->j;
				if (ft_backtrack(map, t_cord, f + 1, fig))
					return (1);
				t_cord->i = remi;
				t_cord->j = remj;
				map = ft_remove_fig(map, remi, remj, fig[f]);
			}
		}
		t_cord->j++;
	}
	return (0);
}
