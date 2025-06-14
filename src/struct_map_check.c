/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:18:28 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:50:41 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_char(t_type *types, char c, t_lst *map, int flag)
{
	if (ft_isspace(c) || c == '0' || c == 'C' || c == '1' || c == 'O')
		return (0);
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && flag == 0)
		return (1);
	else
	{
		clear_types(types);
		free_map_struct(map);
		err("Map is not valid`(unacceptable char)!\n");
	}
	return (0);
}

void	check_valid_chars(t_lst *map, t_type *types)
{
	int		i;
	t_lst	*temp;
	int		flag;

	temp = map;
	flag = 0;
	while (temp)
	{
		i = -1;
		while (temp->line[++i])
			flag += check_char(types, temp->line[i], map, flag);
		temp = temp -> next;
	}
	if (flag != 1)
	{
		clear_types(types);
		free_map_struct(map);
		err("Map is not valid`(no player)!\n");
	}
}

int	there_is_valid_char(char *s)
{
	if (ft_strchr(s, 'S') || ft_strchr(s, 'N')
		|| ft_strchr(s, '0') || ft_strchr(s, '1')
		|| ft_strchr(s, 'O') || ft_strchr(s, 'C')
		|| ft_strchr(s, 'E') || ft_strchr(s, 'W'))
		return (1);
	return (0);
}

void	clear_empty_lines_begin(t_lst **map)
{
	t_lst	*tmp;

	if (!map)
		return ;
	while (*map && !(there_is_valid_char((*map)->line)
			|| ft_strstr((*map)->line, "north")
			|| ft_strstr((*map)->line, "east")
			|| ft_strstr((*map)->line, "west")
			|| ft_strstr((*map)->line, "south")
			|| ft_strstr((*map)->line, "C")
			|| ft_strstr((*map)->line, "F")))
	{
		tmp = (*map)->next;
		free((*map)->line);
		free(*map);
		*map = tmp;
	}
}

void	clear_empty_lines_finish(t_lst **map, t_type *types)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	tmp = *map;
	while (tmp && tmp->next)
	{
		if (!there_is_valid_char(tmp->next->line))
		{
			tmp2 = tmp->next;
			while (tmp2)
			{
				if (there_is_valid_char(tmp2->line))
				{
					free_map_struct(*map);
					clear_types(types);
					err("Map is not valid`(free line in map)\n");
				}
				tmp2 = tmp2->next;
			}
			free_map_struct(tmp->next);
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
}
