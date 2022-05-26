/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:44:37 by ilinhard          #+#    #+#             */
/*   Updated: 2022/04/20 23:12:34 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (s1 || s2)
	{
		i = 0;
		j = 0;
		new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (new == NULL)
			return (NULL);
		while (s1 && s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		while (s2 && s2[j] != '\0')
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = '\0';
		return (new);
	}
	return (NULL);
}
