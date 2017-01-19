/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:39:50 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/19 16:05:11 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static t_listent	*new_listent(t_listent *current, t_dirent *curr_entry)
{
	t_listent	*list;

	list = (t_listent *)ft_memalloc(sizeof(t_listent));
	list->next = NULL;
	list->type = curr_entry->d_type;
	list->name = ft_strdup(curr_entry->d_name);
	list->back = current;
	return (list);
}

void	add_listent(t_listent **begin, t_dirent *curr_ent)
{
	t_listent	*l;

// les placer dans ordre ASCII name
	if (*begin)
	{
		l = *begin;
		while (l->next)
			l = l->next;
		l->next = new_listent(l, curr_ent);
		l = l->next;
	}
	else
		*begin = new_listent(NULL, curr_ent);
}

void	free_listent(t_listent **begin)
{
	t_listent	*l;

	if (*begin)
	{
		l = *begin;
		while (l)
		{
			*begin = l->next;
			ft_memdel((void **)&l->name);
			ft_memdel((void **)&l);
			l = *begin;
		}
	}
	*begin = NULL;
}
