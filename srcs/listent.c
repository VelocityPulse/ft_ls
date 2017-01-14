/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:39:50 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/14 15:24:33 by cchameyr         ###   ########.fr       */
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
		l->next = (t_listent *)ft_memalloc(sizeof(t_listent));
		l->next->back = l;
		l = l->next;
		l->next = NULL;
		l->dirent = curr_ent;
		l->name = ft_strdup(curr_ent->d_name);
	}
	else
	{
		*begin = (t_listent *)ft_memalloc(sizeof(t_listent));
		l = *begin;
		l->next = NULL;
		l->back = NULL;
		l->dirent = curr_ent;
		// ici copier juste le type et le name pour regler le probleme
		// des pertes de donnees
		l->name = ft_strdup(curr_ent->d_name);
	}
}
