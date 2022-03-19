/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:39:19 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/18 18:39:22 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	y;
	unsigned char	*p;

	p = (unsigned char *) s;
	y = (unsigned char) c;
	x = 0;
	while (x < n)
	{
		if (p[x] == y)
			return ((void *)(p + x));
		x++;
	}
	return (NULL);
}
