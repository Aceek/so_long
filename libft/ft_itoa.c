/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:06:26 by ilinhard          #+#    #+#             */
/*   Updated: 2022/04/25 05:48:43 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int			count;
	long int	nbr;

	count = 0;
	nbr = n;
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 10;
	}
	return (count);
}

char	*ft_put_nbr(char *str, unsigned int number, int len)
{
	while (number > 0)
	{
		str[len] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*str;
	long int	nbr;

	count = ft_count(n);
	nbr = n;
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	ft_put_nbr(str, nbr, count - 1);
	str[count] = '\0';
	return (str);
}
