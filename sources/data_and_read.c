/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_and_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:58:39 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/20 20:38:28 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_data(t_fdf	*data, t_grid_start *start)
{
	data->width = 0;
	data->length = 0;
	data->height = 0;
	data->zoom = 20;
	data->color = 0x0000FF;
	data->z_max = 0;
	data->z_min = 0;
	data->x_shift = 150;
	data->y_shift = 150;
	data->angle = 0.8;
	data->grid = start;
	data->grid->len = 0;
	data->grid->grid = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	data->image_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data_adr = mlx_get_data_addr(data->image_ptr,
			&(data->bits_per_pixel), &(data->size_line), &(data->endian));
}

void	read_file(int fd, t_fdf *data)
{
	char	*line;
	char	*new_line;
	t_grid	*new_item;

	while (get_next_line(fd, &line))
	{
		new_line = ft_strdup(line);
		new_item = lstnew(new_line);
		lstadd_back(data->grid, new_item);
		free(line);
	}
	return ;
}

void	get_width(t_fdf *data)
{
	char	*line;

	line = data->grid->grid->line;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			data->width++;
			while (ft_isdigit(*line))
				line++;
		}
		line++;
	}
	return ;
}

void	free_height(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->length)
		free(data->height[i++]);
	free(data->height);
}

void	get_height(t_fdf *data)
{
	int		i;
	int		width;
	char	**nums;
	t_grid	*current;

	i = 0;
	current = data->grid->grid;
	data->height = (int **)malloc(sizeof(int *) * (data->length + 1));
	while (i < data->length)
	{
		width = 0;
		nums = ft_split(current->line, ' ');
		data->height[i] = (int *)malloc(sizeof(int) * (data->width));
		while (width < data->width)
		{	
			data->height[i][width] = ft_atoi(nums[width]);
			data->z_max = max(data->height[i][width], data->z_max);
			data->z_min = min(data->height[i][width], data->z_min);
			free(nums[width++]);
		}
		current = current->next;
		i++;
		free(nums);
	}
	data->height[i] = NULL;
}
