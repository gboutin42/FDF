/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_zoom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:02:18 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 11:38:43 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			ft_zoom_on(t_data *data)
{
	data->zoom += 0.02;
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}

void			ft_zoom_off(t_data *data)
{
	if ((SPACE * data->zoom) > 0.1 && (SPACE * (data->zoom - 0.02)) > 0.1)
		data->zoom -= 0.02;
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}
