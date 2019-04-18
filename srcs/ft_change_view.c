/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:05:29 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 12:58:53 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_iso(t_data *data)
{
	if (data->iso == FALSE)
	{
		data->parallel = FALSE;
		data->iso = TRUE;
		ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
		store_prev_pos(data);
		mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
		init_commands(data);
	}
}

void		ft_parallel(t_data *data)
{
	data->parallel = TRUE;
	data->iso = FALSE;
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}

void		iso(int *x, int *y, t_data *data, t_cmpt *c)
{
	int		previous_x;
	int		previous_y;
	int		z;

	z = ((double)(data->array[c->i][c->j].z * data->zoom) * data->z);
	previous_x = *x;
	previous_y = *y;
	*x = ((previous_x - previous_y) * cos(0.523599)) + (ORIGINX * 2.5);
	*y = ((previous_x + previous_y) * sin(0.523599)) - z - (ORIGINY / 2.5);
}
