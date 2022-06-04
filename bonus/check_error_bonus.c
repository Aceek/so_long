/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:17:15 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/04 06:27:56 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free (tab[i++]);
	free (tab);
}

int	write_error(int error)
{
	if (error == -1)
		ft_putstr_fd("Errors\nWrong arg number\n", 2);
	else if (error == -2)
		ft_putstr_fd("Errors\nMap format .ber\n", 2);
	else if (error == -3)
		ft_putstr_fd("Errors\nCan't open file\n", 2);
	else if (error == -4)
		ft_putstr_fd("Errors\nInvald map", 2);
	else
		ft_putstr_fd("Errors\n", 2);
	return (-1);
}

int	check_name(char *map_name)
{
	int	i;

	i = (int)ft_strlen(map_name);
	if (i < 4)
		return (-1);
	else if (ft_strnstr(&map_name[i - 4], ".ber", 4) == NULL)
		return (-1);
	return (0);
}

char	**create_map(int fd, t_game *game)
{
	char	*line;
	char	*map_str;
	char	**map;
	int		i;

	i = 0;
	map_str = malloc(sizeof(char) * 1);
	if (!map_str)
		return (NULL);
	map_str[0] = '\0';
	game->height_map = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_str = ft_strjoin2(map_str, line);
		game->height_map += 1;
		free(line);
	}
	while (map_str[i++])
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
			return (free(map_str), NULL);
	map = ft_split(map_str, '\n');
	return (free(map_str), map);
}

int	ft_check_error(int ac, char *path, char ***map, t_game *game)
{
	int		fd;

	if (ac != 2)
		return (-1);
	if (check_name(path) == -1)
		return (-2);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-3);
	*map = create_map(fd, game);
	if (*map == NULL)
		return (close (fd), -4);
	if (ft_check_map(*map, game) == -1)
		return (ft_destroy_tab(*map), close (fd), -4);
	close (fd);
	return (0);
}
