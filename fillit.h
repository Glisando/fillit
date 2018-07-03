/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:02:56 by knovytsk          #+#    #+#             */
/*   Updated: 2017/12/19 14:42:01 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_fig
{
	int			*x;
	int			*y;
	char		letter;
}				t_fig;

typedef struct	s_map
{
	int			i;
	int			j;
	int			size;
}				t_map;

size_t			ft_strlen(const char *str);
int				ft_valid(char *s);
int				ft_sqrt(int nb);
int				ft_backtrack(char **map, t_map *t_cord, int f, t_fig **figures);
char			*ft_read_file(char *argv);
void			ft_figures(char *s);
void			ft_putstr(char const *str);
void			ft_strdel(char **str);
void			ft_map(t_fig **figures, int size);

#endif
