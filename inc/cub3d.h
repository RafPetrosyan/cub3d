/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:19:29 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:53:28 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

# define ESC 53
# define SPACE 49
# define E 14
# define W 13
# define A 0
# define S 1
# define D 2
# define LARROW 123
# define RARROW 124

# define AROTATE 0.07
# define MROTATE 0.03
# define WSPEED 0.15
# define SSPEED 0.12
# define ROTSPEED 0.06

# define MAP_WIDTH 36
# define MAP_HEIGHT 11
# define TILE_SIZE 10

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
}	t_player;

typedef struct s_rt
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_dist;
	int		hit;
	int		side;

}	t_rt;

typedef struct s_img
{
	int		wd;
	int		ht;
	int		endian;
	int		line_len;
	int		bits_per_pixel;
	char	*addr;
	void	*img;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_lst
{
	char			*line;
	struct s_lst	*next;
}	t_lst;

typedef struct s_type_identifier
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	*floor_color;
	t_color	*ceiling_color;
}	t_type;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_tex_place
{
	int		tex_x;
	int		tex_y;
	int		draw_end;
	int		draw_start;
	int		line_height;
	double	step;
	double	tex_pos;
}	t_tex_place;

typedef struct s_textures
{
	void	*north;
	void	*south;
	void	*west;
	void	*east;
}	t_textures;

typedef struct s_cub
{
	char		**map;
	t_type		*types;
	int			fc;
	int			rc;
	int			map_wd;
	int			map_ht;
	int			hide_map;
	char		*npath;
	char		*spath;
	char		*wpath;
	char		*epath;
	char		*fcolor;
	char		*rcolor;
	bool		play;
	t_mlx		mlx;
	t_player	player;
	t_img		img;
	t_img		cd;
	t_img		od;
	t_rt		ray;
	t_color		f_color;
	t_color		r_color;
	t_lst		*lst_map;
	t_img		*gun;
	t_img		gun_anim;
	t_img		south;
	t_img		north;
	t_img		east;
	t_img		west;
	t_textures	textures;
}	t_cub;

//utils.c
int				ft_strlen(char *s);
int				ft_lstsize(t_lst *lst);
void			ft_lstadd_back(t_lst **lst, char *new);
int				ft_isspace(int ch);
char			*ft_strchr(char *s, int c);

//utils2.c
char			*ft_strstr(char *str, char *to_find);
int				ft_strcmp(const char *s1, const char *s2);
int				name_check_file(char *s);
int				ft_atoi(char *str);

//ft_split.c
int				ft_words_count(char *s);
char			**ft_split(char const *s);

//ft_split_color.c
int				ft_words_count_color(char *s, char c);
char			**ft_split_color(char const *s, char c);

//err_exit.c
void			err(char *str);
int				ext(void *params);
void			destroy_doors_and_walls(t_cub *cub);
void			destroy_guns(t_cub *cub);
void			esc(t_cub *cub);

//free.c
void			free_map_struct(t_lst *map);
void			clear_arr(char **map);
void			clear_types(t_type *types);
void			clear_cub(t_cub *cub);

//valid_map.c
char			**lst_to_array(t_lst *map_stract, t_type *types);
char			*replace_tab_with_spaces(char **map, int i, int j, t_cub *cub);
void			tabs_to_spaces(char **map, t_cub *cub);
void			check_borders(char **map, t_cub *cub);
void			check_doors(char **map, t_cub *cub);

//initialization.c
t_cub			*init_cub(char **map, t_type *types);
t_cub			*start_cub(char *av);
void			mlx_struct_init(t_cub *cub);

//initialization2.c
t_lst			*read_map(char *av);
void			get_player_position(t_cub *cub);
void			set_direction(t_cub *cub, char c);

//struct_map_check.c
int				check_char(t_type *types, char c, t_lst *map, int flag);
void			check_valid_chars(t_lst *map, t_type *types);
int				there_is_valid_char(char *s);
void			clear_empty_lines_begin(t_lst **map);
void			clear_empty_lines_finish(t_lst **map, t_type *types);

//type_identifier.c
void			types_init_struct(t_type *types);
int				type_name(char *to_check, char *with, char *file);
void			types_init(t_type *types, t_lst *map, char **split);
void			check_identifier(t_lst **map, t_type *types);
t_type			*type_identifiers(t_lst **map);

//type_identifier2.c
t_color			*type_set_color(char *str);
void			type_error(t_type *types, char **split, t_lst *map);

//draw.c
int				create_rgb(int t, int r, int g, int b);
void			my_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color(t_img data, int j, int i);
t_img			choose_texture(t_cub *vars);
void			draw_wall(t_cub *cub, t_tex_place tex, int x);

//draw2.c
void			draw_patalok_u_pol(t_cub *cub);
int				ft_redraw(t_cub *cub);
void			gun(t_cub *cub, int i);
void			gun_anim(t_cub *cub);

//movements.c
void			move_forward(t_cub *cub);
void			move_back(t_cub *cub);
void			move_left(t_cub *cub);
void			move_right(t_cub *cub);
int				moveing(int key, t_cub *cub);

//movements2.c
void			rot_left(t_cub *cub);
void			rot_right(t_cub *cub);
void			try_to_open_door(t_cub *cub);
int				mouse_rot(int x, int y, t_cub *cub);

//raycasting.c
void			raycasting(t_cub *cub);
void			set_ray(t_cub *cub, int x);
void			check_ray(t_cub *cub);
void			find_wall(t_cub *cub);
t_tex_place		set_texture(t_cub *cub);

//set_wall_textures.c
void			set_south_texture(t_cub *cub);
void			set_north_texture(t_cub *cub);
void			set_west_texture(t_cub *cub);
void			set_east_texture(t_cub *cub);

//set_textures.c
void			set_close_door_texture(t_cub *cub);
void			set_open_door_texture(t_cub *cub);

//minimap.c
void			paint_square(double i, double j, t_cub *cub, int color);
void			minimap(t_cub *cub);

//set_gun_textures.c
void			set_gun_0_1(t_cub *cub);
void			set_gun_2_3(t_cub *cub);
void			set_gun_4(t_cub *cub);
void			set_guns(t_cub *cub);

#endif