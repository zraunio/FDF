/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:28 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/07 14:46:36 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	return (key == 61 || key == 45 || key == 97 || key == 115 ||\
	key == 122 || key == 120 || key == 65362 || key == 65363 ||\
	key == 65364 || key == 65361 || key == 65307 || key == 32);
}

int		map_op(int key, t_coord *map)
{
	if (key == 65307)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(1);
	}
	if (key == 32)
	{
		if (map->view == 1)
			map->view = 0;
		else
			map->view = 1;
	}
	if (key == 61)
		map->zoom += 5;
	if (key == 45)
		map->zoom -= 5;
	if (key == 97)
		map->angle += 0.2;
	if (key == 115)
		map->angle -= 0.2;
	if (key == 122)
	{
		if (map->depth == 0)
			map->depth = 1;
		map->depth *= 2;
	}
	if (key == 120)
		map->depth /= 2;
	if (key == 65362) //nb is up
		map->mv_y -= 15;
	if (key == 65364) // down
		map->mv_y += 15;
	if (key == 65361) //left
		map->mv_x -= 15;
	if (key == 65363) //right
		map->mv_x += 15;
	return (0);
}

int		handle_keys(int key, t_coord *map)
{
	if (is_key(key))
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		map_op(key, map);
		draw_map(map);
	}
	print_text(map);
	return (0);
}
