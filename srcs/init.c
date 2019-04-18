/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:10:20 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 12:55:20 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			smlx_init(t_data *data, char *title)
{
	char	*str;

	str = "CHOOSE YOUR VIEW:    ISO    /    PARALLEL?";
	data->z = 1;
	data->zoom = 1;
	data->iso = FALSE;
	data->parallel = TRUE;
	init_size_screen(data);
	if (!(MLXPTR = mlx_init()))
		ft_exit("Problem mlx_init");
	if (!(WINPTR = mlx_new_window(MLXPTR, WIDTH, HEIGHT, title)))
		ft_exit("Problem mlx_new_window");
	if (!(IMGPTR = mlx_new_image(MLXPTR, WIDTH, HEIGHT)))
		ft_exit("Problem mlx_new_image");
	if (!(IMGDATA = mlx_get_data_addr(IMGPTR, &data->bpp, &data->size_ln,
		&data->end)))
		ft_exit("Problem mlx_get_data_addr");
	mlx_string_put(MLXPTR, WINPTR, MIDWIDTH - 210, MIDHEIGHT, GREEN, str);
	init_commands(data);
	mlx_loop(MLXPTR);
	return (0);
}

void		init_size_screen(t_data *data)
{
	WIDTH = data->tabsize.x * 50;
	HEIGHT = data->tabsize.y * 50;
	if (WIDTH > MAX_WIDTH)
		WIDTH = MAX_WIDTH;
	else if (WIDTH < MIN_WIDTH)
		WIDTH = MIN_WIDTH;
	if (HEIGHT > MAX_HEIGHT)
		HEIGHT = MAX_HEIGHT;
	else if (HEIGHT < MIN_HEIGHT)
		HEIGHT = MIN_HEIGHT;
}

void		init_commands(t_data *data)
{
	mlx_hook(WINPTR, 17, 1L << 17, deal_mouse, data);
	mlx_hook(WINPTR, 2, 0, deal_key, data);
	help_command(data);
}
