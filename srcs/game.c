/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 00:54:18 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/03 03:15:17 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_game *game)
{
	game->out = mlx_xpm_file_to_image(game->mlx, "./xpm/door_back.xpm",
			&game->width, &game->height);
	game->coin = mlx_xpm_file_to_image(game->mlx, "./xpm/bomb_back.xpm",
			&game->width, &game->height);	
	game->pj = mlx_xpm_file_to_image(game->mlx, "./xpm/king_back.xpm",
			&game->width, &game->height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./xpm/wall.xpm",
			&game->width, &game->height);
	game->back = mlx_xpm_file_to_image(game->mlx, "./xpm/back.xpm",
			&game->width, &game->height);
}

void	ft_put_img(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
				(i * 64), (j * 64));
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->back,
				(i * 64), (j * 64));
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->pj,
				(i * 64), (j * 64));
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->coin,
				(i * 64), (j * 64));
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->out,
				(i * 64), (j * 64));
}

void	ft_display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			ft_put_img(game, i, j);
			j++;
		}
		i++;
	}
}

int	ft_show(char **map, t_game *game)
{
	game->map = map;
	game->mlx = mlx_init();
	ft_init_img(game);
	game->win = mlx_new_window(game->mlx, game->height_map * 64,
			game->width_map * 64, "so_long");
	ft_display_map(game);
	mlx_loop(game->mlx);
	return (0);
}
