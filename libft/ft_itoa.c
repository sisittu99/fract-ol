/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdrudi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:37:45 by fdrudi            #+#    #+#             */
/*   Updated: 2022/01/18 18:38:02 by fdrudi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int	div;

	div = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		div *= 10;
		len--;
	}
	return (div);
}

static void	ft_neg(int *n, char *dest, int *i, int *len)
{
	if (*n == -2147483648)
	{
		*n = 147483648;
		dest[0] = '-';
		dest[1] = '2';
		*i += 2;
		*len -= 2;
	}
	if (*n < 0)
	{
		*n *= -1;
		dest[0] = '-';
		*i += 1;
		*len -= 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	i = 0;
	len = ft_intlen(n);
	len2 = len;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	if (n == -2147483648 || n < 0)
		ft_neg(&n, dest, &i, &len);
	while (i < len2)
	{
		dest[i] = ((n / ft_div(len)) % 10) + 48;
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
