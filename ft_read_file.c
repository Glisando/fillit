/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:39:41 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/27 19:10:03 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read_file(char *argv)
{
	int		i;
	int		fd;
	char	buf;
	char	*figs;

	fd = open(argv, O_RDONLY);
	if (fd != -1)
	{
		i = 0;
		while (read(fd, &buf, 1) != 0)
			i++;
		if (i == 0)
			return (NULL);
		fd = close(fd);
		if ((figs = (char*)malloc(sizeof(char) * i + 1)) == NULL)
			return (NULL);
		fd = open(argv, O_RDONLY);
		i = 0;
		while (read(fd, &buf, 1) != 0)
			figs[i++] = buf;
		figs[i] = '\0';
		fd = close(fd);
		return (figs);
	}
	return (NULL);
}
