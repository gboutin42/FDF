/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_prev_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:46:34 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 13:08:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		storing_prev(t_data *data, t_coor *cur, t_coor *prev, t_cmpt *c)
{
	cur->y = (SPACE * (double)(DATA.y * data->zoom)) + ORIGINY;
	cur->x = (SPACE * (double)(DATA.x * data->zoom)) + ORIGINX;
	if (data->iso == TRUE)
		iso(&cur->x, &cur->y, data, c);
	else if (data->parallel == TRUE)
	{
		cur->y -= ((double)(DATA.z * data->zoom) * data->z);
		cur->x += ((double)(DATA.z * data->zoom) * data->z);
	}
	if (DATA.color > 0)
		cur->color = DATA.color;
	else
	{
		if (DATA.z < 0)
			cur->color = GREEN;
		else if (DATA.z > 8)
			cur->color = CYAN;
		else
			cur->color = YELLOW;
	}
	if (prev->y != 0 && prev->x != 0)
		ft_draw_line(cur, prev, cur->color, data);
	prev->y = cur->y;
	prev->x = cur->x;
}

void			store_prev_pos(t_data *data)
{
	t_cmpt		c;
	t_coor		current;
	t_coor		previous;

	c.j = -1;
	current.color = CYAN;
	previous.x = 0;
	while (++c.j < data->tabsize.x)
	{
		c.i = -1;
		previous.y = 0;
		while (++c.i < data->tabsize.y)
			storing_prev(data, &current, &previous, &c);
	}
	store_prev_pos2(data);
}

void			store_prev_pos2(t_data *data)
{
	t_cmpt		c;
	t_coor		current;
	t_coor		previous;

	current.color = CYAN;
	c.i = -1;
	previous.y = 0;
	while (++c.i < data->tabsize.y)
	{
		c.j = -1;
		previous.x = 0;
		while (++c.j < data->tabsize.x)
			storing_prev(data, &current, &previous, &c);
	}
}
