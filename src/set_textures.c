/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:18:18 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:14 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_close_door_texture(t_cub *cub)
{
	int	height;
	int	width;

	cub->cd.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			"textures/CloseDoor.xpm", &width, &height);
	if (!cub->cd.img || width != 64 || height != 64)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->west.img);
		mlx_destroy_image(cub->mlx.mlx, cub->south.img);
		mlx_destroy_image(cub->mlx.mlx, cub->north.img);
		mlx_destroy_image(cub->mlx.mlx, cub->east.img);
		if (cub->cd.img)
			mlx_destroy_image(cub->mlx.mlx, cub->cd.img);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		clear_cub(cub);
		err("Can not open door textures\n");
	}
	cub->cd.wd = width;
	cub->cd.ht = height;
	cub->cd.addr = mlx_get_data_addr(cub->cd.img,
			&cub->cd.bits_per_pixel, &cub->cd.line_len, &cub->cd.endian);
}

void	set_open_door_texture(t_cub *cub)
{
	int	height;
	int	width;

	cub->od.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			"textures/OpenDoor.xpm", &width, &height);
	if (!cub->od.img || width != 64 || height != 64)
	{
		mlx_destroy_image(cub->mlx.mlx, cub->west.img);
		mlx_destroy_image(cub->mlx.mlx, cub->south.img);
		mlx_destroy_image(cub->mlx.mlx, cub->north.img);
		mlx_destroy_image(cub->mlx.mlx, cub->east.img);
		mlx_destroy_image(cub->mlx.mlx, cub->cd.img);
		if (cub->od.img)
			mlx_destroy_image(cub->mlx.mlx, cub->od.img);
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		clear_cub(cub);
		err("Can not open door textures\n");
	}
	cub->od.wd = width;
	cub->od.ht = height;
	cub->od.addr = mlx_get_data_addr(cub->od.img,
			&cub->od.bits_per_pixel, &cub->od.line_len, &cub->od.endian);
}
