/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:20:33 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/03 02:43:49 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		error;
	char	**map;
	t_game	game;

	error = ft_check_error(ac, av[1], &map, &game);
	if (error < 0)
		return (write_error(error));
	ft_show(map, &game);
	ft_destroy_tab(map);
	return (0);
}
