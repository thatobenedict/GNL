/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/26 18:58:10 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>

static size_t		new_line_ind(char *buf)
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
	recycle++;
	recycle = ft_strdup(recycle);
	return (recycle);
}
/*
   static size_t		ft_change_size(char *found)
   {
   size_t len;
   const char *str;

   str = ft_change(found);
   len = ft_strlen(str);
   return (len);
   }
   you're using a strdup now - probably will delete*/
int		get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*keep;
	size_t		buffout;

	if (keep == NULL)
		keep = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	while ((buffout = read(fd, buf, BUFF_SIZE)) > 0)
	{
		keep = ft_strjoin(keep, buf);
		if (ft_contain_char(keep, '\n'))
			break ;
	}
	*line = ft_strsub(keep, 0, new_line_ind(keep));
	keep = ft_change(keep);
	if (*keep == 0 && buffout == 0)
		return (READ_COMPLETE);
	return (READ_SUCCESS);
}
/*
int		main(void)
{
	int		fd;
	int		strbuf;
	char	*line;

	fd = open("file.txt", O_RDONLY, 0700);
	if(fd == -1)
	{
		printf("Failed to create and open and read the file.\n");
		return (1);
	}
	strbuf = get_next_line(fd, &line);
		printf("%s", line);
	strbuf = get_next_line(fd, &line);
	printf("%s", line);
	close(fd);
	return 0;

}*/
