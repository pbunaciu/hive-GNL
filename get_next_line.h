/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:57:21 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/29 12:11:22 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char    *ft_strdup(char *s1);
size_t  ft_strlen(char *str);
char    *strjoin(char *s1, char *s2);
char    *ft_strchr(char *s, int c);
char    *read_save(int fd, char *temp);
char    *find_newline(char *stash);
char    *find_nextline(char *stash);
char    *join_free(char *stash, char *buf);
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void *s, size_t n);
#endif
