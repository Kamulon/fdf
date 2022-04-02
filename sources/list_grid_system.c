/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_grid_system.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperegri <cperegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:02:52 by cperegri          #+#    #+#             */
/*   Updated: 2022/03/20 17:03:59 by cperegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_grid	*lstnew(char *line)
{
	t_grid	*new_elem;

	new_elem = malloc(sizeof(t_grid));
	if (new_elem)
	{
		new_elem->line = line;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	return (new_elem);
}

void	lstadd_back(t_grid_start *start, t_grid *new)
{
	if (start->len == 0)
	{
		start->grid = new;
		new->next = new;
		new->prev = new;
		start->len++;
		return ;
	}
	new->next = start->grid;
	new->prev = start->grid->prev;
	start->grid->prev->next = new;
	start->grid->prev = new;
	start->len++;
}
