/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:49:47 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/12 14:34:38 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

int	open_fd(int fd, char **argv)
{
	char	buf[1];

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		printf("Error\n");
	else if (read(fd, buf, 1) <= 0)
	{
		printf("Error\n");
		return (-1);
	}
	return (fd);
}

int	ft_len_malloc(t_param *p)
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

void	read_file(int fd, t_param *p)
{
	char	*line;
	int		i;

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
		secure_line(line);
		i++;
	}
	secure_line(line);
	close(fd);
}

void	store_map(t_param *p, int fd)
{
	int	i;

	i = 0;
	while (i < p->nb_of_lines)
	{
		p->map[i] = get_next_line(fd, p, false);
		if (p->map[i][0] == ' ' || p->map[i][0] == '\n' || !p->map[i][0])
		{
			free(p->map[i]);
			p->map[i] = NULL;
			break ;
		}
		if (!p->map[i])
		{
			free(p->map[i]);
			break ;
		}
		i++;
	}
	p->map[i] = NULL;
	close(fd);
}

void	secure_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}
