/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_system_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:07:52 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/10 20:35:38 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_up(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->y_shift -= 10;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}

int	key_down(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->y_shift += 10;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}

int	key_left(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->x_shift -= 10;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}

int	key_right(int key, t_fdf *data)
{
	data->color = 0;
	draw_grid(data);
	data->x_shift += 10;
	data->color = 1;
	draw_grid(data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image_ptr, 0, 0);
	return (key);
}
