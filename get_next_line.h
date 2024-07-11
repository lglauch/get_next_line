/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:34:08 by lglauch           #+#    #+#             */
/*   Updated: 2023/12/11 13:43:25 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		get_newline(t_list *list);
t_list	*find_lastnode(t_list *list);
void	str_cpy(t_list *list, char *next_line);
int		get_strlen(t_list *list);
void	dealloc(t_list **list, t_list *cleannode, char *buffer);

#endif