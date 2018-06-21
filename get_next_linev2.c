/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/21 16:42:25 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>


int		get_next_line(const int fd, char **line)
{
	char		*buf;
	char		*temp;
	size_t		buffout;
	int			i = 0;

	while (buffout > 0)
	{
		buf = ft_strnew(BUFF_SIZE);
		buffout = read(fd, buf, BUFF_SIZE);
		temp = ft_strdup(buf);
		printf("buf %d is: \n%s\n",i ,temp);
		i++;
	}
	if (temp == NULL)
		return (0);
	return (1);
}

int		main(void)
{
	int		fd;
	int		strbuf;
	char	*line;
	int 	i = 0;

	fd = open("file.txt", O_RDONLY, 0700);
	if(fd == -1)
	{
		printf("Failed to create and open and read the file.\n");
		return (1);
	}
	while ((strbuf = get_next_line(fd, &line)) == 1 && i < 10)
	{
		//	printf("fd is:\n%d\n", fd);
		//	printf("return:\n%d\n", strbuf);
		i++;
	}
	close(fd);
	return 0;
}
