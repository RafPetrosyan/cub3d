/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:16:14 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:14 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ext(void *params)
{
	t_cub	*cub;

	cub = params;
	destroy_doors_and_walls(cub);
	destroy_guns(cub);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	mlx_destroy_display(cub->mlx.mlx);
	free(cub->mlx.mlx);
	clear_cub(cub);
	cub = NULL;
	exit(0);
}

void	destroy_doors_and_walls(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.mlx, cub->west.img);
	mlx_destroy_image(cub->mlx.mlx, cub->south.img);
	mlx_destroy_image(cub->mlx.mlx, cub->north.img);
	mlx_destroy_image(cub->mlx.mlx, cub->east.img);
	mlx_destroy_image(cub->mlx.mlx, cub->cd.img);
	mlx_destroy_image(cub->mlx.mlx, cub->od.img);
}

void	destroy_guns(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 5)
		mlx_destroy_image(cub->mlx.mlx, cub->gun[i].img);
}

void	esc(t_cub *cub)
{
	destroy_doors_and_walls(cub);
	destroy_guns(cub);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	mlx_destroy_display(cub->mlx.mlx);
	free(cub->mlx.mlx);
	clear_cub(cub);
	exit(0);
}
