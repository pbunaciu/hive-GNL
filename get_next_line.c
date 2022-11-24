/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:13 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/24 12:14:25 by pbunaciu         ###   ########.fr       */
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
	while (s1[i++] != '\0')
		new[i] = s1[i];
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
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (null);
		str++;
	}
	return (str);
}
char    *find_newline(char *stash)
{
    int i;
    int j;
    i = 0;
    j = 0;
    char    *line_ret;
    while (stash[i] != '\0')
    {
        if (stash[i] != '\n')
            i++;
        if (stash[i] == '\n')
        {
            line_ret = malloc(sizeof(char) * i + 1);
            if (!line_ret)
                return (NULL);
            while (j++ < i)
            {
                line_ret[j] = stash[j];
                stash[j] = '\0';          
            }
            line_ret[j++] = '\0';
        
          //  while (i-- >= 0)
            //    stash[i] = 0;
         }
    }
    line_ret = NULL;
    free(line_ret);
    return (line_ret);

}

char	*read_save(int fd, char *stash)
{
    char    *temp2;
    char    *buf;

    buf = malloc(sizeof(char) * (BUFFER_SIZE));
        if (!buf)
            return (NULL);
    while (!ft_strchr(stash, '\n')) 
    {    
        read(fd, buf, BUFFER_SIZE);
        temp2 = stash;
        stash = strjoin(temp2, buf);
        return(find_newline(stash));
    }
    return(NULL);

}
char	*get_next_line(int fd)
{
    char    *ret;
    static char *stash;

    if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    ret = (read_save(fd, stash));
  
    return(ret);
}
