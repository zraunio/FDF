/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:28 by zraunio           #+#    #+#             */
/*   Updated: 2020/11/02 11:44:29 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		win_zoom(int key, t_coord *map)
{
	if (key == 69)
		map->zoom += 5;
	if (key == 78)
		map->zoom -= 5;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw_map(map);
	return (0);
}

int		map_shift(int key, t_coord *map)
{
	if (key == 116)
		map->angle += 0.2;
	if (key == 121)
		map->angle -= 0.2;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw_map(map);
	return (0);
}

int		depth_change(int key, t_coord *map)
{
	if (map->depth == 0)
		map->depth = 1;
	if (key == 91)
		map->depth *= 2;
	if (key == 84)
		map->depth /= 2;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw_map(map);
	return (0);
}

int		map_move(int key, t_coord *map)
{
	if (key == 126)
		map->mv_y -= 15;
	if (key == 125)
		map->mv_y += 15;
	if (key == 123)
		map->mv_x -= 15;
	if (key == 124)
		map->mv_x += 15;
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw_map(map);
	return (0);
}

int		handle_keys(int key, t_coord *map)
{
	if (key == 116 || key == 121)
		map_shift(key, map);
	if (key == 69 || key == 78)
		win_zoom(key, map);
	if (key == 84 || key == 91)
		depth_change(key, map);
	win_close(key, map);
	if (key >= 123 && key <= 126)
		map_move(key, map);
	print_text(map);
	return (0);
}
