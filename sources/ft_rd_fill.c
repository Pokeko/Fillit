/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rd_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:01:49 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 20:21:59 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			rdd_file(char *str, t_form *g, int rd, int fd)
{
	char	buf[21];
	int		index;
	char	c;

	index = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		quit(g);
	bzero(buf, 21);
	while ((rd = read(fd, buf, 21)))
	{
		c = buf[20];
		buf[20] = '\0';
		if ((buf[18] != '.' && buf[18] != '#')
				|| !verif_line(buf) || !check_pieces(buf))
			quit(g);
		g = ft_add_form(buf, g, index);
		bzero(buf, 21);
		index++;
	}
	if (c == '\n' || index <= 0)
		quit(g);
	close(fd);
	return (index);
}

char		**new_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = (char **)malloc(sizeof(char **) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	return (map);
}

int			*get_form(t_form *g, int max)
{
	int		*tab;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (!(tab = (int*)malloc(sizeof(int) * max + 1)))
		return (NULL);
	while (g->prev != NULL)
		g = g->prev;
	while (k < max)
	{
		tab[k] = g->form - 1;
		free(g->str);
		g = g->next;
		free(g->prev);
		k++;
	}
	free(g);
	tab[k] = 99;
	return (tab);
}

void		result(t_map *g)
{
	int		i;
	int		size;

	size = 2;
	i = 0;
	while (!resolve(g, 0, 0, size))
	{
		free_map(g->map, size);
		size++;
		g->map = new_map(size);
	}
	free(g->tab);
	while (i < size)
	{
		ft_putstr(g->map[i]);
		ft_putchar('\n');
		i++;
	}
	free_map(g->map, size);
}
