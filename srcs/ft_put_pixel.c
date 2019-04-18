/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:55:38 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/15 10:47:53 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_put_pixel(t_data *data, t_bresenham *cur, int color)
{
	int pixel;

	if (IMGDATA && cur->pos.x < WIDTH && cur->pos.x >= 0
		&& cur->pos.y < HEIGHT && cur->pos.y >= 0)
	{
		pixel = (cur->pos.y * data->size_ln) + (cur->pos.x * (data->bpp / 8));
		IMGDATA[pixel] = (char)color;
		IMGDATA[pixel + 1] = (char)(color >> 8);
		IMGDATA[pixel + 2] = (char)(color >> 16);
	}
}
