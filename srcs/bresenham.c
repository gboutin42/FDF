/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:29:07 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 09:39:02 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_draw_line(t_coor *current, t_coor *prev, int color, t_data *data)
{
	t_bresenham	cur;
	int			i;

	cur.dx = ft_abs(prev->x - current->x);
	cur.dy = ft_abs(prev->y - current->y);
	if (current->x < prev->x)
		cur.xincr = 1;
	else
		cur.xincr = -1;
	if (current->y < prev->y)
		cur.yincr = 1;
	else
		cur.yincr = -1;
	cur.pos.x = current->x;
	cur.pos.y = current->y;
	i = -1;
	if (cur.dx > cur.dy)
		ft_draw_line2(&cur, data, color);
	else
		ft_draw_line3(&cur, data, color);
}

void	ft_draw_line2(t_bresenham *cur, t_data *data, int color)
{
	int	i;

	i = -1;
	cur->erreur = cur->dx / 2;
	while (++i < cur->dx)
	{
		cur->pos.x += cur->xincr;
		cur->erreur += cur->dy;
		if (cur->erreur > cur->dx)
		{
			cur->pos.y += cur->yincr;
			cur->erreur -= cur->dx;
		}
		if (cur->pos.y > -1 && cur->pos.x > -1)
			ft_put_pixel(data, cur, color);
	}
}

void	ft_draw_line3(t_bresenham *cur, t_data *data, int color)
{
	int i;

	i = -1;
	cur->erreur = cur->dy / 2;
	while (++i < cur->dy)
	{
		cur->pos.y += cur->yincr;
		cur->erreur += cur->dx;
		if (cur->erreur > cur->dy)
		{
			cur->pos.x += cur->xincr;
			cur->erreur -= cur->dy;
		}
		if (cur->pos.y > -1 && cur->pos.x > -1)
			ft_put_pixel(data, cur, color);
	}
}
