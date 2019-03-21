/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:34:07 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/14 16:53:10 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ligne(int xi, int yi, int xf, int yf, t_3d *d)
{
	int dx, dy, i, xinc, yinc, cumul, x, y;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(MLXPTR, WINPTR, x, y, BLUE);
	if (dx > dy)
	{
		cumul = dx / 2;
		for (i = 1; i <= dx; i++)
		{
	  		x += xinc;
	  		cumul += dy;
	  		if (cumul >= dx)
			{
	    		cumul -= dx;
	    		y += yinc;
			}
			mlx_pixel_put(MLXPTR, WINPTR, x, y, RED);
		}
	}
	else
	{
		cumul = dy / 2;
		for (i = 1; i <= dy; i++)
		{
	  		y += yinc;
	  		cumul += dx;
	  		if (cumul >= dy)
	  		{
	    	cumul -= dy;
	    	x += xinc;
			}
			mlx_pixel_put(MLXPTR, WINPTR, x, y, RED);
		}
	}
}

/*
** ft_bresenham1 => x1 < x2 && y1 < y2
*/

void		ft_bresenham1(t_3d *d)
{

	d->tata.x1 = d->j;
	d->tata.x2 = ((d->j + 1) * SPACEX);
	d->tata.y1 = d->i;
	d->tata.y2 = ((d->i + 1) * SPACEX);
	d->tata.e = fabs((float)d->tata.x2 - (float)d->tata.x1);
	d->tata.dx = 2 * d->tata.e;
	d->tata.dy = 2 * fabs((float)d->tata.y2 - (float)d->tata.y1);
	while (d->tata.x1 <= d->tata.x2)
	{
		IMGDATA[d->tata.y1 * WIDTH + d->tata.x1] = YELLOW;
		d->tata.x1++;
		d->tata.e -= d->tata.dy;
		if (d->tata.e < 0)
		{
			d->tata.y1++;
			d->tata.e += d->tata.dx;
		}
	}
}

/*
** ft_bresenham2 => x1 > x2 && y1 < y2
*/

void		ft_bresenham2(t_3d *d)
{
	t_data	tata;

	tata.x1 = 100;
	tata.x2 = 215;
	tata.y1 = 100;
	tata.y2 = 50;
	tata.e = fabs((float)tata.x2 - (float)tata.x1);
	tata.dx = 2 * tata.e;
	tata.dy = 2 * fabs((float)tata.y2 - (float)tata.y1);
	while (tata.x1 >= tata.x2)
	{
		mlx_pixel_put(MLXPTR, WINPTR, tata.x1, tata.y1, YELLOW);
		tata.x1--;
		tata.e -= tata.dy;
		if (tata.e < 0)
		{
			tata.y1++;
			tata.e += tata.dx;
		}
	}
}

/*
** ft_bresenham3 => x1 > x2 && y1 > y2
*/

void		ft_bresenham3(t_3d *d)
{
	t_data	tata;

	tata.x1 = 500;
	tata.x2 = 000;
	tata.y1 = 800;
	tata.y2 = 000;
	tata.e = fabs((float)tata.x2 - (float)tata.x1);
	tata.dx = 2 * tata.e;
	tata.dy = 2 * fabs((float)tata.y2 - (float)tata.y1);
	while (tata.x1 >= tata.x2)
	{
		mlx_pixel_put(MLXPTR, WINPTR, tata.x1, tata.y1, BLUE);
		tata.x1--;
		tata.e -= tata.dy;
		if (tata.e < 0)
		{
			tata.y1--;
			tata.e += tata.dx;
		}
	}
}

/*
** ft_bresenham4 => x1 < x2 && y1 > y2
*/

void		ft_bresenham4(t_3d *d)
{
	t_data	tata;

	tata.x1 = 100;
	tata.x2 = 215;
	tata.y1 = 100;
	tata.y2 = 50;
	tata.e = fabs((float)tata.x2 - (float)tata.x1);
	tata.dx = 2 * tata.e;
	tata.dy = 2 * fabs((float)tata.y2 - (float)tata.y1);
	while (tata.x1 <= tata.x2)
	{
		mlx_pixel_put(MLXPTR, WINPTR, tata.x1, tata.y1, CYAN);
		tata.x1++;
		tata.e -= tata.dy;
		if (tata.e < 0)
		{
			tata.y1--;
			tata.e += tata.dx;
		}
	}
}

int	ft_abs(int i)
{
	return ((i < 0) ? (i *= -1) : (0));
}

void	ft_horizontal(t_abs_ord a, t_abs_ord b, t_3d *d, int color)
{
	int xinc;
	int yinc;
	int cumul;
	int i;

	xinc = (b.x > 0) ? 1 : -1;
	yinc = (b.y > 0) ? 1 : -1;
	b.x = ft_abs(b.x);
	b.y = ft_abs(b.y);
	cumul = b.y / 2;
	i = 0;
	while (i <= b.y)
	{
		if ((a.x >= 0 && a.x < WIDTH) && (a.y >= 0 && a.y < HEIGHT))
			ft_pixel_put(d, a, color);
		cumul += b.x;
		if (cumul >= b.y)
		{
			cumul -= b.y;
			a.x += xinc;
		}
		a.y += yinc;
		i++;
	}
}

void	ft_vertical(t_abs_ord a, t_abs_ord b, t_3d *d, int color)
{
	int xinc;
	int yinc;
	int cumul;
	int i;

	xinc = (b.x > 0) ? 1 : -1;
	yinc = (b.y > 0) ? 1 : -1;
	b.x = ft_abs(b.x);
	b.y = ft_abs(b.y);
	cumul = b.x / 2;
	i = 0;
	while (i <= b.x)
	{
		if ((a.x >= 0 && a.x < WIDTH) && (a.y >= 0 && a.y < HEIGHT))
			ft_pixel_put(d, a, color);
		cumul += b.y;
		if (cumul >= b.x)
		{
			cumul -= b.x;
			a.y += yinc;
		}
		a.x += xinc;
		i++;
	}
}

void		ft_bresenham(t_3d *d, t_abs_ord a, t_abs_ord b, int color)
{
	b.x = b.x - a.x;
	b.y = b.y - a.y;
	if (ft_abs(b.x) > ft_abs(b.y))
		ft_vertical(a, b, d, color);
	else
		ft_horizontal(a, b, d, color);
}

void	ft_pixel_put(t_3d *d, t_abs_ord pos, int color)
{
	int i;

	if (!(pos.x <= WIDTH && pos.x >= 0 && pos.y <= HEIGHT && pos.y >= 0))
		return ((void)NULL);
	i = d->size_line * pos.y + (pos.x * (d->bpp / 8));
	d->pxl[i] = (char)color;
	d->pxl[i + 1] = (char)(color >> 8);
	d->pxl[i + 2] = (char)(color >> 16);
}
