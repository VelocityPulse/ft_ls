/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 18:39:50 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/20 14:54:50 by cchameyr         ###   ########.fr       */
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
	BN
}

void	add_listent(t_listent **begin, t_dirent *curr_ent)
{
	t_listent	*l;
	t_listent	*new;

// les placer dans ordre ASCII name
	if (*begin)
	{
		l = *begin;
		while (l->next)
		{
			if (ft_strcmp(l->next->name, curr_ent->d_name) >= 0)
				break;
			l = l->next;
		}
		new = new_listent(curr_ent);
		new->back = l;
		new->next = l->next;
		l->next = new;
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
