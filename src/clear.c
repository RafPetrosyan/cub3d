/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:16:44 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:14 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_map_struct(t_lst *map)
{
	t_lst	*temp;

	if (!map)
		return ;
	while (map)
	{
		free(map->line);
		temp = map->next;
		free(map);
		map = temp;
	}
	map = NULL;
}

void	clear_arr(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	clear_types(t_type *types)
{
	if (!types)
		return ;
	if (types->north)
		free(types->north);
	if (types->south)
		free(types->south);
	if (types->west)
		free(types->west);
	if (types->east)
		free(types->east);
	if (types->floor_color)
		free(types->floor_color);
	if (types->ceiling_color)
		free(types->ceiling_color);
	free(types);
}

void	clear_cub(t_cub *cub)
{
	clear_arr(cub->map);
	cub->map = NULL;
	clear_types(cub->types);
	cub->types = NULL;
	if (cub->gun)
		free(cub->gun);
	cub->gun = NULL;
	free(cub);
}
