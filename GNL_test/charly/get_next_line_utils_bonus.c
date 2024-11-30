/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carbon-m <carbon-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:04:57 by carbon-m          #+#    #+#             */
/*   Updated: 2024/10/26 15:17:43 by carbon-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	free (s1);
	return (res);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = size * nmemb;
	res = malloc(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = 0;
		++i;
	}
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}
