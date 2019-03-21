/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:50:27 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/14 16:56:53 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_help_command(t_3d *d)
{
	mlx_string_put(MLXPTR, WINPTR, 15, 10, GREEN, "HAUT   --> W");
	mlx_string_put(MLXPTR, WINPTR, 15, 25, GREEN, "BAS    --> S");
	mlx_string_put(MLXPTR, WINPTR, 15, 40, GREEN, "GAUCHE --> A");
	mlx_string_put(MLXPTR, WINPTR, 15, 55, GREEN, "DROITE --> D");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 150), 10, GREEN, "ZOOM + --> +");
	mlx_string_put(MLXPTR, WINPTR, (WIDTH - 150), 25, GREEN, "ZOOM - --> -");
	mlx_string_put(MLXPTR, WINPTR, 15, (HEIGHT - 30), GREEN, "CLOSE  --> ESC");
}

int			deal_key(int key, t_3d *d)
{
	if (key == 53)
	{
		mlx_destroy_image(MLXPTR, IMGPTR);
		mlx_destroy_window(MLXPTR, WINPTR);
		exit(0);
	}
	return (key);
}

int			deal_mouse(t_3d *d)
{
	mlx_destroy_image(MLXPTR, IMGPTR);
	mlx_destroy_window(MLXPTR, WINPTR);
	exit(0);
	return (0);
}

/*
** idee:
**
** tableau[0] = ft_haut
** tableau[1] = ft_bas
** tableau[2] = ft_gauche
** tableau[3] = ft_droite
** tableau[4] = ft_zoom_plus
** tableau[5] = ft_zoom_moins
** tableau[6] = ft_escape
*/
