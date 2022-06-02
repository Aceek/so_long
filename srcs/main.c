/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:17:15 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/02 04:07:30 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**check_map(int fd)
{
	char	*line;
	char	*map_str;
	char	**map;

	if ((map_str = malloc(sizeof(char) * 1)) == NULL)
		return (NULL);
	map_str[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map_str = ft_strjoin2(map_str, line);
		free(line);
	}
	map = ft_split(map_str, '\n');
	free (map_str);
	ft_destroy_tab(map);
	return (map);
}

int	ft_check_error(int ac, char *path)
{
	int	fd;

	if (ac != 2)
		return (-1);
	else if (check_name(path) == -1)
		return (-2);
	else if ((fd = open(path, O_RDONLY)) == -1)
		return (-3);
	if (check_map(fd) == NULL)
		return (-1);

	close (fd);
	return (0);

}

int	main(int ac, char **av)
{
	int	error;

	if ((error = ft_check_error(ac, av[1])) < 0)
		return (write_error(error));
	return (0);
}