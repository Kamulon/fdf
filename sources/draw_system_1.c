/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_system_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:05:24 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/10 16:06:06 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	coords_zoom(t_dot *a, t_dot *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	b->x *= data->zoom;
	b->y *= data->zoom;
}

void	coords_isometric(t_dot *a, t_dot *b, t_fdf *data)
{
	a->x = (a->x - a->y) * cos(data->angle);
	a->y = (a->x + a->y) * sin(data->angle) - a->z;
	b->x = (b->x - b->y) * cos(data->angle);
	b->y = (b->x + b->y) * sin(data->angle) - b->z;
}

void	coords_get_height(t_dot *a, t_dot *b, t_fdf *data)
{
	a->z = data->height[(int)a->y][(int)a->x];
	b->z = data->height[(int)b->y][(int)b->x];
}

void	coords_shift(t_dot *a, t_dot *b, t_fdf *data)
{
	a->x += data->x_shift;
	a->y += data->y_shift;
	b->x += data->x_shift;
	b->y += data->y_shift;
}
