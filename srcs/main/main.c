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
	int		i;
	int		curs;
	t_param	p;

	if (ft_parse_arg(argc, argv))
	{
		curs = 0;
		i = 0;
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("Error\n");
			return (0);
		} ////->fonction
		read_file(fd, &p);
		////////aloue **map
		fd = ft_len_malloc(&p);
		printf("fd vaut %d\n", fd);
		if (fd == 0)
		{
			printf("fd malloc de %d\n", fd);
			return(0);
		}
		/*map = (char **)malloc(sizeof(char *) * (p.nb_of_lines + 1));
		if (!map)
			return (0);*/
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("Error\n");
			return (0);
		}
		//Lecture pour sauvegarder les lignes
		while (i < p.nb_of_lines)
		{
			p.map[i] = get_next_line(fd, &p, false);
			if (p.map[i][0] == ' ' || p.map[i][0] == '\n' || !p.map[i][0])
			{
				free(p.map[i]);
				p.map[i] = NULL;
				break ;
			}
			if (!p.map[i])
			{
				free(p.map[i]);
				break ;
			}
			i++;
		}
		p.map[i] = NULL;
		close(fd);
		i = 0;
		if (p.map[i] && ft_parsing(p.map, &p))
		{
			ft_window(p.map, p.size_x, p.size_y, p.c);
			return (0);
		}
		else
		{
			printf("Error\n");
			free_map(p.map);
			return (-1);
		}
		free_map(p.map);
	}
	return (0);
}
