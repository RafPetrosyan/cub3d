/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:17:20 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:14 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_cub	*init_cub(char **map, t_type *types)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
	{
		clear_types(types);
		err("Memory allocation error\n");
	}
	cub->map = map;
	cub->types = types;
	cub->gun = NULL;
	tabs_to_spaces(cub->map, cub);
	check_borders(cub->map, cub);
	check_doors(cub->map, cub);
	return (cub);
}

t_cub	*start_cub(char *argv)
{
	t_lst	*map_str;
	t_type	*types;
	char	**map;

	map_str = read_map(argv);
	types = type_identifiers(&map_str);
	if (!types || !types->north || !types->west
		|| !types->east || !types->floor_color || !types->ceiling_color)
	{
		clear_types(types);
		free_map_struct(map_str);
		err("Map is not valid`(missing types)\n");
	}
	check_valid_chars(map_str, types);
	clear_empty_lines_begin(&map_str);
	clear_empty_lines_finish(&map_str, types);
	if (!map_str)
	{
		clear_types(types);
		err("Map is not valid\n");
	}
	map = lst_to_array(map_str, types);
	return (init_cub(map, types));
}

void	init_textutes(t_cub *cub)
{
	set_open_door_texture(cub);
	set_close_door_texture(cub);
	set_east_texture(cub);
	set_west_texture(cub);
	set_north_texture(cub);
	set_south_texture(cub);
	set_guns(cub);
	if (!cub->od.addr || !cub->north.addr || !cub->west.addr
		|| !cub->east.addr || !cub->south.addr || !cub->cd.addr
		|| !cub->gun[0].addr || !cub->gun[1].addr
		|| !cub->gun[2].addr || !cub->gun[3].addr
		|| !cub->gun[4].addr)
	{
		destroy_doors_and_walls(cub);
		destroy_guns(cub);
		clear_cub(cub);
		err("Can not open textures\n");
	}
}

void	mlx_struct_init(t_cub *cub)
{
	cub->map_wd = 1080;
	cub->map_ht = 720;
	cub->img.ht = cub->map_ht;
	cub->img.wd = cub->map_wd;
	cub->player.dir_x = 0.0;
	cub->player.dir_y = 0.0;
	cub->player.plane_x = 0.0;
	cub->player.plane_y = 0.0;
	cub->play = false;
	get_player_position(cub);
	cub->fc = create_rgb(0, cub->types->floor_color->r,
			cub->types->floor_color->g, cub->types->floor_color->b);
	cub->rc = create_rgb(0, cub->types->ceiling_color->r,
			cub->types->ceiling_color->g, cub->types->ceiling_color->b);
	cub->mlx.mlx = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.mlx,
			cub->map_wd, cub->map_ht, "cub3D");
	init_textutes(cub);
	mlx_hook(cub->mlx.win, 6, 1L << 6, mouse_rot, cub);
	mlx_hook(cub->mlx.win, 2, 1L << 0, &moveing, cub);
	mlx_loop_hook(cub->mlx.mlx, &ft_redraw, cub);
	mlx_hook(cub->mlx.win, 17, 0, ext, cub);
	mlx_loop(cub->mlx.mlx);
}
