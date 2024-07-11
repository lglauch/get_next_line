/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:15 by lglauch           #+#    #+#             */
/*   Updated: 2023/12/14 16:27:39 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_buffer(int fd, char *buffer)
{
	int		buffer_read;
	char	*new_buffer;

	new_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_buffer)
		return (NULL);
	buffer_read = 1;
	while (buffer_read != 0)
	{
		buffer_read = read(fd, new_buffer, BUFFER_SIZE);
		if (buffer_read == 0)
			break ;
		if (buffer_read == -1)
			return (free(new_buffer), free(buffer), NULL);
		new_buffer[buffer_read] = '\0';
		buffer = ft_strjoin(buffer, new_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(new_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free (buffer), buffer = NULL, NULL);
	buffer = make_buffer(fd, buffer);
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	next_line = get_theline(buffer);
	buffer = newline(buffer);
	return (next_line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line: %d - " "%s\n", ++i, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
