/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 05:25:16 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/03 06:38:27 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_clean_cool(game);
		if (game->map[i - 1][j] == 'E' && game->collectible > 0)
			return ;
		game->map[i - 1][j] = 'P';
		game->map[i][j] = '0';
		ft_display_map(game);
	}
}