/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:04:27 by ilinhard          #+#    #+#             */
/*   Updated: 2022/04/25 04:01:35 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		new = malloc(sizeof(char) * 1);
		new[0] = '\0';
		return (new);
	}
	if (ft_strlen(s) < len + start)
			len = ft_strlen(s) - start;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (s[start + i] != '\0' && len)
	{
		new[i] = s[start + i];
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
