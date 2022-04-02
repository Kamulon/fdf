/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_system_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:08:30 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/10 20:36:58 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_zoom_up(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->zoom += 5;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}

int	key_zoom_down(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	if (data->zoom != 5)
		data->zoom -= 5;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}

int	key_angle_up(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->angle += 0.05;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}

int	key_angle_down(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->angle -= 0.05;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}
