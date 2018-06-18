/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/18 16:14:56 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>


const int	in_line(char **line, )
{



}
/*
int get_next_line(const int fd, char **line)
{


}
*/
int		main(void)
{
	int fd;
	char buff[BUFF_SIZE + 1];
	size_t bufout;

	fd = open("file.txt", O_RDONLY);
	if(fd == -1)
	{
		printf("Failed to create and open and read the file.\n");
		return (1);
	}

	file_des()
 	bufout = read(fd, buff, BUFF_SIZE);
	buff[BUFF_SIZE] = '\0';

	printf("%d\n", ft_strlen(buff));
	printf("%zu\n", bufout);
	printf("buf is: \n%s\n", buff);
	close(fd);
	return 0;
}
