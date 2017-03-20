/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:51:20 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 20:22:05 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_pieces(char *str)
{
	int	i;
	int	lien;
	int	hash;

	hash = 0;
	lien = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			hash++;
			lien += str[i - 5] == '#' ? 1 : 0;
			lien += str[i - 1] == '#' ? 1 : 0;
			lien += str[i + 1] == '#' ? 1 : 0;
			lien += str[i + 5] == '#' ? 1 : 0;
		}
		i++;
	}
	if ((lien == 6 || lien == 8) && hash == 4)
		return (1);
	else
		return (0);
}

int		verif_form_2(t_form *g, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 5] == '#' && str[i + 6] == '#')
			g->form = 1;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 2] == '#' && str[i + 3] == '#')
			g->form = 2;
		if (str[i] == '#' && str[i + 5] == '#'
				&& str[i + 10] == '#' && str[i + 15] == '#')
			g->form = 3;
		if (str[i] == '#' && str[i + 5] == '#'
				&& str[i + 10] == '#' && str[i + 11] == '#')
			g->form = 4;
		if (str[i] == '#' && str[i + 3] == '#'
				&& str[i + 4] == '#' && str[i + 5] == '#')
			g->form = 5;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 6] == '#' && str[i + 11] == '#')
			g->form = 6;
		i++;
	}
	return (g->form);
}

int		verif_form_3(t_form *g, char *str, int i)
{
	while (str[i])
	{
		if (str[i + 5] == '#' && str[i + 1] == '#'
				&& str[i + 2] == '#' && str[i])
			g->form = 7;
		if (str[i] == '#' && str[i + 5] == '#'
				&& str[i + 9] == '#' && str[i + 10] == '#')
			g->form = 8;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 2] == '#' && str[i + 7] == '#')
			g->form = 9;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 5] == '#' && str[i + 10] == '#')
			g->form = 10;
		if (str[i] == '#' && str[i + 5] == '#'
				&& str[i + 6] == '#' && str[i + 7] == '#')
			g->form = 11;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 4] == '#' && str[i + 5] == '#')
			g->form = 12;
		i++;
	}
	return (g->form);
}

int		verif_form_4(t_form *g, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '#' && str[i + 5] == '#'
				&& str[i + 6] == '#' && str[i + 11] == '#')
			g->form = 13;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 6] == '#' && str[i + 7] == '#')
			g->form = 14;
		if (str[i] == '#' && str[i + 4] == '#'
				&& str[i + 5] == '#' && str[i + 9] == '#')
			g->form = 15;
		if (str[i] == '#' && str[i + 4] == '#'
				&& str[i + 5] == '#' && str[i + 6] == '#')
			g->form = 16;
		if (str[i] == '#' && str[i + 5] == '#'
				&& str[i + 6] == '#' && str[i + 10] == '#')
			g->form = 17;
		if (str[i] == '#' && str[i + 1] == '#'
				&& str[i + 2] == '#' && str[i + 6] == '#')
			g->form = 18;
		i++;
	}
	return (g->form);
}

int		verif_line(char *str)
{
	int i;
	int countline;
	int countcol;

	countline = 0;
	i = 0;
	countcol = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		countcol++;
		if (str[i] == '\n')
		{
			countline++;
			if (countcol != 5)
				return (0);
			else
				countcol = 0;
		}
		i++;
	}
	return (countline == 4);
}
