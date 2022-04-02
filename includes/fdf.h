/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:54:08 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/20 17:03:41 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"

# define HEIGHT			1920
# define WIDTH			1080

typedef struct s_grid
{
	char			*line;
	struct s_grid	*next;
	struct s_grid	*prev;
}	t_grid;

typedef struct s_grid_start
{
	int		len;
	t_grid	*grid;
}	t_grid_start;

typedef struct s_fdf
{
	int				width;
	int				length;
	int				**height;
	int				z_min;
	int				z_max;
	int				color;
	int				x_shift;
	int				y_shift;
	float			angle;
	float			zoom;
	void			*image_ptr;
	char			*data_adr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*mlx_ptr;
	void			*win_ptr;
	t_grid_start	*grid;
}	t_fdf;



typedef struct s_dot
{
	float	x;
	float	y;
	float	z;
}	t_dot;

//list_grid_system.c
t_grid	*lstnew(char *line);
void	lstadd_back(t_grid_start *start, t_grid *new);
//void	lstfree(t_grid_start *start);

//simple_maths.c
int		max(int a, int b);
int		min(int a, int b);
int		mod(float a);

//data_and_read.c
void	init_data(t_fdf	*data, t_grid_start *start);
void	read_file(int fd, t_fdf *data);
void	get_width(t_fdf *data);
void	get_height(t_fdf *data);
void	free_height(t_fdf *data);

//draw_system_0.c
void	draw_grid(t_fdf *data);

//draw_system_1.c
void	coords_zoom(t_dot *a, t_dot *b, t_fdf *data);
void	coords_isometric(t_dot *a, t_dot *b, t_fdf *data);
void	coords_get_height(t_dot *a, t_dot *b, t_fdf *data);
void	coords_shift(t_dot *a, t_dot *b, t_fdf *data);

//control_system_0.c
int		close_key(void *param, t_fdf *data);
int		key_esc(int key, t_fdf *data);
void	setup_controls(t_fdf *data);
int		deal_key(int key, t_fdf *data);
//control_system_1.c
int		key_up(int key, t_fdf *data);
int		key_down(int key, t_fdf *data);
int		key_left(int key, t_fdf *data);
int		key_right(int key, t_fdf *data);
//control_system_2.c
int		key_zoom_up(int key, t_fdf *data);
int		key_zoom_down(int key, t_fdf *data);
int		key_angle_up(int key, t_fdf *data);
int		key_angle_down(int key, t_fdf *data);

//libft_utils
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd, char **line);

#endif
