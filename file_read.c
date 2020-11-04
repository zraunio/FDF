/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:21 by zraunio           #+#    #+#             */
/*   Updated: 2020/11/02 11:44:24 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_y(char *file)
{
	int		y;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	close(fd);
	return (y);
}

static int		get_x(char *file)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (x);
}

static void		get_z(int *z_matrix, char *line)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_strsplit(line, ' ');
	while (arr[i])
	{
		z_matrix[i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void			set_initial(t_coord *map)
{
	map->zoom = 10;
	map->angle = 0.8;
	map->depth = 1;
	map->mv_y = 200;
	map->mv_x = 200;
}

void			read_file(char *file, t_coord *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	data->y = get_y(file);
	data->x = get_x(file);
	if (!(data->z_matrix = (int**)malloc(sizeof(int*) * (data->y))))
		return ;
	while (i <= data->y)
		if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->x))))
			return ;
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		get_z(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	set_initial(data);
}
