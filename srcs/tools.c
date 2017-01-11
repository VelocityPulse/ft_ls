/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:50:13 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/11 03:49:33 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

char	*get_parent(char *path)
{
	int		i;

	i = ft_strlen(path);
	while (path[--i])
	{
		if (path[i] == '/')
		{
			path[i] = 0;
			return (path);
		}
	}
	return (path);
}
