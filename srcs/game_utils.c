/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:22:05 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/03 05:22:25 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clean_cool(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->out);
	mlx_destroy_image(game->mlx, game->pj);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->back);
	mlx_destroy_display(game->mlx);
	ft_destroy_tab(game->map);
	free(game->mlx);
	exit (0);
}
