/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:53:07 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/22 17:38:45 by mcerchi          ###   ########.fr       */
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
	if (n < 0 || k < 0)
		return (0);
	return (factorial(n) / (factorial(n - k) * factorial(k)));
}
#include <stdio.h>
//be careful! This is supposed to be used with complex numbers, so we multiply -1 where needed.
void	ft_newton_bin(t_cpx *a, int n, long double real_c, long double img_c)
{
	t_cpx	tmp;
	int		k;

	tmp = *a;
	k = 0;
	if (n <= 0)
	{
		ft_putstr_fd("wrong exp! Exit", 2);
	}
	while (k <= n)
	{
		if (k % 4 == 0)
			tmp.x = coeff(n, k) * pow(a->x, n - k) * pow(a->y, k);
		else if (k % 4 == 2)
			tmp.x = coeff(n, k) * pow(a->x, n - k) * pow(a->y, k) * -1;
		else if (k % 4 == 1)
			tmp.y = coeff(n, k) * pow(a->x, n - k) * pow(a->y, k);
		else if (k % 4 == 3)
			tmp.y = coeff(n, k) * pow(a->x, n - k) * pow(a->y, k) * -1;
		*a = tmp;
		tmp = *a;
		printf("a.x = %Lf\na.y = %Lf\n", a->x, a->y);
		k++;
	}
	a->x += real_c;
	a->y += img_c;
}

// int main()
// {
// 	t_cpx a, b, constant;
// 	double tmp;

// 	a.x = 1.0;
// 	a.y = 1.0;
// 	b.x = 1.0;
// 	b.y = 1.0;
// 	// tmp = 0.0;
// 	constant.x = 4;
// 	constant.y = 4;

// 	tmp = b.x * b.x - b.y * b.y + constant.x;
// 	b.y = 2 * b.y * b.x + constant.y;
// 	b.x = tmp;
// 	ft_newton_bin(&a, 2, constant.x, constant.y);
// 	printf("\n\na.x=\t%f\t\ta.y=\t%f\n", a.x, a.y);
// 	printf("b.x=\t%f\t\tb.y=\t%f\n", b.x, b.y);
// }

