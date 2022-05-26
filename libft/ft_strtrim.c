/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:18:25 by ilinhard          #+#    #+#             */
/*   Updated: 2022/04/25 04:31:34 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	k;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_is_set(s1[j - 1], set))
		j--;
	new = malloc(sizeof(char) * (j - i + 1));
	if (new == NULL)
		return (NULL);
	k = 0;
	while (s1[i + k] && (i + k) < j)
	{
		new[k] = s1[i + k];
		k++;
	}
	new[k] = '\0';
	return (new);
}
