/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:25:50 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/14 11:24:14 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				main(int ac, char **av)
{
	t_3d		d;

	if (ac != 2)
		return (ft_error("Usage: ./fdf [File]"));
	if ((d.fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file"));
	if (!(init_variable(&d, av[1]) == 1))
		return (ft_error("Init Variable is Failed"));
	if (!smlx_init(&d, av[1]))
		return (ft_error("Init of Window is Failed"));
	close(d.fd);
	return (0);
}
