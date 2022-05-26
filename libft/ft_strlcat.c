/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilinhard <ilinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:45:38 by ilinhard          #+#    #+#             */
/*   Updated: 2022/04/18 18:55:07 by ilinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	dst_len_cpy;

	dst_len = ft_strlen(dst);
	dst_len_cpy = dst_len;
	if (dst_len >= size)
		return (size + ft_strlen(src));
	else
	{
		i = 0;
		while (dst_len < size - 1 && src[i])
		{
			dst[dst_len] = src[i];
			i++;
			dst_len++;
		}
		dst[dst_len] = '\0';
		return (ft_strlen(src) + dst_len_cpy);
	}
}
