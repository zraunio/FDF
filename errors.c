/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:43:32 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/07 14:14:19 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		error_content(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		i = 0;
		while(line[i])
		{
			if (ft_isdigit(line[i]) || ft_isspace(line[i]) ||
			line[i] == '-')
				i++;
			else
			{
				write(1, \
			"File contains invlaid characters.\n",\
			34);
			free(line);
			return (1);
			}
		}
		free(line);
	}
	close(fd);
	return (0);
}

static int		error_open(char *file)
{
	int		fd;
	char	*line;


	if  ((fd = open(file, O_RDONLY, 0)) == -1 || (fd = open(file, O_RDONLY, 0)) == 0)
	{
		write(1, \
		"File doesn't exist or you don't have the right permissions.\n",\
		60);
		return (2);
	}
	else if (get_next_line(fd, &line) == -1)
	{
		write(1, \
		"You've probably tried to open a directory. Check the name and \
try again.\n\
usage: ./fdf [file name]\n",
		98);
		free(line);
		return (1);
	}
	close(fd);
	return (0);
}

/*
** error_open return 1 for directory, 
** 2 for RDONLY error
** 0 otherwise
*/

int			error_map(char *file)
{
	if (error_open(file) == 0 && error_content(file) == 0)
		return (0);
	else
		exit (1);
}
