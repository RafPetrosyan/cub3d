/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:38 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 20:05:21 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	paint_square(double i, double j, t_cub *cub, int color)
{
	int	k;
	int	l;

	k = (i * 10) - 5;
	while (k < (i * 10) + 5)
	{
		l = (j * 10) - 5;
		while (l < (j * 10) + 5)
		{
			my_pixel_put(&cub->img, l + 10, k + 10, color);
			l++;
		}
		k++;
	}
}

void	minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == 'O')
				color = create_rgb(0, 102, 255, 178);
			else if (cub->map[i][j] == '1')
				color = create_rgb(0, 0, 0, 153);
			else if (cub->map[i][j] == '0')
				color = create_rgb(0, 153, 204, 255);
			else if (cub->map[i][j] == 'C')
				color = create_rgb(0, 0, 204, 204);
			else
				continue ;
			paint_square(i, j, cub, color);
		}
	}
	paint_square(cub->player.pos_x - 0.5, cub->player.pos_y - 0.5,
		cub, create_rgb(0, 255, 255, 0));
}
