/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:10 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/14 14:51:13 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_dimentions(float *x, float *y, int z, t_coord *map)
{
	int a;
	int b;

	a = (*x - *y) * cos(map->angle);
	b = (*x + *y) * sin(map->angle) - z;
	*x = a;
	*y = b;
}

int		get_depth(float x, float y, t_coord *map)
{
	int		z;

	z = map->z_matrix[(int)y][(int)x];
	z *= map->depth;
	z *= map->zoom;
	return (z);
}

void	gap_calc(float x, float y, t_coord *map)
{
	int		i;

	map->x_gap = map->x_x - x;
	map->y_gap = map->y_y - y;
	i = MAX1(ft_float_abs(map->x_gap), ft_float_abs(map->y_gap));
	map->x_gap /= i;
	map->y_gap /= i;
}

void	draw_line(float x, float y, t_coord *map)
{
	int		z;
	int		z_z;

	z = get_depth(x, y, map);
	z_z = get_depth(map->x_x, map->y_y, map);
	x *= map->zoom;
	y *= map->zoom;
	map->x_x *= map->zoom;
	map->y_y *= map->zoom;
	draw_dimentions(&x, &y, z, map);
	draw_dimentions(&map->x_x, &map->y_y, z_z, map);
	x += map->mv_x;
	y += map->mv_y;
	map->x_x += map->mv_x;
	map->y_y += map->mv_y;
	gap_calc(x, y, map);
	while ((int)(x - map->x_x) || (int)(y - map->y_y))
	{
		map->colour = draw_colour(z, z_z);
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->colour);
		x += map->x_gap;
		y += map->y_gap;
	}
}

void	draw_map(t_coord *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (x < map->x - 1)
			{
				map->x_x = x + 1;
				map->y_y = y;
				draw_line(x, y, map);
			}
			if (y < map->y - 1)
			{
				map->y_y = y + 1;
				map->x_x = x;
				draw_line(x, y, map);
			}
			x++;
		}
		y++;
	}
}
