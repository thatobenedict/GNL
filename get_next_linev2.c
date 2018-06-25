/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/25 18:00:53 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>

static size_t		read_line(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

static char		*ft_change(char *line)
{
	char	*recycle;

	recycle = ft_strchr(line, '\n');
	return (recycle);
}

static size_t		ft_change_size(char *found)
{
	size_t len;
	const char *str;

   	str = ft_change(found);
	len = ft_strlen(str);
	return (len);
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*temp;
	size_t		buffout;
	int			i = 0;
	char		*test;

	temp = "";
	buf = ft_strnew(BUFF_SIZE);
	while (/*BUFF_SIZE > 0 ||*/ i < 5)
	{
		printf("buf %d is: \n%s\n",i ,temp);
		buf = ft_strnew(BUFF_SIZE);
		buffout = read(fd, buf, BUFF_SIZE);
		if (ft_contain_char(buf, '\n') == 0)
			temp = ft_strjoin(temp, buf);
		else
		{
			*line = ft_strnjoin(temp, buf, read_line(buf));
			printf("DELETE! The length of line is |%d|\n", ft_strlen(*line));
			printf("DELETE! The length of read_line(buf) is |%zu|\n", read_line(buf));
			printf("DELETE! (buf) is |%s|\n", buf);
			//*line = ft_strsub(*line, *line[0], read_line(*line));
			free(temp);
			test = ft_strnew(ft_change_size(*line));
			test = ft_change(*line);
			printf("line is: \n%s\n", *line);
			printf("test is: \n%s\n", test);
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
