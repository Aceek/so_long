/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:29:35 by ilinhard          #+#    #+#             */
/*   Updated: 2022/04/25 04:40:48 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	const char		*res;

	res = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if ((const char)c == s[i])
			res = &s[i];
		i++;
	}
	if ((const char)c == s[i])
		return ((char *)&s[i]);
	return ((char *)res);
}
