/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:18:43 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 19:57:22 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_lstsize(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}

void	ft_lstadd_back(t_lst **lst, char *new)
{
	t_lst	*node;
	t_lst	*tmp;

	node = malloc(sizeof(t_lst));
	if (!node)
	{
		free_map_struct(*lst);
		err("Memory allocation error!\n");
	}
	node -> next = NULL;
	node -> line = new;
	if (!*lst)
		*lst = node;
	else
	{
		tmp = *lst;
		while (tmp -> next)
			tmp = tmp ->next;
		tmp->next = node;
	}
}

int	ft_isspace(int ch)
{
	if (!ch)
		return (0);
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\f'
		|| ch == '\r' || ch == '\v')
		return (1);
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}
