/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:06:44 by nilim             #+#    #+#             */
/*   Updated: 2026/08/09 14:39:40 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(const char *str, size_t n)
{
	size_t	c;

	c = 0;
	while (str[c] && c < n)
		c++;
	return (c);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	dsize;
	size_t	orilength;

	n = 0;
	dsize = ft_strlen(dst);
	orilength = ft_strnlen(dst, size) + ft_strlen(src);
	if (!dst || !src || !size)
		return (orilength);
	while (n < dsize)
		n++;
	while (n < size - 1)
	{
		dst[n] = *src;
		n++;
		src++;
	}
	dst[n] = '\0';
	return (orilength);
}
