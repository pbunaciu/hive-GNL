/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:13 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/23 17:26:28 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strjoin(char *s1, char *s2, int len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
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


char	*read_save(int fd, char *temp)
{
    int r = 0;
    int j = 0;
    char    *temp2;
    char    *buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = malloc(sizeof(char) * (BUFFER_SIZE));
        if (!buf)
            return (NULL);
    while (!ft_strchr(temp, '\n')) 
    {    
        r = (read(fd, buf, BUFFER_SIZE));	
            if (r <= 0)
                return NULL;
    temp2 = malloc(sizeof(char) * (BUFFER_SIZE));
        if (!temp2)
            return NULL;
            temp2 = temp;
            j = ft_strlen(temp2);
            temp = strjoin(temp2, buf, j);
            free (temp2);
    }
    return(temp2);
}
char	*get_next_line(int fd)
{
    char    *ret;
    static char *temp;
    ret = (read_save(fd, temp));

    return(ret);
}
