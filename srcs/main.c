/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:20:33 by ilinhard          #+#    #+#             */
/*   Updated: 2022/06/02 04:26:54 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int	error;

	error = ft_check_error(ac, av[1]);
	if (error < 0)
		return (write_error(error));
	return (0);
}
