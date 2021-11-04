/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:47 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/04 12:30:41 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int open_fd(int fd, char **argv)
{
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	    printf("Error\n");
    printf("fd = %d\n", fd);
    return (fd);
}

int ft_len_malloc(t_param *p)
{
    p->map = NULL;
    p->map = (char **)malloc(sizeof(char *) * (p->nb_of_lines + 1));
	if (!p->map)
	{
		printf("map existe pas\n");
		return (0);
	}
	return (1);
}

void    read_file(int fd, t_param *p)
{
    char    *line;
    int     i;

    line = NULL;
    i = 0;
    p->nb_of_lines = 0;
	while (1)
    {
    	line = get_next_line(fd, p, true);
		if (!line || !line[0])
		{
        	free(line);
			line = NULL;
			break ;
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
		i++;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
    close(fd);
}