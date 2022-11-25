/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:29 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/25 12:10:14 by pbunaciu         ###   ########.fr       */
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
	copy = (char *)malloc(sizeof(char) * len);
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
