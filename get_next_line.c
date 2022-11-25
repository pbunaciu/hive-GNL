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
	free (s1);
    free (s2);
    return (new);
}
char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	*null;

	null = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

char    *find_newline(char *stash)
{
    int i;
    int j;
    i = 0;
    j = 0;
    char    *line_ret;
    char    *tempbuf;
    
    while (stash[i] != '\0')
    {
        if (stash[i] != '\n')
            i++;
        if (stash[i] == '\n')
        {
            if (stash[i] == '\n' && i == 0)
                i = 1;
            line_ret = malloc(sizeof(char) * i + 1);
            if (!line_ret)
                return (NULL);
            while (j < i)
            {
                line_ret[j] = stash[j];
                j++;
            }
            line_ret[j++] = '\0';
            tempbuf = malloc(sizeof(char) * i + 1);
            tempbuf = ft_strchr(stash, '\n');
            //free (stash);
            stash = ft_strdup(tempbuf);
            
         }
        i++;

    }
    if (stash[i] == '\0')
        return(stash);
    return (line_ret);

}

char	*read_save(int fd, char *stash)
{
    char    *temp;
    char    *buf;
    int     read_byte;

    read_byte = 0;
    buf = malloc(sizeof(char) * (BUFFER_SIZE));
        if (!buf)
            return (NULL);
    if (!stash)
        stash = ft_strdup("");
    while (!ft_strchr(stash, '\n')) 
    {    
        read_byte = (read(fd, buf, BUFFER_SIZE));
        if (read_byte <= 0)
        {
            free (buf);
            free (stash);
            return (NULL);
        }        
        temp = ft_strdup(stash);
        free(stash);
        stash = strjoin(temp, buf);
    }
    //if (ft_strchr(stash, '\n'))
        return(find_newline(stash));
    
    
    free (stash);
    free (buf);
    return(NULL);
}
char	*get_next_line(int fd)
{
    static char *stash;

    if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    return(read_save(fd, stash));
}
