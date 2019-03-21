/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:21:43 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/14 16:56:05 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		draw_line(t_3d *d, t_abs_ord start, t_abs_ord coor, char dir)
{
	t_abs_ord	next;
	int			color;
	int			height1;
	int			height2;

	color = 0x5a8ee2;
	height1 = d->array[coor.y][coor.x - 1];
	if (dir == 'y')
	{
		height2 = d->array[coor.y + 1][coor.x - 1];
		next.x = start.x;
		next.y = start.y + d->s.x;
	}
	else if (dir == 'x')
	{
		height2 = d->array[coor.y][coor.x];
		next.x = start.x + d->s.x;
		next.y = start.y;
	}
	else
		return ((void)NULL);
	//color = pick_color(height1, height2);
	ft_bresenham(d, start, next, color);
}

void		create_grid(t_3d *d)
{
	t_abs_ord	start;
	t_abs_ord	coor;

	coor.y = 0;
	start.y = d->s.y;
	while (coor.y < d->max.y)
	{
		coor.x = 0;
		start.x = d->s.x;
		while (coor.x < d->max.x)
		{
			start.x += SPACEX;
			coor.x++;
			if (coor.x < d->max.x)
				draw_line(d, start, coor, 'x');
			if (coor.y < d->max.y - 1)
				draw_line(d, start, coor, 'y');
		}
		coor.y++;
		start.y += SPACEX;
	}
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
}
