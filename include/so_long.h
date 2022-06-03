/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:47:45 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/03 06:29:01 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*pj;
	void	*coin;
	void	*out;
	void	*back;
	char	**map;
	int		height;
	int		width;
	int		width_map;
	int		height_map;
	int		player_pos_x;
	int		player_pos_y;
	int		move;
	int		collectible;
}			t_game;

typedef struct s_map
{
	int	C;
	int	P;
	int	E;
}	t_map;

int		ft_check_error(int ac, char *path, char ***map, t_game *game);
char	**create_map(int fd, t_game *game);
int		check_name(char *map_name);
int		write_error(int error);
void	ft_destroy_tab(char **tab);
int		ft_check_map(char **map, t_game *game);

int	ft_show(char **map, t_game *game);
int	ft_clean_cool(t_game *game);
void	ft_up(t_game *game);
void	ft_display_map(t_game *game);

#endif