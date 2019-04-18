/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 09:03:28 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 13:08:37 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		fill_tab_coor(t_data *data, int i)
{
	int			j;

	j = -1;
	while (++j < data->tabsize.x && data->tmp[j] != NULL)
	{
		data->array[i][j].z = ft_atoi(data->tmp[j]);
		data->array[i][j].y = i;
		data->array[i][j].x = j;
		if (data->tmp[j][2] == '0' && data->tmp[j][3] == 'x')
			data->array[i][j].color = ft_strtol(data->tmp[j] + 2, 16);
	}
}

int				parse_map(t_data *data, char *file_desc)
{
	int			i;

	data->line = NULL;
	data->tmp = NULL;
	data->array = NULL;
	if ((data->fd = open(file_desc, O_RDONLY)) == -1)
		return (ft_error("Could not open file", 0));
	data->array = ft_memalloc(sizeof(t_coor*) * data->tabsize.y);
	i = -1;
	while (get_next_line(data->fd, &data->line))
	{
		data->str = ft_strdup(data->line);
		data->tmp = ft_strsplit(data->str, ' ');
		data->tabsize.x = axe_x(data->str);
		data->array[++i] = ft_memalloc(sizeof(t_coor) * data->tabsize.x);
		fill_tab_coor(data, i);
		free(data->line);
		free(data->str);
		free_array(data->tmp);
	}
	close(data->fd);
	return (0);
}

void			axe_y(t_data *data)
{
	data->line = NULL;
	data->tabsize.y = 0;
	data->tabsize.x = 0;
	while (get_next_line(data->fd, &data->line) == 1)
	{
		data->tabsize.y++;
		data->str = ft_strdup(data->line);
		data->tabsize.x = axe_x(data->str);
		free(data->str);
		free(data->line);
	}
	close(data->fd);
	if (data->tabsize.y == 0 || data->tabsize.x == 0)
		ft_exit("Is not a valid file");
}
