/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:44:34 by zraunio           #+#    #+#             */
/*   Updated: 2020/11/02 11:44:35 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		win_close(int key, t_coord *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(1);
	}
	return (0);
}

void	print_text(t_coord *map)
{
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 5, 0xe9cf67, \
	"move: arrows");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 25, 0xe9cf67, "depth: 8/2");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 45, 0xe9cf67, "zoom: +/-");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 5, 65, 0xe9cf67, \
	"twirl: pageup/pagedown");
}

int		draw_colour(int z, int zz, t_coord *map)
{
	map->colour = (z || zz) ? 0x9400D3 : 0xe6be79;
	return (map->colour);
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
	int			fd;

	if (argc == 1 || argc > 2)
	{
		write(1, "usage: ./fdf [file name]\n", 25);
	}
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
		{
			write(1, \
			"File doesn't exist or you don't have the right permissions.\n",\
			60);
			return (0);
		}
		if (!valid_file(argv[1]))
		{
			ft_putendl("Invalid input.");
			return (0);
		}
		if (!(map = (t_coord*)malloc(sizeof(t_coord))))
			return (0);
		read_file(argv[1], map);
		do_mlx(map);
		free(map);
	}
	return (0);
}
