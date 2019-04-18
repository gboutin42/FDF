/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:21:39 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/18 08:41:02 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int ac, char **av)
{
	t_data	data;
	char	title[250];
	int		i;
	int		j;

	if (ac != 2)
		return (ft_error("Usage: ./fdf [File]", 0));
	if ((data.fd = open(av[1], O_RDONLY)) == -1)
		return (ft_error("Could not open file", 0));
	axe_y(&data);
	parse_map(&data, av[1]);
	i = -1;
	j = -1;
	while (av[1][++i] != '\0')
	{
		if (av[1][i] == '/')
		{
			j = -1;
			i++;
		}
		title[++j] = av[1][i];
	}
	smlx_init(&data, title);
	return (0);
}

void		free_array(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
