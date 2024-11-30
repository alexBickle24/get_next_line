/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:01:10 by carbon-m          #+#    #+#             */
/*   Updated: 2024/11/21 19:22:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_until_jump(char *s_buffer, int fd)
{
	char	*tr_buffer;
	int		readed;

	if (!s_buffer)
		s_buffer = ft_calloc_gnl (1, BUFFER_SIZE + 1);
	tr_buffer = ft_calloc_gnl (1, BUFFER_SIZE + 1);
	if (!tr_buffer)
		return (NULL);
	while (!ft_strchr(s_buffer, 10))
	{
		readed = read (fd, tr_buffer, BUFFER_SIZE);
		if (readed < 0)
		{
			free(s_buffer);
			free(tr_buffer);
			return (NULL);
		}
		if (readed == 0)
			break ;
		tr_buffer[readed] = 0;
		s_buffer = ft_strjoin_gnl(s_buffer, tr_buffer);
	}
	free(tr_buffer);
	return (s_buffer);
}

char	*full_line(char *s_buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!s_buffer[i])
		return (NULL);
	while (s_buffer[i] != 10 && s_buffer[i])
		++i;
	line = ft_calloc_gnl(1, i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = s_buffer[j];
		++j;
	}
	if (s_buffer[i] == 0)
		line[j] = 10;
	return (line);
}

char	*rest_buffer(char *s_buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (s_buffer[i] && s_buffer[i] != '\n')
		i++;
	if (!s_buffer[i])
	{
		free(s_buffer);
		return (NULL);
	}
	new_buffer = ft_calloc_gnl((ft_strlen(s_buffer) - i + 1), sizeof(char));
	i += 1;
	j = 0;
	while (s_buffer[i])
	{
		new_buffer[j] = s_buffer[i];
		++i;
		++j;
	}
	free(s_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	s_buffer[fd] = read_until_jump(s_buffer[fd], fd);
	if (!s_buffer[fd])
		return (NULL);
	line = full_line(s_buffer[fd]);
	s_buffer[fd] = rest_buffer(s_buffer[fd]);
	return (line);
}
