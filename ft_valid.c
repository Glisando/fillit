/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:48:13 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/26 20:23:10 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_struct(char *str)
{
	size_t	len;
	int		j;
	size_t	i;

	len = ft_strlen(str);
	j = 0;
	i = 4;
	while (i <= len)
	{
		if (++j % 4 == 0)
		{
			if (str[i] != '\n' && str[i] != '\0')
				return (0);
			i++;
		}
		if (str[i] != '\n' && str[i] != '\0')
			return (0);
		i += 5;
	}
	if (str[i - 5] != '\0')
		return (0);
	return (1);
}

int			ft_check_tetrimino(char *s, int i, int min, int max)
{
	int		block;
	int		count;

	block = 0;
	count = 0;
	while (i < max && (s[i] == '#' || s[i] == '.' || s[i] == '\n'))
	{
		if (s[i] == '#')
			count++;
		if (i + 1 < max && s[i + 1] == '#' && s[i] == '#')
			block++;
		if (i - 1 >= min && s[i - 1] == '#' && s[i] == '#')
			block++;
		if (i + 5 < max && s[i + 5] == '#' && s[i] == '#')
			block++;
		if (i - 5 >= min && s[i - 5] == '#' && s[i] == '#')
			block++;
		i++;
	}
	if (count == 4 && i + 1 >= max && (block == 6 || block == 8))
		return (1);
	return (0);
}

int			ft_valid(char *s)
{
	int		i;
	int		len;
	int		max;
	int		min;

	len = ft_strlen(s);
	max = 21;
	i = 0;
	if ((ft_check_struct(s)) == 1)
	{
		while (i < len && i < 546)
		{
			min = i;
			if (ft_check_tetrimino(s, i, min, max + i) == 1)
				i = i + 20;
			else
				return (0);
			i++;
		}
		if (len < 546)
			return (1);
	}
	return (0);
}
