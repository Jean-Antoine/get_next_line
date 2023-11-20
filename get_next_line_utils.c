/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:01 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/20 15:10:37 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_buffer **lst, t_buffer *new)
{
	t_buffer	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n != 0)
		((unsigned char *)s)[--n] = (unsigned char)c;
	return (s);
}

int	cat_buffer(char **line, char *buf)
{
	char	*new_line;
	int		endl;
	size_t	line_len;
	size_t	i;

	i = 0;
	line_len = ft_strlen(*line);
	while (buf[i] && buf[i] != '\n')
		i++;
	endl = buf[i] == '\n';
	new_line = malloc(line_len + i + endl + 1);
	if (!new_line)
		return (0);
	ft_memset(new_line, '\0', line_len + i + endl + 1);
	ft_memcpy(new_line, *line, line_len);
	ft_memcpy(new_line + line_len, buf, i + endl);
	free(*line);
	*line = new_line;
	ft_memcpy(buf, &buf[i + endl], BUFFER_SIZE - i - endl + 1);
	buf[i + endl] = '\0';
	return (endl);
}
