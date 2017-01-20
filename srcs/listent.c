/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:39:50 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/20 18:16:11 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static t_listent	*new_listent(t_dirent *curr_entry)
{
	t_listent	*list;

	list = (t_listent *)ft_memalloc(sizeof(t_listent));
	list->type = curr_entry->d_type;
	list->name = ft_strdup(curr_entry->d_name);
	list->next = NULL;
	list->back = NULL;
	list->end = list;
	return (list);
}

static void			make_sorting_listent(int find, t_listent *new, t_listent *l)
{
	if (!find)
	{
		l->next = new;
		new->back = l;
	}
	else
	{
		new->back = l->back;
		new->next = l;
		if (l->back)
			l->back->next = new;
		l->back = new;
	}
}

void	add_listent(t_listent **begin, t_dirent *curr_ent)
{
	t_listent	*l;
	t_listent	*new;
	int			find;

	if (*begin && !(find = 0))
	{
		l = *begin;
		while (l->next)
		{
			if (ft_strcmp(l->name, curr_ent->d_name) >= 0)
			{
				find++;
				break;
			}
			l = l->next;
		}
		new = new_listent(curr_ent);
		make_sorting_listent(find, new, l);
		*begin = (new->back == 0 ? new : *begin);
		(*begin)->end = (new->next == 0 ? new : (*begin)->end);
	}
	else
		*begin = new_listent(curr_ent);
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

void	display_list(t_listent *list)
{
	while (list)
	{
		ft_putendl(list->name);
		list = list->next;
	}
}
