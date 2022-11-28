/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:29 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/28 16:54:47 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char	*ft_strdup(const char *s1)
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
	copy[i] = '\0';
	return (copy);
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

char	*strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
    size_t  len;

	i = 0;
	j = 0;
    len = ft_strlen(s1) + ft_strlen(s2);
    if (!s1 || !s2)
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
    new[len] = 0;
    free (s1);
    return (new);
}
size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
    return (i);
}
