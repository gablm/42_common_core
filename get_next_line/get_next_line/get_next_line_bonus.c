/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfragoso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:19:20 by gfragoso          #+#    #+#             */
/*   Updated: 2023/08/31 18:35:08 by gfragoso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_all(char **content, char **res, int mode)
{
	if (*content)
	{
		free(*content);
		*content = NULL;
	}
	if (*res && mode)
	{
		free(*res);
		*res = NULL;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	total;
	size_t	i;

	total = size * nmemb;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	res = malloc(total);
	if (!res)
		return (NULL);
	i = 0;
	while (i < total)
		*((char *)res + i++) = 0;
	return (res);
}

char	*get_content(int fd, char **res, char **content)
{
	int	code;

	code = read(fd, *content, BUFFER_SIZE);
	if (code == 0)
	{
		if (*res && *res[0] == '\0')
			return (free_all(content, res, 1));
		free_all(content, res, 0);
		return (*res);
	}
	while (code > 0)
	{
		*res = ft_strjoin(*res, strdup_tilln(*content));
		strcpy_fromn(*content);
		if (ft_strchr(*res, '\n'))
			return (*res);
		code = read(fd, *content, BUFFER_SIZE);
	}
	if (code == -1)
		return (free_all(content, res, 1));
	return (*res);
}

char	*get_next_line(int fd)
{
	static char	*content[MAX_FILES_OPENED];
	char		*res;

	if (fd < 0 || fd >= MAX_FILES_OPENED)
		return (NULL);
	res = NULL;
	if (content[fd])
	{
		res = strdup_tilln(content[fd]);
		strcpy_fromn(content[fd]);
		if (ft_strchr(res, '\n'))
			return (res);
	}
	else
		content[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	res = get_content(fd, &res, &content[fd]);
	return (res);
}
