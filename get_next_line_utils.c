/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:29 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/29 12:54:22 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*copy;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
//	copy[len] = '\0';
	return (copy);
}
char	*ft_strchr(char *s, int c)
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

char	*strjoin(char *s1, char *s2)
{
	char	*new;
	int 	i;
	int 	j;
    int     len;

	i = 0;
	j = 0;
    len = ft_strlen(s1) + ft_strlen(s2);
    if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
    {
        new[i] = s1[i];
        i++;
    }
    while (s2 && s2[j] != '\0')
		new[i++] = s2[j++];
    new[len] = '\0';
    //ree (s2);
    //s1 = NULL;
    //free (s2);
    //s2 = NULL;
    return (new);
}
size_t	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
    return (i);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((size_t)-1 / count < size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*p = '\0';
		n--;
		p++;
	}
}
