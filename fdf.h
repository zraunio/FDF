/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zraunio <zraunio@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:43:32 by zraunio           #+#    #+#             */
/*   Updated: 2020/11/02 11:44:16 by zraunio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define MAX1(a, b) (a > b ? a : b)

typedef struct	s_coord
{
	int			y;
	int			x;
	int			**z_matrix;
	float		x_x;
	float		y_y;
	float		x_gap;
	float		y_gap;
	int			mv_y;
	int			mv_x;
	int			colour;
	double		angle;
	int			depth;
	int			zoom;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_coord;

void			read_file(char *file, t_coord *data);
void			draw_map(t_coord *map);
int				handle_keys(int key, t_coord *map);
void			draw_line(float x, float y, t_coord *map);
void			print_text(t_coord *map);
int				draw_colour(int z, int zz, t_coord *map);
int				win_close(int key, t_coord *map);

#endif

/*
** y is the vertical axis (height), x is the horizontal(width),
** while z is depth data
*/
