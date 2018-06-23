/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/23 15:58:58 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>

size_t		read_line(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] != '\n' && !buf)
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*temp;
	size_t		buffout;
	int			i = 0;

	temp = "";	
	buf = ft_strnew(BUFF_SIZE);
	while (/*BUFF_SIZE > 0 ||*/ i < 5)
	{
		printf("buf %d is: \n%s\n",i ,temp);
		buf = ft_strnew(BUFF_SIZE);
		buffout = read(fd, buf, BUFF_SIZE);
		if (ft_contain_char(buf, '\n') == 0)
			temp = ft_strnjoin(temp, buf, BUFF_SIZE);
		else
		{
			*line = ft_strnjoin(temp, buf, read_line(buf));
			*line = temp;
			printf("line is: \n%s\n", *line);
			return (READ_SUCCESS);
		}
		i++; //for the print out
	}
	if (temp == NULL)
		return (READ_ERROR);
	return (READ_COMPLETE);
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
	while ((strbuf = get_next_line(fd, &line)) == 0)
	{
		//	printf("fd is:\n%d\n", fd);
		//	printf("return:\n%d\n", strbuf);
		i++;
	}
	close(fd);
	return 0;

}
