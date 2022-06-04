/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:25:16 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/04 04:49:24 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_up(t_game *game)
{
	int		i;
	int		j;

	j = game->player_pos_x;
	i = game->player_pos_y;
	if (game->map[i - 1][j] != '1')
	{
		if (game->map[i - 1][j] == 'C')
			game->collectible -= 1;
		if (game->map[i - 1][j] == 'E' && game->collectible == 0)
		{
			ft_count_move(&game->move);
			ft_clean_cool(game);
		}
		if (game->map[i - 1][j] == 'E' && game->collectible > 0)
			return ;
		game->map[i - 1][j] = 'P';
		game->map[i][j] = '0';
		ft_count_move(&game->move);
		ft_display_map(game);
	}
}

void	ft_down(t_game *game)
{
	int		i;
	int		j;

	j = game->player_pos_x;
	i = game->player_pos_y;
	if (game->map[i + 1][j] != '1')
	{
		if (game->map[i + 1][j] == 'C')
			game->collectible -= 1;
		if (game->map[i + 1][j] == 'E' && game->collectible == 0)
		{
			ft_count_move(&game->move);
			ft_clean_cool(game);
		}
		if (game->map[i + 1][j] == 'E' && game->collectible > 0)
			return ;
		game->map[i + 1][j] = 'P';
		game->map[i][j] = '0';
		ft_count_move(&game->move);
		ft_display_map(game);
	}
}

void	ft_left(t_game *game)
{
	int		i;
	int		j;

	j = game->player_pos_x;
	i = game->player_pos_y;
	if (game->map[i][j - 1] != '1')
	{
		if (game->map[i][j - 1] == 'C')
			game->collectible -= 1;
		if (game->map[i][j - 1] == 'E' && game->collectible == 0)
		{
			ft_count_move(&game->move);
			ft_clean_cool(game);
		}
		if (game->map[i][j - 1] == 'E' && game->collectible > 0)
			return ;
		game->map[i][j - 1] = 'P';
		game->map[i][j] = '0';
		ft_count_move(&game->move);
		ft_display_map(game);
	}
}

void	ft_right(t_game *game)
{
	int		i;
	int		j;

	j = game->player_pos_x;
	i = game->player_pos_y;
	if (game->map[i][j + 1] != '1')
	{
		if (game->map[i][j + 1] == 'C')
			game->collectible -= 1;
		if (game->map[i][j + 1] == 'E' && game->collectible == 0)
		{
			ft_count_move(&game->move);
			ft_clean_cool(game);
		}
		if (game->map[i][j + 1] == 'E' && game->collectible > 0)
			return ;
		game->map[i][j + 1] = 'P';
		game->map[i][j] = '0';
		ft_count_move(&game->move);
		ft_display_map(game);
	}
}
