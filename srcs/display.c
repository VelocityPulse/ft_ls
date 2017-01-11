/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 00:54:01 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/11 04:01:05 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	read_specify_file(t_ls *data, DIR *curr_dir, char *file)
{
	struct dirent	*dir_entry;


	while ((dir_entry = readdir(curr_dir)))
	{
		if (!ft_strcmp(dir_entry->d_name, file))
		{
			//print stat
			ft_printf("%s\n", data->curr_path->path);
			return ;
		}
	}
	ft_printf("2ft_ls: %s: No such file or directory\n", file);
	(void)data;
}


void	recursive(t_ls *data, char *npath)
{
	DIR				*curr_dir;
	struct dirent	*dir_entry;

	if (!(curr_dir = opendir(npath)))
	{
		if (!(curr_dir = opendir(get_parent(npath))))
		{
			curr_dir = opendir(".");
			read_specify_file(data, curr_dir, data->curr_path->path);
		}
		else
			read_specify_file(data, curr_dir,
					ft_strrchr(data->curr_path->path, '/') + 1);
	}

	exit(0);

	dir_entry = readdir(curr_dir);
	ft_printf("|%s|\n", dir_entry->d_name);

	(void)data;
	(void)npath;
}



void	display(t_ls *data)
{
	data->curr_path = data->lpaths;
	if (data->flag_rec)
	{
		while (data->curr_path)
		{
			recursive(data, ft_strdup(data->curr_path->path));
			data->curr_path = data->curr_path->next;
		}
	}
}
