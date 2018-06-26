/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/21 16:12:56 by tbenedic         ###   ########.fr       */
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
	static int	i;
	static int	j;


	buf = ft_strnew(BUFF_SIZE);
	while (buffout > 0)
	{
		buffout = read(fd, buf, BUFF_SIZE);
		j = i;
		while (buf[i] != '\0' && buf[i] != '\n')
			i++;
		temp = ft_strsub(buf, j, i - j);
		printf("buf is: \n%s\n", temp);
	}
	if (temp == NULL)
		return (0);
	return (1);
}

int		main(void)
{
	int		fd;
	int		strbuf;
	//	char	*strbuf;
	char	*line;
	int i = 0;

	fd = open("file.txt", O_RDONLY, 0700);
	if(fd == -1)
	{
		printf("Failed to create and open and read the file.\n");
		return (1);
	}
	while ((strbuf = get_next_line(fd, &line)) == 1 && i < 5 )
	{
		//	printf("fd is:\n%d\n", fd);
		//	printf("return:\n%d\n", strbuf);
		i++;
	}
	close(fd);
	return 0;
}
