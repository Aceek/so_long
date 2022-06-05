/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:22:05 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/05 03:20:38 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_clean_cool(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->out);
	mlx_destroy_image(game->mlx, game->pj);
	mlx_destroy_image(game->mlx, game->coin);
	mlx_destroy_image(game->mlx, game->bomb1);
	mlx_destroy_image(game->mlx, game->bomb2);
	mlx_destroy_image(game->mlx, game->bomb3);
	mlx_destroy_image(game->mlx, game->bomb4);
	mlx_destroy_image(game->mlx, game->back);
	mlx_destroy_display(game->mlx);
	ft_destroy_tab(game->map);
	free(game->mlx);
	exit (0);
}

void	ft_count_move(int *move)
{
	*move += 1;
	ft_putnbr_fd(*move, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_print_move(t_game *game)
{	
	char	*line;

	line = ft_itoa(game->move);
	mlx_string_put(game->mlx, game->win, 22, 35, 0xff0000, line);
	free (line);
}
