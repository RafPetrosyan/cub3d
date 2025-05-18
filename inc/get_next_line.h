/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafpetro <rafpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:19:26 by rafpetro          #+#    #+#             */
/*   Updated: 2025/05/18 14:19:27 by rafpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		look_for_newline(char *str);
int		there_is_nl(char *str);
int		list_len(t_list *lst);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*create_line(t_list *lst, int line_len);
void	add_to_list(t_list **lst, char *str);
void	create_list(t_list **lst, int fd);
void	clear_list(t_list **lst);
size_t	ft_strlen_gnl(const char *s);

#endif
