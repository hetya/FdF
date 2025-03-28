/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hetya                                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:20:53 by hetya             #+#    #+#             */
/*   Updated: 2025/02/25 01:00:56 by hetya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

// Controls:
# define KEY_ESCAPE			65307

// Zoom
# define KEY_PAD_PLUS		65451
# define KEY_PAD_MINUS		65453

// Translation
# define KEY_ARROW_LEFT		65361
# define KEY_ARROW_RIGHT	65363
# define KEY_ARROW_UP		65362
# define KEY_ARROW_DOWN		65364
# define KEY_Z				122
# define KEY_Q				113
# define KEY_S				115
# define KEY_D				100

// Projection
# define KEY_P				112

// Rotation
# define KEY_R				114
# define KEY_ENTER			65293

// Color
# define KEY_C				99

// Mouse
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_size;
}				t_data;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}		t_color;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	t_color	color;
}		t_point;

typedef struct s_fdf
{
	t_point	*tab;
	t_point	*reset;
	int		len_tab;
	t_color	t_color;
	int		zoom;
	float	angle;
	int		is_rotation;
	int		switch_color;
	int		is_para;
	int		greater_value;
	int		smaller_value;
	int		high;
	int		width;
	int		x_translation;
	int		y_translation;
	int		x_max;
	int		y_max;
}	t_fdf;

typedef struct s_ptr_mlx
{
	void	*mlx;
	void	*win;
	t_data	*data;
	t_fdf	*fdf;
}		t_ptr_mlx;

typedef struct s_line
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
	int		x;
	int		y;
	float	percent;
}		t_line;

int		fdf_error(int nb);
void	*create_window(void *mlx, char *name, int weidth, int high);
int		key_hook(int key, t_ptr_mlx *ptr_mlx);
char	*fdf_join(char *s1, char const *s2);
void	bresenham_segement(t_ptr_mlx *mlx_ptr, t_point p1, t_point p2);
int		mouse_hook(int key, int x, int y, t_ptr_mlx *mlx_ptr);
void	mlx_pixel_put_on_img(t_ptr_mlx *ptr_mlx, int x, int y, int color);
void	parse(t_ptr_mlx *mlx_ptr, int fd);
int		color(t_ptr_mlx *ptr_mlx);
int		create_trgb(int t, int r, int g, int b);
void	draw_map(t_ptr_mlx *ptr_mlx, t_point *tab, int len_tab);
int		rotation(t_ptr_mlx *ptr_mlx, int ax, int ay, int az);
int		loop_hook(t_ptr_mlx *ptr_mlx);
int		ft_atoi_base(char *str, char *base);
char	*title(char *str);
float	float_percent(int min, int max, int current);
void	white_map(t_ptr_mlx *ptr_mlx);
void	set_color(t_ptr_mlx *ptr_mlx, char *color);
void	center_value(t_ptr_mlx *ptr_mlx);
void	destroy_mlx(t_ptr_mlx *ptr_mlx, void *ptr, int error);
void	check_translation(t_ptr_mlx *ptr_mlx, int key);
int		cleaning_fdf(t_ptr_mlx *ptr_mlx);

#endif
