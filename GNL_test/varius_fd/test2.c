/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:05:36 by alex              #+#    #+#             */
/*   Updated: 2024/11/18 19:59:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

//creo que el numerod de archivos se podria definir en funcion de una variadica

//Tambien se puede hacer un array de punteros, y que cada elemento apunte a un elemento de array
//de fd y que el ultimo sea nulo para tener un control

void    ft_putstr_fd(char *s, int fd)
{
        while (*s)
        {
                write(fd, s, 1);
                s++;
        }
}

int	main(void)
{
	int	i;   
        int	j;
        int	x;
        char	*s;
	int	fd[3];
	char	*files[] = {"/home/alex/GNL/GNL_imputs/Antonio Machado",
		"/home/alex/GNL/GNL_imputs/Foyone",
		"/home/alex/GNL/GNL_imputs/KikoVeneno",
		NULL};
	
	s = NULL;
	x = 0;
	i = 0;
	j = 0;
	while (i < 3)
	{
		fd[i] = open(files[i], O_RDONLY);
		if (fd[i] <= 0)
		{
			printf("error en la apertura de %s\n", files[i]);
			return (0);
		}
		i++;
	}
	while ((x == 0 || s != NULL) && j < 3)
	{
		x = 1;
		s = get_next_line(fd[j]);
		printf("linea perteneciente a fd = %d\n", fd[j]);
		ft_putstr_fd(s, 0);
		j++;
		if (j == 3)
			j = 0;
	}
	printf("se sale del bucle");
	j = 0;
	while(j < 3)
		close(fd[j]);
	return(0);

}
