/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:48:13 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/19 17:23:05 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				smlx_init(t_3d *d, char *title)
{
	MLXPTR = mlx_init();
	WINPTR = mlx_new_window(MLXPTR, WIDTH, HEIGHT, title);
	IMGPTR = mlx_new_image(MLXPTR, WIDTH, HEIGHT);
	mlx_key_hook(WINPTR, deal_key, d);
	//IMGDATA = mlx_get_data_addr(IMGPTR, &d->bpp, &d->size_line, &d->endian);
	draw_img(d);
	create_grid(d);
	//mlx_put_image_to_window(MLXPTR, WINPTR, IMGPTR, 0, 0);
	ft_help_command(d);
	mlx_hook(WINPTR, 17, 1L << 17, deal_mouse, d);
	mlx_loop(MLXPTR);
	return (0);
}
