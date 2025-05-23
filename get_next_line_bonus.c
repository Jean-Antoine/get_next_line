/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:32:48 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 15:13:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*add_node(t_buffer **buffer_list, int fd)
{
	t_buffer	*node;

	node = (t_buffer *)malloc(sizeof(t_buffer));
	if (!node)
		return (NULL);
	node->content[0] = '\0';
	node->fd = fd;
	node->next = NULL;
	ft_lstadd_back(buffer_list, node);
	return (node);
}

t_buffer	*remove_node(t_buffer *buffer_list, int fd, int force)
{
	t_buffer	*prev;
	t_buffer	*current;

	if (!buffer_list)
		return (NULL);
	prev = NULL;
	current = buffer_list;
	while (current->next && current->fd != fd)
	{
		prev = current;
		current = current->next;
	}
	if (current->fd == fd && (!current->content[0] || force))
	{
		if (prev)
			prev->next = current->next;
		else
			buffer_list = current->next;
		free(current);
	}
	return (buffer_list);
}

t_buffer	*find_fd(t_buffer **buffer_list, int fd)
{
	t_buffer	*node;

	if (!buffer_list)
		return (NULL);
	node = *buffer_list;
	while (node && node->fd != fd)
		node = node->next;
	if (!node)
		node = add_node(buffer_list, fd);
	return (node);
}

char	*read_line(t_buffer **buffer_list, int fd)
{
	t_buffer	*buffer;
	char		*line;
	ssize_t		read_c;

	line = NULL;
	buffer = find_fd(buffer_list, fd);
	if (!buffer)
		return (NULL);
	if (cat_buffer(&line, buffer->content))
		return (line);
	read_c = 1;
	while (read_c)
	{
		read_c = read(fd, (buffer->content), BUFFER_SIZE);
		if (read_c < 0)
			return (NULL);
		buffer->content[read_c] = '\0';
		if (read_c && cat_buffer(&line, buffer->content))
			return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	*buffer;
	char			*line;

	line = read_line(&buffer, fd);
	buffer = remove_node(buffer, fd, !line);
	return (line);
}
