/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:42:29 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/20 15:20:51 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INCLUDE_H
# define _INCLUDE_H

# include <unistd.h>
# include <dirent.h>
//# include <sys/stat.h>
# include <stdlib.h>

# include "../libft/libft.h"

#include "debug.h"

//typedef DIR				t_dir;
typedef struct dirent	t_dirent;

typedef struct	s_path
{
	char			*path;
	struct s_path	*next;
}				t_path;

typedef struct	s_listent
{
	char				*name;
	int					type;
	struct s_listent	*next;
	struct s_listent	*back;
	struct s_listent	*end;
}				t_listent;

typedef struct	s_ls
{
	t_bool		flag_l;
	t_bool		flag_rec;
	t_bool		flag_rev;
	t_bool		flag_t;
	t_bool		flag_a;
	t_path		*lpaths;
}				t_ls;

void			ls_exit(char *str);
void			display(t_ls *data);

/*
** LISTS
*/

void			add_listent(t_listent **list, t_dirent *curr_ent);
void			free_listent(t_listent **list);
void			display_list(t_listent *list);

/*
** TOOLS
*/

char			*get_parent(char *path);
char			*ft_strjoin_dir(char *s1, char *s2);

#endif
