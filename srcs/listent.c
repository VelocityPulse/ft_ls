/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:39:50 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/20 17:24:42 by cchameyr         ###   ########.fr       */
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
	return (list);
}

void	display_list(t_listent *list)
{
	while (list)
	{
//		ft_printf("%s->", list->name);
		ft_putendl(list->name);
		list = list->next;
	}

}

void	add_listent(t_listent **begin, t_dirent *curr_ent)
{
	t_listent	*l;
	t_listent	*new;
	int			find;

// les placer dans ordre ASCII name
	ft_printf("%s\n", curr_ent->d_name);
	if (*begin)
	{
		find = 0;
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
		if (!new->back)
			*begin = new;
	}
	else
	{
		*begin = new_listent(curr_ent);
		(*begin)->end = *begin;
	}
//	display_list(*begin);
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
