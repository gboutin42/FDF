/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:25:04 by gboutin           #+#    #+#             */
/*   Updated: 2019/03/18 16:25:47 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "../../libft_perso/src/libft.h"//a modifier avec le bon path
# include <stdio.h>//a supprimer

# define MLXPTR			d->env.mlx_ptr
# define WINPTR 		d->env.win_ptr
# define IMGPTR 		d->env.img_ptr
# define IMGDATA		d->env.img_data

# define WIDTH			2400//max = 2560
# define HEIGHT			1300//max = 1395
# define SPACEX			(WIDTH / (d->max.x * 3))
# define SPACEY			SPACEX / 2
# define RED			0xe22b29
# define YELLOW			0xfbf22f
# define BLUE			0x56c5ea
# define GREEN			0x22ff00
# define CYAN			0x00FFFF
# define WHITE			0xFFFFFF

/*
** middle = max_size/2 - size/2 * nb_pixel_echelle
*/

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;

}				t_env;

typedef struct	s_abs_ord
{
	int			x;
	int			y;
}				t_abs_ord;

typedef struct	s_data
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	float		dx;
	float		dy;
	float		e;
}				t_data;

typedef	struct	s_3d
{
	char		*line;
	char		*str;
	char		*pxl;
	char		**tmp;
	int			**array;
	int			fd;
	int			i;
	int			j;
	int			bpp;
	int			size_line;
	int			endian;
	t_abs_ord	max;
	t_abs_ord	s;
	t_data		tata;
	t_env		env;
}				t_3d;

/*
** -----------------------DRAWING----------------------
*/
int				draw_img(t_3d *d);

/*
** ----------------------INIT WINDOW-------------------
*/
void			ft_help_command(t_3d *d);
int				smlx_init(t_3d *d, char *title);

/*
** ---------------------KEYBOARDING--------------------
*/
int				deal_key(int key, t_3d *d);
int				deal_mouse(t_3d *d);

/*
** -----------------------PARSING----------------------
*/
int				parse_color(char *str, int *i);
int				parse_digit(char *s, int *i);
int				parse_map(char *str);
int				read_map(t_3d *d, char *s);
int				init_variable(t_3d *d, char *str);

/*
** --------------------ALGO BRESENHAM------------------
*/
void			ft_bresenham(t_3d *d, t_abs_ord a, t_abs_ord b, int color);
void			ft_vertical(t_abs_ord a, t_abs_ord b, t_3d *d, int color);
void			ft_horizontal(t_abs_ord a, t_abs_ord b, t_3d *d, int color);
int				ft_abs(int i);
void			ft_pixel_put(t_3d *d, t_abs_ord pos, int color);

/*
** ---------------------CREATE GRID--------------------
*/
void			draw_line(t_3d *d, t_abs_ord start, t_abs_ord coor, char dir);
void			create_grid(t_3d *d);

#endif
