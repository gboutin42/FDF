/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:58:52 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 11:34:09 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			ft_translate_up(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->tabsize.y)
	{
		j = -1;
		while (++j < data->tabsize.x)
			data->array[i][j].y--;
	}
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}

void			ft_translate_left(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->tabsize.y)
	{
		j = -1;
		while (++j < data->tabsize.x)
			data->array[i][j].x--;
	}
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}

void			ft_translate_down(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->tabsize.y)
	{
		j = -1;
		while (++j < data->tabsize.x)
			data->array[i][j].y++;
	}
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}

void			ft_translate_right(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->tabsize.y)
	{
		j = -1;
		while (++j < data->tabsize.x)
			data->array[i][j].x++;
	}
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}
