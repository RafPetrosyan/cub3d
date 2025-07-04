/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:53:53 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 20:15:47 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	int			read_size;
	char		*ret;
	char		*temp;
	static char	buffer[BUFFER_SIZE];

	temp = 0;
	ret = 0;
	if (buffer[0] != '\0')
	{
		temp = ft_strjoin(temp, buffer, BUFFER_SIZE);
		rearrange(buffer);
		if (ft_check(temp) == 1)
			return (temp);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		ret = ft_strjoin(temp, buffer, read_size);
		temp = ret;
		rearrange(buffer);
		if (ft_check(ret) == 1)
			return (ret);
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (temp);
}
