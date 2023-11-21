/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:31:18 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/21 09:56:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_buffer
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	struct t_buffer	*next;
}	t_buffer;
void		ft_lstadd_back(t_buffer **lst, t_buffer *new);
t_buffer	*ft_lstlast(t_buffer *lst);
size_t		ft_strlen(const char *s);
int			cat_buffer(char **line, char *buf);
char		*get_next_line(int fd);

#endif
