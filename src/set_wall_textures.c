/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:18:23 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:14 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_south_texture(t_cub *cub)
{
	int	height;
	int	width;

	cub->south.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->types->south, &width, &height);
	if (!cub->south.img || width != 64 || height != 64)
	{
		if (cub->south.img)
			mlx_destroy_image(cub->mlx.mlx, cub->south.img);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		clear_cub(cub);
		err("Can not open wall textures\n");
	}
	cub->south.wd = width;
	cub->south.ht = height;
	cub->south.addr = mlx_get_data_addr(cub->south.img,
			&cub->south.bits_per_pixel, &cub->south.line_len,
			&cub->south.endian);
}

void	set_north_texture(t_cub *cub)
{
	int	height;
	int	width;

	cub->north.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->types->north, &width, &height);
	if (!cub->north.img || width != 64 || height != 64)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->south.img);
		if (cub->north.img)
			mlx_destroy_image(cub->mlx.mlx, cub->north.img);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		clear_cub(cub);
		err("Can not open wall textures\n");
	}
	cub->north.wd = width;
	cub->north.ht = height;
	cub->north.addr = mlx_get_data_addr(cub->north.img,
			&cub->north.bits_per_pixel, &cub->north.line_len,
			&cub->north.endian);
}

void	set_west_texture(t_cub *cub)
{
	int	height;
	int	width;

	cub->west.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->types->west, &width, &height);
	if (!cub->west.img || width != 64 || height != 64)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->south.img);
		mlx_destroy_image(cub->mlx.mlx, cub->north.img);
		if (cub->west.img)
			mlx_destroy_image(cub->mlx.mlx, cub->west.img);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		clear_cub(cub);
		err("Can not open wall textures\n");
	}
	cub->west.wd = width;
	cub->west.ht = height;
	cub->west.addr = mlx_get_data_addr(cub->west.img,
			&cub->west.bits_per_pixel, &cub->west.line_len, &cub->west.endian);
}

void	set_east_texture(t_cub *cub)
{
	int	height;
	int	width;

	cub->east.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->types->east, &width, &height);
	if (!cub->east.img || width != 64 || height != 64)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->west.img);
		mlx_destroy_image(cub->mlx.mlx, cub->south.img);
		mlx_destroy_image(cub->mlx.mlx, cub->north.img);
		if (cub->east.img)
			mlx_destroy_image(cub->mlx.mlx, cub->east.img);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		clear_cub(cub);
		err("Can not open wall textures\n");
	}
	cub->east.wd = width;
	cub->east.ht = height;
	cub->east.addr = mlx_get_data_addr(cub->east.img,
			&cub->east.bits_per_pixel, &cub->east.line_len, &cub->east.endian);
}
