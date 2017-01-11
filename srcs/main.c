/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:42:16 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/11 06:45:47 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"


/*
int		main(int argc, char **argv)
{
	DIR		*lol;
	DIR		*dp2;
	struct dirent	*lol2;
	struct dirent	*dir1;

	(void)argc;
	(void)argv;
	lol = opendir("/Users/cchameyr/");

	if (!lol)
		ft_printf("erreur lol\n");
	while ((lol2 = readdir(lol)))
	{
		ft_printf("%s\n", lol2->d_name);
		if (lol2->d_type == DT_DIR)
		{
			if ((dp2 = opendir(ft_strjoin("/Users/cchameyr/", lol2->d_name))))
				while ((dir1 = readdir(dp2)))
					ft_printf("\t%s\n", dir1->d_name);
		}
	}
	return (0);
}
*/



static void		init_data(t_ls *data)
{
	data->flag_l = false;
	data->flag_rec = false;
	data->flag_rev = false;
	data->flag_t = false;
	data->lpaths = NULL;
}

static void		get_flags(t_ls *data, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'l')
			data->flag_l = true;
		else if (str[i] == 'R')
			data->flag_rec = true;
		else if (str[i] == 'r')
			data->flag_rev = true;
		else if (str[i] == 't')
			data->flag_t = true;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", str[i]);
			ls_exit("usage: ft_ls [-Rlrt] [file ...]\n");
		}
	}
}

static void		add_path(t_path **paths, char *str)
{
	t_path		*p;

	if (*paths == NULL)
	{
		*paths = ft_memalloc(sizeof(t_path));
		(*paths)->path = str;
		(*paths)->next = NULL;
	}
	else
	{
		p = *paths;
		while (p->next)
			p = p->next;
		p->next = ft_memalloc(sizeof(t_path));
		p = p->next;
		p->path = str;
		p->next = NULL;
	}
}

static void		get_arg(t_ls *data, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1])
		get_flags(data, &av[i++][1]);
	while (i < ac)
		add_path(&data->lpaths, av[i++]);
	if (!data->lpaths)
		add_path(&data->lpaths, ".");
}

int		main(int argc, char **argv)
{
	t_ls	data;

	init_data(&data);
	get_arg(&data, argc, argv);
	display(&data);
	return (0);
}
