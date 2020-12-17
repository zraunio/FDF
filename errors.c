/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:43:32 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/14 15:12:42 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		error_content(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (ft_isdigit(line[i]) || ft_isspace(line[i]) || line[i] == '-')
				i++;
			else
			{
				write(1, "File contains invlaid characters.\n", 34);
				ft_memdel((void**)&line);
				return (1);
			}
		}
		ft_memdel((void**)&line);
	}
	line = NULL;
	close(fd);
	return (0);
}

static int		error_open(char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY, 0)) == -1 ||
	(fd = open(file, O_RDONLY, 0)) == 0)
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
		ft_memdel((void**)&line);
		return (1);
	}
	ft_memdel((void**)&line);
	line = NULL;
	close(fd);
	return (0);
}

/*
** error_open return 1 for directory,
** 2 for RDONLY error
** 0 otherwise
*/

int				error_map(char *file)
{
	if (error_open(file) == 0 && error_content(file) == 0)
		return (0);
	else
		exit(1);
}
