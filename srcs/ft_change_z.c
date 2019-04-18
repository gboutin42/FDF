/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:14:52 by mcoadou           #+#    #+#             */
/*   Updated: 2019/04/17 11:35:51 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_decrease_z(t_data *data)
{
	data->z -= 1;
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}

void	ft_increase_z(t_data *data)
{
	data->z += 1;
	ft_bzero(IMGDATA, ((HEIGHT * WIDTH) * 4));
	store_prev_pos(data);
	mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	init_commands(data);
}
