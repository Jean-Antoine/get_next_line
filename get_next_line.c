/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:32:48 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/15 11:51:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	size_t		read_n;
	char		*line;

	read_n = 1;
	while (read_n == BUFFER_SIZE)
	{
		read_n = read(fd, buf, line);
		if (read_n < 0)
		{
			free(buf);
			return (line);
		}
	}
	return (line);
}
