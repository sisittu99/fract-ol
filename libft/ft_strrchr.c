/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:35:43 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/18 17:18:24 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	if (!len && c == '\0')
		return ((char *)s);
	s += len - 1;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	while (len--)
	{
		if (*s == (char) c)
			return ((char *) s);
		s--;
	}
	return (0);
}
