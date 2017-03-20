/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:06:33 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 18:57:38 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_form		*verif_form(t_form *g)
{
	char	*str;
	int		i;
	int		verif;

	verif = g->form;
	i = 0;
	str = ft_strdup(g->str);
	if (verif_form_2(g, str, 0))
		g->form = verif_form_2(g, str, 0);
	if (verif_form_3(g, str, 0))
		g->form = verif_form_3(g, str, 0);
	if (verif_form_4(g, str, 0))
		g->form = verif_form_4(g, str, 0);
	while (str[i])
	{
		if (str[i] == '#' && str[i + 4] == '#'
				&& str[i + 5] == '#' && str[i + 10] == '#')
			g->form = 19;
		i++;
	}
	return (g);
}
