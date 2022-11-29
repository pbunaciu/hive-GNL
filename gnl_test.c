/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbunaciu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:24:00 by pbunaciu          #+#    #+#             */
/*   Updated: 2022/11/29 12:41:09 by pbunaciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int i = 1;
    char    *file;
    int fd;


    fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY);
     
    while(i < 20)
      {
        file = get_next_line(fd);
        printf("%s", file);
        i++;
        }
return (0);
}

