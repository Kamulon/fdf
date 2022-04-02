/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_system_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:57:58 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/20 17:02:53 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	setup_controls(t_fdf *data)
{
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_key, data);
}

int	key_esc(int key, t_fdf *data)
{
	(void) key;
	free_height(data);
	exit (0);
}

int	close_key(void *param, t_fdf *data)
{
	(void)param;
	free_height(data);
	exit(0);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 53)
		return (key_esc(key, data));
	if (key == 126)
		return (key_up(key, data));
	if (key == 125)
		return (key_down(key, data));
	if (key == 123)
		return (key_left(key, data));
	if (key == 124)
		return (key_right(key, data));
	if (key == 24)
		return (key_zoom_up(key, data));
	if (key == 27)
		return (key_zoom_down(key, data));
	if (key == 44)
		return (key_angle_up(key, data));
	if (key == 47)
		return (key_angle_down(key, data));
	return (key);
}
