/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:44 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:30:43 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <X11/keysym.h>

void	move_forward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x + cub->player.dir_x * WSPEED;
	new_y = cub->player.pos_y + cub->player.dir_y * WSPEED;
	if (cub->map[(int)new_x][(int)cub->player.pos_y] != '1'
		&& cub->map[(int)new_x][(int)cub->player.pos_y] != 'C')
		cub->player.pos_x = new_x;
	if (cub->map[(int)cub->player.pos_x][(int)new_y] != '1'
		&& cub->map[(int)cub->player.pos_x][(int)new_y] != 'C')
		cub->player.pos_y = new_y;
}

void	move_back(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x - cub->player.dir_x * WSPEED;
	new_y = cub->player.pos_y - cub->player.dir_y * WSPEED;
	if (cub->map[(int)new_x][(int)cub->player.pos_y] != '1'
		&& cub->map[(int)new_x][(int)cub->player.pos_y] != 'C')
		cub->player.pos_x = new_x;
	if (cub->map[(int)cub->player.pos_x][(int)new_y] != '1'
		&& cub->map[(int)cub->player.pos_x][(int)new_y] != 'C')
		cub->player.pos_y = new_y;
}

void	move_left(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x - cub->player.dir_y * SSPEED;
	new_y = cub->player.pos_y + cub->player.dir_x * SSPEED;
	if (cub->map[(int)new_x][(int)cub->player.pos_y] != '1'
		&& cub->map[(int)new_x][(int)cub->player.pos_y] != 'C')
		cub->player.pos_x = new_x;
	if (cub->map[(int)cub->player.pos_x][(int)new_y] != '1'
		&& cub->map[(int)cub->player.pos_x][(int)new_y] != 'C')
		cub->player.pos_y = new_y;
}

void	move_right(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player.pos_x + cub->player.dir_y * SSPEED;
	new_y = cub->player.pos_y - cub->player.dir_x * SSPEED;
	if (cub->map[(int)new_x][(int)cub->player.pos_y] != '1'
		&& cub->map[(int)new_x][(int)cub->player.pos_y] != 'C')
		cub->player.pos_x = new_x;
	if (cub->map[(int)cub->player.pos_x][(int)new_y] != '1'
		&& cub->map[(int)cub->player.pos_x][(int)new_y] != 'C')
		cub->player.pos_y = new_y;
}

int	moveing(int key, t_cub *cub)
{
	if (key == XK_Escape)
		esc(cub);
	if (key == XK_space)
		cub->play = true;
	else if (key == 16778616)
		move_forward(cub);
	else if (key == 16778593)
		move_left(cub);
	else if (key == 16778621)
		move_back(cub);
	else if (key == 65361)
		rot_right(cub);
	else if (key == 16778596)
		move_right(cub);
	else if (key == 65363)
		rot_left(cub);
	else if (key == 16778597)
		try_to_open_door(cub);
	return (0);
}
