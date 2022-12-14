/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:13 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/12/13 10:38:13 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*find_nextline(char *stash, int *error)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
	{
		*error = 1;
		return (NULL);
	}
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free (stash);
	new_stash[j] = '\0';
	return (new_stash);
}

char	*find_newline(char *stash)
{
	int		j;
	char	*line_ret;

	j = 0;
	if (!stash[j])
		return (NULL);
	while (stash[j] && stash[j] != '\n')
			j++;
	line_ret = malloc(sizeof(char) * (j + 2));
	if (!line_ret)
		return (NULL);
	j = 0;
	while (stash[j] && stash[j] != '\n')
	{
		line_ret[j] = stash[j];
		j++;
	}
	if (stash[j] && stash[j] == '\n')
		line_ret[j++] = '\n';
	line_ret[j] = '\0';
	return (line_ret);
}

char	*read_save(int fd, char *stash)
{
	char	*buf;
	int		read_bytes;

	read_bytes = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read_bytes > 0 && !ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		stash = strjoin(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line_ret;
	static char	*stash[OPEN_MAX];
	int			error;

	error = 0;
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	if (!stash[fd])
		return (NULL);
	stash[fd] = (read_save(fd, stash[fd]));
	if (!stash[fd])
		return (NULL);
	line_ret = find_newline(stash[fd]);
	stash[fd] = find_nextline(stash[fd], &error);
	if (error)
	{
		free (line_ret);
		return (NULL);
	}
	return (line_ret);
}
