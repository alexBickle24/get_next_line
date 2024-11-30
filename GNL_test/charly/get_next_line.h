/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:54:10 by carbon-m          #+#    #+#             */
/*   Updated: 2024/11/21 15:31:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_calloc_gnl(size_t nmemb, size_t size);
size_t	ft_strlen(char *s);

#endif
