/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:34 by zraunio           #+#    #+#             */
/*   Updated: 2020/12/07 14:49:35 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_text(t_coord *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 15, 0xe9cf67, \
	"move: arrows");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 35, 0xe9cf67, "depth: z/x");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 55, 0xe9cf67, "zoom: +/-");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 75, 0xe9cf67, \
	"twirl: a/s");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 95, 0xe9cf67, \
	"switch projection: esc");
}

int		draw_colour(int z, int zz)
{
	return (z || zz) ? 0x9400D3 : 0xe6be79;
}

void	do_mlx(t_coord *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1200, 1200, "FDF");
	draw_map(map);
	print_text(map);
	mlx_key_hook(map->win_ptr, handle_keys, map);
	mlx_loop(map->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_coord		*map;

	if (argc == 1 || argc > 2)
	{
		write(1, "usage: ./fdf [file name]\n", 25);
	}
	else if (argc == 2)
	{
		error_map(argv[1]);
		if (!(map = (t_coord*)malloc(sizeof(t_coord))))
			return (0);
		read_file(argv[1], map);
		do_mlx(map);
		free(map);
	}
	return (0);
}
