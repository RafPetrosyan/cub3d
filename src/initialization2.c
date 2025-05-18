/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:25 by rafpetro          #+#    #+#             */
/*   Updated: 2025/05/18 18:37:58 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/get_next_line.h"

t_lst	*read_map(char *av)		//կարդում է քարտեզը, ավելացնում է լիստի մեջ տողերին եթե հիշողություն չի կարողանում հատկացնել ազատում է մինչև այդ զբաղեցրածները
{
	int		fd;
	char	*line;
	t_lst	*map;

	if (!name_check_file(av))	
		err("Invalid map!\n");
	map = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err("Invalid map!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, line);
	}
	close(fd);
	if (!map)
		err("Invalid map\n");
	return (map);
}

void	get_player_position(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				set_direction(cub, cub->map[i][j]);
				cub->player.pos_x = i + 0.5;
				cub->player.pos_y = j + 0.5;
				cub->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_direction(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->player.plane_y = 0.66;
		cub->player.dir_x = -1.0;
	}
	else if (c == 'S')
	{
		cub->player.plane_y = -0.66;
		cub->player.dir_x = 1.0;
	}
	else if (c == 'W')
	{
		cub->player.plane_x = -0.66;
		cub->player.dir_y = -1.0;
	}
	else if (c == 'E')
	{
		cub->player.plane_x = 0.66;
		cub->player.dir_y = 1.0;
	}
}
