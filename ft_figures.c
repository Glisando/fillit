/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figures4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:37:46 by knovytsk          #+#    #+#             */
/*   Updated: 2017/12/20 13:37:03 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_move_fig(t_fig *fig)
{
	int i;
	int xmin;
	int	ymin;

	i = 0;
	xmin = 3;
	ymin = 3;
	while (i < 4)
	{
		if (fig->x[i] < xmin)
			xmin = fig->x[i];
		if (fig->y[i] < ymin)
			ymin = fig->y[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		fig->x[i] = fig->x[i] - xmin;
		fig->y[i] = fig->y[i] - ymin;
		i++;
	}
}

void		ft_coordinates(char *s, t_fig *figura)
{
	int		i;
	int		j;
	int		index;
	int		line;

	i = 0;
	j = 0;
	line = -1;
	figura->x = (int*)malloc(sizeof(int) * 4);
	figura->y = (int*)malloc(sizeof(int) * 4);
	while (++line < 4)
	{
		index = 0;
		while (s[i] != '\n' && s[i] != '\0')
		{
			if (s[i] == '#')
			{
				figura->x[j] = index;
				figura->y[j++] = line;
			}
			i++;
			index++;
		}
		i++;
	}
}

void		ft_figures(char *s)
{
	t_fig	**figura;
	size_t	block;
	size_t	index;
	size_t	size;

	size = ft_strlen(s) / 21 + 1;
	block = 0;
	index = 0;
	figura = (t_fig**)malloc(sizeof(t_fig*) * (size + 1));
	while (index < size)
	{
		figura[index] = (t_fig*)malloc(sizeof(t_fig));
		ft_coordinates(&s[block], figura[index]);
		figura[index]->letter = index + 65;
		ft_move_fig(figura[index]);
		block = block + 21;
		index++;
	}
	figura[index] = NULL;
	size = ft_sqrt(index * 4);
	ft_map(figura, size);
}
