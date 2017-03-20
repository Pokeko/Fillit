/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:14:32 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 20:20:35 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_map
{
	int				*tab;
	char			**map;
}					t_map;

typedef struct		s_form
{
	int				form;
	int				index;
	char			*str;
	struct s_form	*next;
	struct s_form	*prev;
}					t_form;

void				ft_init_list_map(t_map **g);
void				result(t_map *g);
int					resolve(t_map *g, int ind, int pos, int size);
int					rdd_file(char *str, t_form *g, int rd, int fd);
int					verif_line(char *str);
t_form				*verif_form(t_form *g);
int					check_pieces(char *str);
void				ft_init_list(t_form **g);
t_form				*ft_add_elem(t_form **g);
int					verif_form_3(t_form *g, char *str, int i);
int					verif_form_4(t_form *g, char *str, int i);
t_form				*ft_add_form(char *buf, t_form *g, int index);
int					verif_form_2(t_form *g, char *str, int i);
char				**new_map(int size);
int					*get_form(t_form *g, int max);
void				free_list_quit(t_form *g);
void				quit(t_form *g);
void				free_map(char **map, int size);
#endif
