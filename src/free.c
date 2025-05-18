/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:16:44 by rafpetro          #+#    #+#             */
/*   Updated: 2025/05/18 14:16:45 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cub3d.h"

void	free_map_struct(t_lst *map)
{
	t_lst	*tmp;

	if (!map)
		return ;
	while (map)
	{
		free(map->line);
		tmp = map->next;
		free(map);
		map = tmp;
	}
	map = NULL;
}

void	free_array(char **map)
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

void	free_types(t_type *types)
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

void	free_cub(t_cub *cub)
{
	free_array(cub->map);
	cub->map = NULL;
	free_types(cub->types);
	cub->types = NULL;
	if (cub->gun)
		free(cub->gun);
	cub->gun = NULL;
}
