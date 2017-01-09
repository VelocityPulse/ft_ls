/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:42:16 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/09 16:33:15 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

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
