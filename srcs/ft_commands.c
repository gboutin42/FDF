/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:33:01 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 12:50:03 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		help_command(t_data *data)
{
	mlx_string_put(MLXPTR, WINPTR, 15, 10, YELLOW, "HAUT   --> ^");
	mlx_string_put(MLXPTR, WINPTR, 15, 40, YELLOW, "GAUCHE --> <");
	mlx_string_put(MLXPTR, WINPTR, 15, 25, YELLOW, "BAS    --> v");
	mlx_string_put(MLXPTR, WINPTR, 15, 55, YELLOW, "DROITE --> >");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 150), 10, YELLOW, "ZOOM ON  --> +");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 150), 25, YELLOW, "ZOOM OFF --> -");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 150), 40, YELLOW, "ISO VIEW --> I");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 150), 55, YELLOW, "PAR VIEW --> P");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 140), (HEIGHT - 45), YELLOW, \
					"HIGHT Z --> H");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 140), (HEIGHT - 30), YELLOW, \
					"LOW   Z --> L");
	mlx_string_put(MLXPTR, WINPTR, 15, (HEIGHT - 30), YELLOW, \
					"CLOSE --> ESC or RED_CROSS");
}

int			deal_key(int key, t_data *data)
{
	void	(*array[145])(t_data *data);

	array[123] = ft_translate_left;
	array[124] = ft_translate_right;
	array[125] = ft_translate_down;
	array[126] = ft_translate_up;
	array[4] = ft_increase_z;
	array[37] = ft_decrease_z;
	array[69] = ft_zoom_on;
	array[78] = ft_zoom_off;
	array[53] = ft_close;
	array[34] = ft_iso;
	array[35] = ft_parallel;
	if (key == 4 || key == 37 || key == 34 || key == 35 || key == 53
		|| key == 69 || key == 78 || key == 123 || key == 124 || key == 125
		|| key == 126)
		(*array[key])(data);
	return (key);
}

int			deal_mouse(t_data *data)
{
	mlx_destroy_window(MLXPTR, WINPTR);
	exit(0);
	return (0);
}

void		ft_close(t_data *data)
{
	mlx_destroy_image(MLXPTR, IMGPTR);
	mlx_destroy_window(MLXPTR, WINPTR);
	exit(0);
}
