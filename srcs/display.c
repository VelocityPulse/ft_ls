/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 06:16:24 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/16 17:38:28 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	read_not_dir(t_ls *data, char *path, char *name)
{
	DIR			*curr_dir;
	t_dirent	*curr_ent;

	name = (name == NULL ? path : name + 1);
	if (!(curr_dir = opendir(path)))
		if (!(curr_dir = opendir(get_parent(path))))
			curr_dir = opendir(".");
	while ((curr_ent = readdir(curr_dir)))
		if (!ft_strcmp(curr_ent->d_name, name))
			break;
	if (curr_ent == NULL)
	{
		if (path == name)
			ft_printf("ft_ls: %s: No such file or directory\n", path);
		else
			ft_printf("ft_ls: %s/%s: No such file or directory\n", path, name);
		return ;
	}
	//stat patati pampata :3
	//ajouter dans des list chaine bref bref :3
	if (path == name)
		ft_putendl(curr_ent->d_name);
	else
		ft_printf("%s/%s\n", path, curr_ent->d_name);
	(void)data;
}

void	recursive(t_ls *data, char *path)
{
	DIR				*curr_dir;
	t_dirent		*curr_ent;
	t_listent		*list_ent;
	t_listent		*tmp;
	char			*join;
	static int		folder = 0;
	static int		not_dir = 0;


	list_ent = NULL;
	if (!(curr_dir = opendir(path)))
		read_not_dir(data, path, ft_strrchr(path, '/'));
	else
	{
		while ((curr_ent = readdir(curr_dir)))
		{
			add_listent(&list_ent, curr_ent);
			if (ft_strncmp(curr_ent->d_name, ".", 1) && ft_strncmp(curr_ent->d_name, "..", 2))
				ft_putendl(curr_ent->d_name);
			//display_curr
		}
		tmp = list_ent;
		while (tmp)
		{
			if (tmp->type == DT_DIR)
			{
				if (ft_strncmp(tmp->name, ".", 2) && ft_strncmp(tmp->name, "..", 3))
					// obligatoire pour pas avoir de boucle infini
				{
					if (ft_strncmp(tmp->name, ".", 1) && ft_strncmp(tmp->name, "..", 2))
					{
						// necessaire pour pas afficher les fichers caches
						join = ft_strjoin_dir(path, tmp->name);
						ft_printf("\n%s:\n", join);
						recursive(data, join);
						ft_memdel((void **)&join);
					}
				}
			}
			tmp = tmp->next;
		}
		closedir(curr_dir);
		free_listent(&list_ent);
	}
	//free list_ent
	//closedir list_ent blabla
}

void	display(t_ls *data)
{
	t_path		*p;

	p = data->lpaths;
	if (data->flag_rec)
	{
		while (p)
		{
			recursive(data, p->path);
			p = p->next;
		}
	}
	else
		ft_printf("think to use -R for debug\n");
}
