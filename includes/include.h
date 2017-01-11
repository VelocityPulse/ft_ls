/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:42:29 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/11 06:19:23 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INCLUDE_H
# define _INCLUDE_H

# include <unistd.h>
# include <dirent.h>
//# include <sys/stat.h>
# include <stdlib.h>
//# include <dirent.h>

# include "../libft/libft.h"

#include "debug.h"

typedef struct	s_path
{
	char			*path;
	struct s_path	*next;
}				t_path;

typedef struct	s_ls
{
	t_bool		flag_l;
	t_bool		flag_rec;
	t_bool		flag_rev;
	t_bool		flag_t;
	t_path		*lpaths;
}				t_ls;

void			ls_exit(char *str);
void			display(t_ls *data);

/*
** TOOLS
*/

char			*get_parent(char *path);

#endif
