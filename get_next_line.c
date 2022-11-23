/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:13 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/23 15:04:56 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <string.h>
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
	size_t	len1;
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
       s1 = ft_strdup("");
    if (!s2)
		return (NULL);
	len1 = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i++] != '\0')
		new[i] = s1[i];
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
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


char	*row_finder(char *temp)
{
    static int i;
    int j = 0;
    char    *line;

    
    while (temp[i++] != '\n' )
        i++;
    line = malloc(sizeof(char) * (ft_strlen(temp)));
    if (temp[i] == '\n')
    {
        while (j++ <= i)
            line[j] = temp[j];
    return(line);
    }  
    i++;
return (0);
}
char	*get_next_line(int fd)
{
    static char *temp;
    char    *buf;
    char    *print;
    int i;


	if (fd <= 0 || BUFFER_SIZE <= 0)
        return (-1);
    
    buf = malloc(BUFFER_SIZE) * (sizeof(char));
    while (!ft_strchr(temp, '\n') && i = (read(fd, buf, BUFFER_SIZE)))	
        {
            if (i <= 0)
                return (-1);
    
            temp = strjoin(temp, buf);
            row_finder(temp)
    return(print);
}
