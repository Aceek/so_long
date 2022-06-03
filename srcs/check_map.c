/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:41:02 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/03 02:43:09 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	if (i < 3)
		return (-1);
	while (map[0][j] != '\0')
		if (map[0][j++] != '1')
			return (-1);
	i--;
	j = 0;
	while (map[i][j] != '\0')
		if (map[i][j++] != '1')
			return (-1);
	return (0);
}

int	ft_check_carac(char c, t_map *conso)
{
	if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'C')
		return (conso->C += 1, 0);
	else if (c == 'P')
		return (conso->P += 1, 0);
	else if (c == 'E')
		return (conso->E += 1, 0);
	return (-1);
}

int	ft_check_mid(char **map, t_map *conso, t_game *game)
{
	int	ref;
	int	i;
	int	j;

	i = 0;
	ref = (int)ft_strlen(map[i]);
	if (ref < 3)
		return (-1);
	game->width_map = ref;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_check_carac(map[i][j], conso) == -1)
				return (-1);
			j++;
		}
		if (j != ref)
			return (-1);
		if (map[i][j - 1] != '1' || map[i][0] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_map(char **map, t_game *game)
{
	t_map	conso;

	conso.C = 0;
	conso.E = 0;
	conso.P = 0;
	if (ft_check_wall(map) == -1)
		return (-1);
	if (ft_check_mid(map, &conso, game) == -1)
		return (-1);
	if (conso.C == 0 || conso.E == 0 || conso.P != 1)
		return (-1);
	return (0);
}
