/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:50:13 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/12 19:17:41 by cchameyr         ###   ########.fr       */
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

char	*ft_strjoin_dir(char *s1, char *s2)
{
	char	*str;
	int		len;

	ft_printf("|%s| |%s|\n", s1, s2);
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = ft_memalloc(sizeof(char) * (len + 1));
		str = ft_strcpy(str, s1);
		str = ft_strcat(str, s2);
		str[len] = 0;
		ft_printf("|%s|\n", str);
		exit(0);
		return (str);
	}
	return (NULL);
}
