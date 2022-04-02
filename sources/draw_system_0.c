/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_system_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:04:12 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/19 21:46:17 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_dot	new_dot(float x, float y)
{
	t_dot	a;

	a.x = x;
	a.y = y;
	a.z = 0;
	return (a);
}

static void	pick_color(float z, t_fdf *data)
{
	float	range;
	float	quart1;
	float	quart2;
	float	quart3;

	range = (float)(data->z_max - data->z_min);
	quart1 = (float) data->z_min + range / 4;
	quart2 = (float) data->z_min + range / 4 * 2;
	quart3 = (float) data->z_min + range / 4 * 3;
	if (z <= quart1)
		data->color = 0xa6f1f4;
	else if (z > quart1 && z < quart2)
		data->color = 0xbff271;
	else if (z >= quart2 && z < quart3)
		data->color = 0xf7c34f;
	else if (z >= quart3)
		data->color = 0xe16331;
}

static void	put_pixel(t_fdf *data, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * data->bits_per_pixel / 8) + (y * data->size_line);
		data->data_adr[i] = color;
		data->data_adr[++i] = color >> 8;
		data->data_adr[++i] = color >> 16;
	}
}

static void	draw_line(t_dot a, t_dot b, t_fdf *data)
{
	float	dx;
	float	dy;
	float	dz;
	float	max_d;

	coords_get_height(&a, &b, data);
	coords_zoom(&a, &b, data);
	coords_isometric(&a, &b, data);
	coords_shift(&a, &b, data);
	dx = (b.x - a.x);
	dy = (b.y - a.y);
	dz = (b.z - a.z);
	max_d = max(mod(dx), mod(dy));
	dx /= max_d;
	dy /= max_d;
	dz /= max_d;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (data->color != 0)
			pick_color(a.z, data);
		put_pixel(data, a.x, a.y, data->color);
		a.x += dx;
		a.y += dy;
		a.z += dz;
	}
}

void	draw_grid(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= (int)data->length - 1)
	{
		x = 0;
		while (x <= (int)data->width - 1)
		{
			if (y != (int)data->length - 1)
				draw_line(new_dot(x, y), new_dot(x, y + 1), data);
			if (x != (int)data->width - 1)
				draw_line(new_dot(x, y), new_dot(x + 1, y), data);
			x++;
		}
		y++;
	}
}
