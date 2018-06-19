/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/19 17:58:16 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>


char	*ft_analyse(int fd)
{
	char 	*buf;
	char	*temp;
	size_t	buffout;

	buf = ft_strnew(BUFF_SIZE);
 	buffout = read(fd, buf, BUFF_SIZE);
	buf[BUFF_SIZE] = '\0';

	temp = ft_strchr(buf, '\n');

	return (temp);
}
/*
int		get_next_line(const int fd, char **line)
{

}
*/
int		main(void)
{
	int		fd;
	char	*strbuf;

	fd = open("file.txt", O_RDONLY, 0700);
	if(fd == -1)
	{
		printf("Failed to create and open and read the file.\n");
		return (1);
	}
	strbuf = ft_analyse(fd);	
	printf("%d\n", ft_strlen(strbuf));
	printf("buf is: \n%s\n", strbuf);
	close(fd);
	return 0;
}
