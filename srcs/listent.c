/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:39:50 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/12 18:50:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	add_listent(t_listent **begin, t_dirent *curr_ent)
{
	t_listent	*l;

	if (*begin)
	{
		l = *begin;
		while (l->next)
			l = l->next;
		l->next = ft_memalloc(sizeof(t_dirent));
		l->next->back = l;
		l = l->next;
		l->next = NULL;
		l->dirent = curr_ent;
		l->name = curr_ent->d_name;
	}
	else
	{
		*begin = ft_memalloc(sizeof(t_dirent));
		l = *begin;
		l->next = NULL;
		l->back = NULL;
		l->dirent = curr_ent;
		l->name = curr_ent->d_name;
	}
}
