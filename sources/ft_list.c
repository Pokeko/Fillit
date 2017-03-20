/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:20:43 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 20:21:52 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_list(t_form **g)
{
	if ((*g = (t_form*)malloc(sizeof(**g))) == NULL)
	{
		ft_putstr("Error Malloci\n");
		exit(0);
	}
	(*g)->next = NULL;
	(*g)->prev = NULL;
	(*g)->str = NULL;
}

void		ft_init_list_map(t_map **g)
{
	if ((*g = (t_map*)malloc(sizeof(**g))) == NULL)
	{
		ft_putstr("Error Malloc\n");
		exit(0);
	}
	(*g)->map = NULL;
	(*g)->tab = NULL;
}

t_form		*ft_add_elem(t_form **g)
{
	if ((*g = (t_form*)malloc(sizeof(**g))) == NULL)
	{
		ft_putstr("Error Malloc\n");
		exit(0);
	}
	(*g)->next = NULL;
	(*g)->prev = NULL;
	(*g)->str = NULL;
	return (*g);
}

t_form		*ft_add_form(char *buf, t_form *g, int index)
{
	t_form *h;

	g->str = ft_strdup(buf);
	g = verif_form(g);
	g->next = ft_add_elem(&h);
	g->next->prev = g;
	g->index = index;
	g = g->next;
	return (g);
}
