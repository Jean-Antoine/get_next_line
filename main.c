/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:51:33 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/20 14:53:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Something went wrong.\n", 22);
	}
	i = 0;
	while (i < 4)
	{
		__builtin_printf("Reading line %d\n", i++);
		line = get_next_line(fd);
		__builtin_printf("%s", line);
		if (!line)
		{
			break;
		}
		free(line);
	}	
	close(fd);
	return (1);
}
