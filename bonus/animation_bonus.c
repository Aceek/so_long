/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 01:28:24 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/05 03:15:37 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_bomb(t_game *game)
{
	game->bomb1 = mlx_xpm_file_to_image(game->mlx, "./xpm/bomb1.xpm",
			&game->width, &game->height);
	game->bomb2 = mlx_xpm_file_to_image(game->mlx, "./xpm/bomb2.xpm",
			&game->width, &game->height);
	game->bomb3 = mlx_xpm_file_to_image(game->mlx, "./xpm/bomb3.xpm",
			&game->width, &game->height);
	game->bomb4 = mlx_xpm_file_to_image(game->mlx, "./xpm/bomb4.xpm",
			&game->width, &game->height);
}

int	ft_animate(t_game *game, int i, int j)
{
	if (game->pos == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->bomb1,
			(j * 64), (i * 64));
	else if (game->pos == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->bomb2,
			(j * 64), (i * 64));
	else if (game->pos == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->bomb3,
			(j * 64), (i * 64));
	else if (game->pos == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->bomb4,
			(j * 64), (i * 64));
	game->pos++;
	if (game->pos >= 3)
		game->pos = 0;
	return (0);
}
