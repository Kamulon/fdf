/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:53:46 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/20 20:28:24 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_grid_start	start;
	t_fdf			data;
	int				fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDWR, 0);
		if (fd < 0)
			return (0);
		init_data(&data, &start);
		read_file(fd, &data);
		close(fd);
		data.length = data.grid->len;
		get_width(&data);
		get_height(&data);
		draw_grid(&data);
		setup_controls(&data);
		mlx_put_image_to_window(data.mlx_ptr,
			data.win_ptr, data.image_ptr, 0, 0);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
