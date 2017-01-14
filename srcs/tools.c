/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 02:50:13 by cchameyr          #+#    #+#             */
/*   Updated: 2017/01/14 13:06:45 by cchameyr         ###   ########.fr       */
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
	int		len1;
	int		len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = ft_memalloc(sizeof(char) * (len1 + len2 + 2));
		str = ft_strcpy(str, s1);
		if (str[len1 - 1] != '/')
			str[len1] = '/';
		str = ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
