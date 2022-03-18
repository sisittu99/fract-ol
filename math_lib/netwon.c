/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:53:07 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/18 13:11:52 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

int	factorial(int nb)
{
	int	f;

	f = nb;
	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	else
		f *= factorial(nb - 1);
	return (f);
}

int	coeff(int n, int k)
{
	return (factorial(n) / (factorial(n - k) * factorial(k)));
}

void	ft_newton_bin(t_cpx *a, int n, double real_c, double img_c)
{
	t_cpx	tmp;
	int		k;

	tmp = *a;
	k = 0;
	while (k <= n)
	{
		if (k % 4 == 0)
			a->x += coeff(n, k) * pow(tmp.x, n - k) * pow(tmp.y, k);
		else if (k % 4 == 2)
			a->x += coeff(n, k) * pow(tmp.x, n - k) * pow(tmp.y, k) * -1;
		else if (k % 4 == 1)
			a->y += coeff(n, k) * pow(tmp.x, n - k) * pow(tmp.y, k);
		else if (k % 4 == 3)
			a->y += coeff(n, k) * pow(tmp.x, n - k) * pow(tmp.y, k) * -1;
		k++;
	}
	a->x += real_c;
	a->y += img_c;
}
