/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:39:29 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/18 18:39:33 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*cp1;
	const unsigned char	*cp2;

	i = -1;
	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (cp1[i] != cp2[i])
			return ((unsigned int)(cp1[i] - cp2[i]));
	}
	return (0);
}
