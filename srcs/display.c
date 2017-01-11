/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 06:16:24 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/11 07:43:47 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	read_file(t_ls *data, char *path, char *name)
{
	DIR					*curr_dir;
	struct	dirent		*curr_ent;

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
		printf("%s\n", curr_ent->d_name);
	else
		ft_printf("%s/%s\n", path, curr_ent->d_name);
}

void	recursive(t_ls *data, char *path)
{
	DIR		*curr_dir;

	if (!(curr_dir = opendir(path)))
		read_file(data, path, ft_strrchr(path, '/'));

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
}
