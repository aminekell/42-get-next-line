/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:42:45 by akella            #+#    #+#             */
/*   Updated: 2024/12/15 17:23:40 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif

static char	*trim_buffer(char *buffer)
{
	char	*new_buffer;
	char	*newline_pos;
	int		i;

	if (!buffer)
		return (NULL);
	newline_pos = ft_strchr(buffer, '\n');
	if (!newline_pos)
		return (free(buffer), buffer = NULL, NULL);
	i = (newline_pos - buffer) + 1;
	new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!new_buffer)
		return (free(buffer), buffer = NULL, NULL);
	ft_strlcpy(new_buffer, buffer + i, ft_strlen(buffer) - i + 1);
	return (free(buffer), buffer = NULL, new_buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		line_length;
	char	*newline_pos;

	if (!buffer || !*buffer)
		return (NULL);
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos)
		line_length = newline_pos - buffer + 1;
	else
		line_length = ft_strlen(buffer);
	line = ft_calloc(line_length + 1, sizeof(char));
	if (!line)
		return (NULL);
	return (ft_strlcpy(line, buffer, line_length + 1), line);
}

static char	*read_and_append(int fd, char *content)
{
	char	*buffer;
	int		bytes_read;
	char	*comi;

	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(content), NULL);
	ft_strlcpy(buffer, "", (size_t)BUFFER_SIZE + 1);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(content), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		comi = ft_strjoin(content, buffer);
		if (!comi)
			return (free(content), free(buffer), NULL);
		content = comi;
	}
	return (free(buffer), content);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	remainder[fd] = read_and_append(fd, remainder[fd]);
	if (!remainder[fd])
		return (free(remainder[fd]), remainder[fd] = NULL, NULL);
	line = extract_line(remainder[fd]);
	if (!line)
		return (free(remainder[fd]), remainder[fd] = NULL, NULL);
	remainder[fd] = trim_buffer(remainder[fd]);
	return (line);
}
