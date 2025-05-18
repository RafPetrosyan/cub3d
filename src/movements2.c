/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:50 by rafpetro          #+#    #+#             */
/*   Updated: 2025/05/18 14:17:51 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rot_left(t_cub *cub)
{
	double	tmp;

	tmp = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(-ROTSPEED)
		- cub->player.dir_y * sin(-ROTSPEED);
	cub->player.dir_y = tmp * sin(-ROTSPEED)
		+ cub->player.dir_y * cos(-ROTSPEED);
	tmp = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(-ROTSPEED)
		- cub->player.plane_y * sin(-ROTSPEED);
	cub->player.plane_y = tmp * sin(-ROTSPEED)
		+ cub->player.plane_y * cos(-ROTSPEED);
}

void	rot_right(t_cub *cub)
{
	double	tmp;

	tmp = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(ROTSPEED)
		- cub->player.dir_y * sin(ROTSPEED);
	cub->player.dir_y = tmp * sin(ROTSPEED) + cub->player.dir_y * cos(ROTSPEED);
	tmp = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(ROTSPEED)
		- cub->player.plane_y * sin(ROTSPEED);
	cub->player.plane_y = tmp * sin(ROTSPEED)
		+ cub->player.plane_y * cos(ROTSPEED);
}

void	try_to_open_door(t_cub *cub)
{
	int	x;
	int	y;

	x = (int)cub->player.pos_x + round(cub->player.dir_x);
	y = (int)cub->player.pos_y + round(cub->player.dir_y);
	if (cub->map[x][y] == 'C')
		cub->map[x][y] = 'O';
	else if (cub->map[x][y] == 'O')
		cub->map[x][y] = 'C';
}

int	mouse_rot(int x, t_cub *cub)
{
	static int	past_view;

	if (x < past_view)
		rot_right(cub);
	else if (x > past_view)
		rot_left(cub);
	past_view = x;
	return (0);
}
