/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:08:35 by alex              #+#    #+#             */
/*   Updated: 2024/11/30 17:30:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static void	***tree;
	char		*buffer;
	char		*out_line;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
	{
		return (free_all(tree, buffer));
	}
	tree = create_tree_branches(tree, fd);
	if (!tree)
		return (free_all(tree, buffer));
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
	{
		return (free_all(tree, buffer));
	}
	tree = read_imput_controler(tree, buffer, fd);
	if (!tree || !tree[fd] || !tree[fd][3])
	{
		return (free_all(tree, buffer));
	}
	out_line = (char *)gnl_out_line_controler(tree, fd, 0, buffer);
	return (free(buffer), out_line);
}

void	***read_imput_controler(void ***tree, char *buffer, int fd)
{
	ssize_t	readed;
	ssize_t	len_out_line;

	if (tree[fd][3] != NULL)
		tree[fd][3] = gnl_out_line_controler(tree, fd, 1, buffer);
	len_out_line = ((ssize_t *)tree[fd][0])[0];
	while (!tree[fd][3] || ((char *)tree[fd][3])[len_out_line - 1] != '\n')
	{
		if (fd >= 3 && ((ssize_t *)tree[fd][1])[0] == 1)
			break ;
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
		{
			((ssize_t *)tree[fd][1])[0] = 1;
			break ;
		}
		if (readed < BUFFER_SIZE)
			((ssize_t *)tree[fd][1])[0] = 1;
		tree[fd] = ft_split_lines(tree[fd], buffer, readed);
		if (!tree[fd] || !tree[fd][3])
			return (NULL);
		len_out_line = ((ssize_t *)tree[fd][0])[0];
	}
	return (tree);
}

void	**ft_split_lines(void **ta, char *s, ssize_t readed)
{
	ssize_t	i;
	ssize_t	b;
	ssize_t	e;
	ssize_t	cl;

	i = -1;
	cl = -1;
	while (++i < readed && readed != 0)
	{
		if (i == 0 || (i >= 1 && s[i - 1] == '\n'))
			b = i;
		if (i == (readed - 1) || s[i] == '\n')
		{
			e = i;
			ta = ft_redim_fill_table(ta, ++cl, ((ssize_t *)ta[2])[0]);
			if (!ta)
				return (NULL);
			ta[cl + 3] = l(((char *)ta[cl + 3]), &s[b], ((ssize_t *)ta[0])[cl],
					(e - b + 1));
			if (!ta[cl + 3])
				return (NULL);
			((ssize_t *)ta[0])[cl] = (e - b + 1) + ((ssize_t *)ta[0])[cl];
		}
	}
	return (ta);
}

char	*l(char *line, char *buffer, ssize_t len, ssize_t cut)
{
	char	*ptr;
	void	*aux_line;
	ssize_t	total_len;
	ssize_t	i;
	ssize_t	j;

	aux_line = line;
	total_len = len + cut;
	if (total_len == 0)
		return (NULL);
	ptr = (char *)malloc(total_len + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	i = -1;
	while ((++i <= (total_len - 1)) && i < len)
		ptr[i] = line[i];
	while ((i <= (total_len - 1)) && j <= cut)
		ptr[i++] = buffer[j++];
	ptr[i] = '\0';
	free(aux_line);
	return (ptr);
}

void	*gnl_out_line_controler(void ***tree, int fd, char flag, char *buffer)
{
	ssize_t	i;
	ssize_t	l_len;

	if (flag)
	{
		i = -1;
		free(tree[fd][3]);
		while (tree[fd][++i + 3] != NULL)
		{
			tree[fd][i + 3] = tree[fd][i + 3 + 1];
			((ssize_t *)tree[fd][0])[i] = ((ssize_t *)tree[fd][0])[i + 1];
		}
		return (tree[fd][3]);
	}
	else
	{
		l_len = ((ssize_t *)tree[fd][0])[0];
		if (tree[fd][3] && (((char *)tree[fd][3])[l_len - 1] == '\n'
				|| (((char *)tree[fd][3])[l_len] != '\n'
					&& ((ssize_t *)tree[fd][1])[0] == 1)))
		{
			return ((tree[fd][3]));
		}
		return (free_all(tree, buffer));
	}
}
