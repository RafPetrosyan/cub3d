/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:42:14 by rafpetro          #+#    #+#             */
/*   Updated: 2025/06/14 20:16:27 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_check(char *str);
char	*ft_strjoin(char *s1, char *s2, int read_size);
void	ft_strjoin_helper(char *s1, char *s2, char *str, int read_size);
int		get_index(char *str);
size_t	ft_strlen_gnl(char *str);
void	rearrange(char *str);

#endif
