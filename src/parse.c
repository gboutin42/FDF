/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 09:28:38 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/19 17:26:41 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				parse_color(char *str, int *i)
{
	int			j;

	j = 0;
	while (str[*i + j] && (ft_isdigit(str[*i + j]) || (str[*i + j] >= 'A' &&
			str[*i + j] <= 'F') || (str[*i + j] >= 'a' && str[*i + j] <= 'f')))
		++j;
	if (j > 8)
		return (-1);
	*i += j;
	return (0);
}

int				parse_digit(char *s, int *i)
{
	if (!*i || s[*i - 1] == ' ' || s[*i - 1] == '-')
		++*i;
	else
		return (-1);
	while (s[*i] && ft_isdigit(s[*i]))
		++*i;
	if (s[*i] == ',')
	{
		if (s[*i + 1] && s[*i + 2] && s[*i + 1] == '0' && s[*i + 2] == 'x')
		{
			*i += 3;
			if (parse_color(s, i) == -1)
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}

int				parse_map(char *str)
{
	int			i;
	int			xlen;

	i = 0;
	xlen = 0;
	if (!*str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			if (parse_digit(str, &i) == -1)
				return (0);
			++xlen;
		}
		else if (str[i] == '-' && str[i + 1] && ft_isdigit(str[i + 1]))
			++i;
		else if (str[i] == ' ')
			++i;
		else
			return (0);
	}
	return (xlen);
}

int				read_map(t_3d *d, char *str)
{
	d->line = NULL;
	d->array = NULL;
	d->fd = 0;
	if ((d->fd = open(str, O_RDONLY)) == -1)
		return (ft_error("Could not open file", 0));
	d->array = ft_memalloc(sizeof(int*) * d->max.y);
	d->i = -1;
	while (get_next_line(d->fd, &d->line) == 1)
	{
		d->str = ft_strdup(d->line);
		d->tmp = ft_strsplit(d->str, ' ');
		d->max.x = parse_map(d->line);
		d->array[++d->i] = ft_memalloc(sizeof(int) * d->max.x);
		d->j = -1;
		while (d->tmp[++d->j] != '\0')
			d->array[d->i][d->j] = ft_atoi(d->tmp[d->j]);
		free(d->line);
		free(d->str);
	}
	printf("y = [%d]\tx = [%d]\n", d->max.y, d->max.x);
	close(d->fd);
	return ((d->max.x >= 1) ? 1 : 0);
}

int 			init_variable(t_3d *d, char *str)
{
	d->max.y = 0;
	while (get_next_line(d->fd, &d->line) == 1)
	{
		d->max.y++;
		free(d->line);
	}
	close(d->fd);
	if ((d->fd = open(str, O_RDONLY)) == -1)
		return (ft_error("Could not open file", 0));
	if (!(read_map(d, str) == 1))
		return (ft_error("Wrong inputs", 0));
/*
** 	d->s.x = ((WIDTH / 2) - (WIDTH / (d->max.x / 2)));
** 	d->s.y = ((HEIGHT / 2) - (HEIGHT / (d->max.y / 2)));
*/
	return (1);
}
