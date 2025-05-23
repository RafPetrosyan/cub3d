/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:16:50 by rafpetro          #+#    #+#             */
/*   Updated: 2025/05/18 14:16:53 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_words_count_color(char *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 0;
	count = 0;
	while (i <= (int)ft_strlen(s))
	{
		if ((s[i] == c || s[i] == '\0') && flag)
		{
			count++;
			flag = 0;
		}
		else if (s[i] != c)
			flag = 1;
		i++;
	}
	return (count);
}

static char	*init(int len, char *s)
{
	char	*element;
	int		i;

	i = 0;
	element = malloc((len + 1) * sizeof(char));
	if (!element)
		return (0);
	while (i < len)
	{
		element[i] = s[i];
		i++;
	}
	element[len] = '\0';
	return (element);
}

static int	fill(char **arr, char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		if ((s[len] == c || s[len] == '\0') && len)
		{
			arr[i] = init(len, s);
			if (!arr[i])
				return (0);
			s += len;
			len = 0;
			i++;
		}
		else if (s[len] != c && s[len] != '\0')
			len++;
		else
			s++;
	}
	return (1);
}

char	**ft_split_color(char const *s, char c)
{
	int		w_count;
	char	**arr;

	if (!s)
		w_count = 0;
	else
		w_count = ft_words_count_color((char *) s, c);
	arr = malloc((w_count + 1) * sizeof(char *));
	if (!arr)
		return (0);
	arr[w_count] = 0;
	if (!w_count)
		return (arr);
	if (!fill(arr, (char *) s, c))
		return (0);
	return (arr);
}
