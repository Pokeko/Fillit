/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:32:08 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 20:37:13 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "piece.h"

char		**ft_put_point(t_map *g, int ind, int pos, int size)
{
	int		i;
	int		j;
	int		a;
	int		b;

	i = pos / size;
	j = pos % size;
	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			if (g_pieces[g->tab[ind]][a][b] == '#')
				g->map[i + a][j + b] = '.';
			b++;
		}
		b = 0;
		a++;
	}
	return (g->map);
}

char		**ft_put_pieces(t_map *g, int ind, int pos, int size)
{
	int		i;
	int		j;
	int		a;
	int		b;

	i = pos / size;
	j = pos % size;
	a = 0;
	b = 0;
	while (a < 4)
	{
		while (b < 4)
		{
			if (g_pieces[g->tab[ind]][a][b] == '#')
				g->map[i + a][j + b] = ind + 'A';
			b++;
		}
		b = 0;
		a++;
	}
	return (g->map);
}

int			ft_check_place(t_map *g, int ind, int pos, int size)
{
	int		i;
	int		j;
	int		a;
	int		b;
	int		count;

	count = 0;
	i = pos / size;
	j = pos % size;
	a = 0;
	b = 0;
	while (a < 4)
	{
		while (i + a < size && j + b < size && b < 4)
		{
			if (g_pieces[g->tab[ind]][a][b] == '#'
					&& g->map[i + a][j + b] < 'A')
				count++;
			b++;
		}
		b = 0;
		a++;
	}
	return (count == 4);
}

int			resolve(t_map *g, int ind, int position, int size)
{
	if (g->tab[ind] == 99)
		return (1);
	while (position < size * size)
	{
		if (ft_check_place(g, ind, position, size))
		{
			g->map = ft_put_pieces(g, ind, position, size);
			if (resolve(g, ind + 1, 0, size))
				return (1);
			else
				g->map = ft_put_point(g, ind, position, size);
		}
		position++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_form	*g;
	t_map	*test;
	int		*tab;
	char	**map;
	int		max;

	if (argc != 2)
	{
		ft_putstr("usage : fillit Source_file\n");
		return (0);
	}
	ft_init_list(&g);
	ft_init_list_map(&test);
	max = rdd_file(argv[1], g, 0, 0);
	while (g->prev != NULL)
		g = g->prev;
	tab = get_form(g, max);
	map = new_map(2);
	test->tab = tab;
	test->map = map;
	result(test);
	return (0);
}
