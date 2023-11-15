/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:51:33 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/15 11:37:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <fcntl.h>

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	int		line_n;
// 	char	*line;
	
// 	if (ac != 2)
// 		return (0);
// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write(2, "Something went wrong.\n", 22);
// 	}
// 	line = 10;
// 	while (line)
// 	{
// 		line--;
// 		if (line)
// 			free(line);
// 		line = get_next_line(fd);
// 		__builtin_printf("%s", line);
// 		free(line)
// 	}
// 	return (1);
// }

int	main(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 10);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	__builtin_printf("%zu\n", ft_strlen(str));
	__builtin_printf("%zu\n", sizeof(str));
	__builtin_printf("%zu\n", sizeof(&str[3]));
	free(str);
}
