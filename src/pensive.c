/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pensive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:36:04 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/14 11:43:28 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
** (position X * 4 + 4 * Taille de la ligne * position Y)
**
** isoX = cartX - cartY;
** isoY = (cartX + cartY) / 2;
** ((WIDTH / 2) - (800 / 2))
** ((HEIGHT / 2) - (600 / 2))
**			x = d->j - d->i;
**			y = (d->j + d->i) / 2;
*/

/*
** midx = ((WIDTH / 2) - (d->max.x / 2));
** midy = ((HEIGHT / 2) - (d->max.y / 2));
*/

/*
** screen.x = (x - y) * SPACEX; // equals 64
** screen.y = (x + y) * (SPACEX/2sp); // equals 96
*/

/*
** ((HEIGHT / 2) - ((d->max.y * SPACEX) / 2))
** ((WIDTH / 2) - ((d->max.x * SPACEX) / 2))
*/

int			draw_img(t_3d *d)
{
	int isoX;
	int isoY;

	d->i = -1;
	while (++d->i < d->max.y)
	{
		d->j = -1;
		while (++d->j < d->max.x)
		{
			isoX = (((d->j - d->i) * SPACEX) + (WIDTH / 2.5));
			isoY = (((d->j + d->i) * (SPACEX / 2)) + (HEIGHT / 5));
			//mlx_pixel_put(MLXPTR, IMGPTR, (isoX), ((isoY)), RED);
			IMGDATA[(isoY * WIDTH + isoX)] = GREEN;
		//	ft_bresenham1(env, d);
		//	ligne(isoX, isoY, isoX + 1, isoY + 1, env);
			//ligne(d->j, d->i, ((d->j + 1) * SPACEX), ((d->i) * SPACEX), env);
		}
	}
	return (0);
}














/*
** while (x <= xmax || y <= ymax)
** 	if (x < xmax - 1)
**  		bresenham (y++ et x++)
** 	if (y < ymax - 1)
** 		bresenham (y++ et x--)
** 	if (x < xmax - 1)
** 		bresenham (y++ et x--)
*/
