/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:47:45 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/02 08:16:16 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

	int	ft_check_error(int ac, char *path, char ***map);
char	**create_map(int fd);
int		check_name(char *map_name);
int		write_error(int error);
void	ft_destroy_tab(char **tab);
int		ft_check_map(char **map);

typedef struct s_map
{
	int	C;
	int	P;
	int	E;
}	t_map;

// typedef struct s_img {
// 	void	*img;
// 	char	*addr;
// 	int		bit_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		height;
// 	int		width;
// 	char	*path;
// }			t_img;

// typedef struct s_game {
// 	void	*mlx;
// 	void	*win;
// }			t_game;

#endif