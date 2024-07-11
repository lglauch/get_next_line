/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:33:26 by lglauch           #+#    #+#             */
/*   Updated: 2023/12/11 16:42:42 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_newline(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->str_buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_lastnode(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	str_cpy(t_list *list, char *next_line)
{
	int	i;
	int	j;

	j = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				next_line[j++] = '\n';
				next_line[j] = '\0';
				return ;
			}
			next_line[j++] = list->str_buffer[i++];
		}
		list = list->next;
	}
	next_line[j] = '\0';
}

int	get_strlen(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i])
		{
			if (list->str_buffer[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}


void	dealloc(t_list **list, t_list *cleannode, char *buffer)
{
	t_list	*tmp;

	if (!*list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str_buffer);
		free(*list);
		*list = tmp;
	}
	if (cleannode->str_buffer[0])
		*list = cleannode;
	else
	{
		free(cleannode);
		free(buffer);
	}
}
