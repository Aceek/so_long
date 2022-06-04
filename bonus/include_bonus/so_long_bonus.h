/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:47:45 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/04 07:25:37 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*pj;
	void	*coin;
	void	*out;
	void	*back;
	void	*bomb;
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
	int	c;
	int	p;
	int	e;
}	t_map;

// Check_error.c

void	ft_destroy_tab(char **tab);
int		write_error(int error);
int		check_name(char *map_name);
char	**create_map(int fd, t_game *game);
int		ft_check_error(int ac, char *path, char ***map, t_game *game);

// check_map.c

int		ft_check_wall(char **map);
int		ft_check_carac(char c, t_map *conso);
int		ft_check_mid(char **map, t_map *conso, t_game *game);
int		ft_check_map(char **map, t_game *game);

// game.c

void	ft_init_img(t_game *game);
void	ft_put_img(t_game *game, int i, int j);
void	ft_display_map(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		ft_show(char **map, t_game *game);

// move.c

void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);

// game_utils.c

int		ft_clean_cool(t_game *game);
void	ft_count_move(int *move);
void	ft_print_move(t_game *game);

#endif