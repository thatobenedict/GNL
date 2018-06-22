/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/22 18:28:45 by tbenedic         ###   ########.fr       */
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

/*
int		main(void)
{
	char str[] = "hello this is a test\non how to read in a file.\nNext, we will work on deliminating the reading \
\ninto chunks of a new line.";
	printf("%zu", read_line(str));
	return (0);

}
*/

int		get_next_line(const int fd, char **line)
{
	char	*buf;
	char	*temp;
	size_t	buffout;
	int		i = 0;
	size_t	j;

	temp = "";	
	buf = ft_strnew(BUFF_SIZE);
	while (BUFF_SIZE > 0 && i < 10)
	{
		buf = ft_strnew(BUFF_SIZE);
		buffout = read(fd, buf, BUFF_SIZE);
		if (ft_contain_char(buf, '\n') == 0)
			temp = ft_strnjoin(temp, buf, BUFF_SIZE);
		else
		{
			temp = ft_strnjoin(temp, buf, read_line(buf));
			return (READ_SUCCESS);

		}
		printf("buf %d is: \n%s\n",i ,temp);
		i++; //for the print out
	}
	if (temp == NULL)
		return (READ_ERROR);
	return (READ_SUCCESS);
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


	while ((strbuf = get_next_line(fd, &line)) == 1 || i < 5)
	{
		//	printf("fd is:\n%d\n", fd);
		//	printf("return:\n%d\n", strbuf);
		i++;
	}
	close(fd);
	return 0;
	
}
