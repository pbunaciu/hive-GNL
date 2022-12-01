/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:13 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/12/01 16:52:33 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*find_nextline(char *stash, int len)
{
	int		i;
	int		j;
	char	*line_ret;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line_ret = malloc(sizeof(char) * (len - i + 1));
	if (!line_ret)
		return (NULL);
	len = len - i;
	i++;
	while (stash[i])
		line_ret[j++] = stash[i++];
	free (stash);
	stash = NULL;
	line_ret[j] = '\0';
	return (line_ret);
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

char	*read_save(int fd, char *stash, int len)
{
	char	*buf;
	int		read_bytes;
	char	*temp;

	read_bytes = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		len = len + read_bytes;
		temp = strjoin(stash, buf);
		free (stash);
		stash = temp;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line_ret;
	static char	*stash;
	static int	len;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	stash = (read_save(fd, stash, len));
	if (!stash)
		return (NULL);
	line_ret = find_newline(stash);
	stash = find_nextline(stash, len);
	return (line_ret);
}
