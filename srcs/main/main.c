/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <bben-yaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:19:45 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/11/04 12:49:45 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/so_long.h"

void	ft_free(char **map)
{
	int	i;
	int	curs;

	i = 0;
	curs = 0;
	while (curs < 5)
	{
		free(map[i]);
		curs++;
		i++;
	}
	free(map);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*copy;

	i = 0;
	while (s[i] != '\0')
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			if (map[i])
			{
				free(map[i]);
				map[i] = NULL;
			}
			i++;
		}
	}
	free(map);
	map = NULL;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_param	p;

	if (ft_parse_arg(argc, argv))
	{
		fd = open_fd(fd, argv);
		if (fd < 0)
			return (0);
		read_file(fd, &p);
		if (ft_len_malloc(&p) == 0)
			return (0);
		fd = open_fd(fd, argv);
		if (fd < 0)
			return (0);
		store_map(&p, fd);
		if (p.map && ft_parsing(p.map, &p))
		{
			ft_window(p.map, p.size_x, p.size_y, p.c);
			return (0);
		}
		else
			return (message_error(&p));
		free_map(p.map);
	}
	return (0);
}
