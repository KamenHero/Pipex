/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:26:32 by oryadi            #+#    #+#             */
/*   Updated: 2022/10/15 11:26:33 by oryadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;
	size_t	lendst;

	i = 0;
	lensrc = ft_strlen(src);
	if (!dst && !dstsize)
		return (lensrc);
	lendst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= lendst)
		return (lensrc + dstsize);
	if (dstsize != 0)
	{
		while (src[i] && i < dstsize - lendst - 1)
		{
			dst[lendst + i] = src[i];
			i++;
		}
		dst[lendst + i] = '\0';
	}
	return (lensrc + lendst);
}
