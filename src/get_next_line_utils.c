/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:31 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 20:18:34 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			++i;
			return (i);
		}
		++i;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int read_size)
{
	char	*str;

	if (s1 == 0)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen_gnl(s1)
				+ ft_strlen_gnl(s2) + 1) * (sizeof(char)));
	if (str == 0)
		return (0);
	ft_strjoin_helper(s1, s2, str, read_size);
	return (str);
}

void	ft_strjoin_helper(char *s1, char *s2, char *str, int read_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0' && j < read_size && s2[j] != '\n')
	{
		str[i + j] = s2[j];
		++j;
	}
	if (s2[j] == '\n')
	{
		str[i + j] = s2[j];
		++j;
	}
	str[i + j] = '\0';
}

void	rearrange(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0' && j < BUFFER_SIZE)
	{
		if (str[j] == '\n')
		{
			++j;
			break ;
		}
		++j;
	}
	while (j < BUFFER_SIZE && str[j] != '\0')
	{
		str[i] = str[j];
		++i;
		++j;
	}
	while (i < BUFFER_SIZE && str[i] != '\0')
		str[i++] = '\0';
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}
