/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:21 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/15 11:50:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			get_y(int fd, t_coord *map)
{
	int		y;
	int		i;
	char	buff[1];

	y = 0;
	while ((i = read(fd, buff, 1) == 1))
	{
		if (buff[0] == '\n')
			y++;
	}
	close(fd);
	map->y = y;
}

static void		get_x(int fd, t_coord *map)
{
	int		x;
	int		i;
	int		flag;
	char	buf[1];

	x = 0;
	flag = 0;
	while ((i = read(fd, buf, 1) == 1))
	{
		if (!flag && buf[0] != '\n' && buf[0] != ' ')
		{
			x++;
			flag = 1;
		}
		if (flag == 1 && buf[0] == ' ')
			flag = 0;
		if (buf[0] == '\n')
			break ;
	}
	close(fd);
	map->x = x;
}

static void		get_coord(int fd, t_coord *map)
{
	int		i;
	int		j;
	char	*line;
	char	**arr;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		arr = ft_strsplit(line, ' ');
		j = 0;
		ft_memdel((void**)&line);
		while (arr[j])
		{
			map->z_matrix[i][j] = ft_atoi(arr[j]);
			free(arr[j]);
			j++;
		}
		ft_memdel((void**)&arr);
		i++;
	}
	close(fd);
}

void			set_initial(t_coord *map)
{
	if (map->y > 40 || map->x > 40)
		map->zoom = 4;
	else
		map->zoom = 10;
	map->angle = 0.523599;
	map->depth = 1;
	map->mv_y = 200;
	map->mv_x = 400;
}

void			read_file(char *file, t_coord *data)
{
	int		i;
	int		fd;
	int		fd1;
	int		fd2;

	i = 0;
	fd = open(file, O_RDONLY, 0);
	get_y(fd, data);
	fd1 = open(file, O_RDONLY, 0);
	get_x(fd1, data);
	if (!(data->z_matrix = (int**)malloc(sizeof(int*) * (data->y + 1))))
		return ;
	while (i < data->y)
	{
		if (!(data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->x + 1))))
			return ;
	}
	fd2 = open(file, O_RDONLY, 0);
	get_coord(fd2, data);
	set_initial(data);
}
