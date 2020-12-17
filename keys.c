/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:28 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/14 11:42:18 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_key(int key)
{
	return (key == 126 || key == 125 || key == 124 || key == 123 ||\
	key == 7 || key == 6 || key == 1 || key == 0 ||\
	key == 27 || key == 24 || key == 49 || key == 53);
}

int		map_op(int key, t_coord *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(1);
	}
	if (key == 49)
	{
		if (map->angle == 0.7862975)
			map->angle = 0.523599;
		else if (map->angle == 0.523599)
			map->angle = 0;
		else
			map->angle = 0.7862975;
	}
	if (key == 24)
		map->zoom += 5;
	if (key == 27)
		map->zoom -= 5;
	if (key == 0)
		map->angle += 0.2;
	if (key == 1)
		map->angle -= 0.2;
	return (0);
}

int		map_op2(int key, t_coord *map)
{
	if (key == 6)
	{
		if (map->depth == 0)
			map->depth = 1;
		map->depth *= 2;
	}
	if (key == 7)
		map->depth /= 2;
	if (key == 126)
		map->mv_y -= 15;
	if (key == 125)
		map->mv_y += 15;
	if (key == 123)
		map->mv_x -= 15;
	if (key == 124)
		map->mv_x += 15;
	return (0);
}

/*
** 124 is up, 125) down
** 123 left,  124) right
*/

int		handle_keys(int key, t_coord *map)
{
	if (is_key(key))
	{
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		map_op(key, map);
		map_op2(key, map);
		draw_map(map);
	}
	print_text(map);
	return (0);
}
