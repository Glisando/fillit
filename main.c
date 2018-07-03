/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:20:33 by knovytsk          #+#    #+#             */
/*   Updated: 2017/11/26 20:06:58 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	char	*figs;

	figs = NULL;
	if (argc != 2)
	{
		write(1, "usage: ./fillit [file_name]\n", 28);
		exit(0);
	}
	if ((figs = ft_read_file(argv[1])) == NULL ||
				(ft_valid(figs) == 0))
		write(1, "error\n", 6);
	else
		ft_figures(figs);
	return (0);
}
