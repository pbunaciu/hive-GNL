/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:21 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/24 14:34:46 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//#ifndef BUFFER_SIZE
#// define BUFFER_SIZE 4096
# include <stdlib.h>
# include <unistd.h>
typedef	struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char    *ft_strdup(const char *s1);
size_t  ft_strlen(const char *str);
char    *strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);
char    *read_save(int fd, char *temp);
char    *find_newline(char *stash);
char    *find_nextline(char *stash);
char    *join_free(char *stash, char *buf);

#endif
