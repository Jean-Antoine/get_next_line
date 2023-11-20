/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:32:48 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/17 14:40:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_trim_buffer(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	ft_memmove(buf, &buf[i + 1], ft_strlen(&buf[i + 1]));
	ft_bzero(&buf[ft_strlen(buf)], i);
	return (buf);
}

char	*ft_get_line(char *line, char *buf)
{
	char	*new_line;
	int		endl;
	size_t	i;

	i = 0;
	endl = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	endl = buf[i] == '\n';
	new_line = (char *)malloc((ft_strlen(*line) + i + endl + 1) * sizeof(char));
	ft_strlcpy(new_line, *line, ft_strlen(*line) + 1);
	ft_strlcpy(new_line, *buf, ft_strlen(*line) + i + 1);
	free(*line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		read_n;
	char		*line;

	read_n = 1;
	line = (char *)malloc(0);
	while (read_n)
	{
		read_n = read(fd, buf, BUFFER_SIZE);
		if (read_n < 0)
			return (NULL);
		buf[BUFFER_SIZE] = '\0';
		line = ft_get_line(line, buf);
		buf = ft_trim_buffer(buf);
		
	}
	return (line);
}
