/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:41:23 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 20:03:03 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list_quit(t_form *g)
{
	while (g->prev != NULL)
		g = g->prev;
	while (g->next != NULL)
	{
		g = g->next;
		if (g->prev->str != NULL)
			free(g->prev->str);
		if (g->prev != NULL)
			free(g->prev);
	}
	if (g->str != NULL)
		free(g->str);
	free(g);
	ft_putstr("error\n");
	exit(1);
}

void	quit(t_form *g)
{
	if (g != NULL)
		free_list_quit(g);
	ft_putstr("error\n");
	exit(1);
}

void	free_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
