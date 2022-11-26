/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:13 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/25 15:38:08 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
    size_t  len;

	i = 0;
	j = 0;
    len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1)
       s1 = ft_strdup("");
    if (!s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
    {
        new[i] = s1[i];
        i++;
    }
        while (s2[j] != '\0')
		new[i++] = s2[j++];
    return (new);
}
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
char    *find_nextline(char *stash)
{
    int     i;
    int     j;
    char    *line_ret;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free (stash);
        return (NULL);
    }
    line_ret = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
        if (!line_ret)
            return (NULL);
    i++;
    while (stash[i])
        line_ret[j++] = stash[i++];
    free (stash);
    return (line_ret);
}
char    *find_newline(char *stash)
{
    int j;
    j = 0;
    char    *line_ret;
    
    if (!stash[j])
        return(NULL);
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
    return (line_ret);
}
char    *join_free(char *stash, char *buf)
{
    char    *temp;

    temp = strjoin(stash, buf);
    free(stash);
    return (temp);
}
char	*read_save(int fd, char *stash)
{
    char    *buf;
    int     read_byte;

    read_byte = 1;
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buf)
            return (NULL);
    if (!stash)
        stash = ft_strdup("");
    while (read_byte > 0) 
    {    
        read_byte = (read(fd, buf, BUFFER_SIZE));
        if (read_byte == -1)
        {
            free (buf);
            free (stash);
            return (NULL);
        }        
        stash[read_byte] = 0;
        stash = join_free(stash, buf);
        if (ft_strchr(stash, '\n'))
            break;
    }
    free (buf);
    return(stash);
}
char	*get_next_line(int fd)
{
    char        *line_ret;
    static char *stash;

    if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = (read_save(fd, stash));
    if (!stash)
        return (NULL);
    line_ret = find_newline(stash);
    stash = find_nextline(stash);
    return (line_ret);
    
}
