/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:19:20 by gfragoso          #+#    #+#             */
/*   Updated: 2023/08/31 18:33:52 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_content(int fd, char *res, char *content)
{
	int	code;

	code = read(fd, content, BUFFER_SIZE);
	while (code > 0)
	{
		res = ft_strjoin(res, strdup_tilln(content));
		strcpy_fromn(content);
		if (ft_strchr(res, '\n'))
			return (res);
		code = read(fd, content, BUFFER_SIZE);
	}
	if (code == 0)
		content[0] = 0;
	if (code == -1)
	{
		if (res)
			free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	content[BUFFER_SIZE];
	char		*res;

	if (fd < 0)
		return (NULL);
	res = NULL;
	if (content[0])
	{
		res = strdup_tilln(content);
		strcpy_fromn(content);
		if (ft_strchr(res, '\n'))
			return (res);
	}
	res = get_content(fd, res, content);
	return (res);
}
