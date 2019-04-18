/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:22:03 by gboutin           #+#    #+#             */
/*   Updated: 2019/04/17 12:49:11 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include "../libft/srcs/libft.h"

/*
** ----------------BOOLEEN---------------- **
*/
# define TRUE		1
# define FALSE		0

/*
** ---------------SCREEN SIZE------------- **
*/
# define WIDTH		data->size_window.x
# define HEIGHT		data->size_window.y
# define MIDWIDTH	(WIDTH / 2)
# define MIDHEIGHT	(HEIGHT / 2)
# define MAX_WIDTH	2560
# define MAX_HEIGHT 1390
# define MIN_WIDTH	800
# define MIN_HEIGHT	800

/*
** ---------SPACE BETWEEN TWO POINTS------- **
*/
# define SPACE		(WIDTH / (data->tabsize.x * 1.42))
# define ORIGINY	(MIDHEIGHT - ((data->tabsize.y / 2) * SPACE))
# define ORIGINX	(MIDWIDTH - ((data->tabsize.x / 2) * SPACE))

# define DATA		data->array[c->i][c->j]

/*
** ---------------MLX POINTER------------- **
*/
# define MLXPTR		data->env.mlx_ptr
# define WINPTR		data->env.win_ptr
# define IMGPTR		data->env.img_ptr
# define IMGDATA	data->env.img_data

/*
** -----------------COLOR----------------- **
*/
# define YELLOW		0xe0fb07
# define GREEN		0x42f626
# define CYAN		0x26e7f6
# define WHITE		0xffffff

/*
** ------------COUNTER STRUCTURE---------- **
*/
typedef struct	s_cmpt
{
	int			i;
	int			j;
}				t_cmpt;

/*
** ---STRUCTURE CONTAINING MLX POINTERS--- **
*/
typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_data;
}				t_env;

/*
** ---STRUCTURE CONTAINING AXES X AND Y--- **
*/
typedef struct	s_coor
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_coor;

/*
** --------STRUCTURE FOR BRESENHAM-------- **
*/
typedef struct	s_bresenham
{
	int			erreur;
	int			dx;
	int			dy;
	int			xincr;
	int			yincr;
	t_coor		pos;
}				t_bresenham;

/*
** -------------MAIN STRUCTURE------------ **
*/
typedef struct	s_data
{
	int			fd;
	int			iso;
	int			parallel;
	double		zoom;
	int			z;
	int			bpp;
	int			size_ln;
	int			end;
	char		*str;
	char		*line;
	char		**tmp;
	t_coor		**array;
	t_coor		tabsize;
	t_coor		size_window;
	t_env		env;
}				t_data;

/*
** ---------------------PARSING MAP---------------------
*/
int				axe_x(char *str);
int				parse_map(t_data *data, char *file_desc);
void			axe_y(t_data *data);

/*
** -------------------INIT MLX & WINDOW-----------------
*/
int				smlx_init(t_data *data, char *title);
void			init_size_screen(t_data *data);
void			init_commands(t_data *data);

/*
** ----------------------JUST FREE----------------------
*/
void			free_array(char **str);

/*
** ----------------------KEYBOARDING--------------------
*/
int				deal_key(int key, t_data *data);
int				deal_mouse(t_data *data);
void			help_command(t_data *data);
void			ft_close(t_data *data);

/*
** ----------------------MOVING VIEW--------------------
*/
void			ft_translate_up(t_data *data);
void			ft_translate_left(t_data *data);
void			ft_translate_down(t_data *data);
void			ft_translate_right(t_data *data);
void			ft_zoom_on(t_data *data);
void			ft_zoom_off(t_data *data);
void			ft_iso(t_data *data);
void			ft_parallel(t_data *data);

/*
** ----------------------CHANGE COOR--------------------
*/
void			store_prev_pos(t_data *data);
void			store_prev_pos2(t_data *data);
void			iso(int *x, int *y, t_data *data, t_cmpt *c);
void			ft_decrease_z(t_data *data);
void			ft_increase_z(t_data *data);

/*
** ----------------------DRAW PICTURE-------------------
*/
void			ft_put_pixel(t_data *data, t_bresenham *cur, int color);
void			ft_draw_line(t_coor *cur, t_coor *prev, int color, t_data *d);
void			ft_draw_line2(t_bresenham *cur, t_data *data, int color);
void			ft_draw_line3(t_bresenham *cur, t_data *data, int color);

#endif
