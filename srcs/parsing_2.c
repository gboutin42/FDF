/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:10:18 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 09:11:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		parse_color(char *str, int *i)
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

static int		ft_ishexa(char *str, int *i)
{
	if (str[*i] == ',' && str[*i + 1] == '0')
		if (str[*i + 2] == 'x' || str[*i + 2] == 'X')
		{
			*i += 3;
			return (1);
		}
	return (0);
}

int				axe_x(char *str)
{
	int			xlen;
	int			i;

	i = 0;
	xlen = 0;
	if (str[i] == '\0')
		ft_exit("Empty File");
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
		{
			xlen++;
			while (ft_isdigit(str[i]) && str[i] != '\0' && str[i] != '\n')
				i++;
			if (str[i] == '\0' || str[i] == '\n')
				return (xlen);
		}
		else if (str[i] == ' ' || (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		else if (ft_ishexa(str, &i))
			parse_color(str, &i);
		else
			ft_exit("Invalid Character");
	}
	return (xlen);
}
