/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_mult_n_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:08:13 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/14 17:08:13 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

t_cpx	ft_mult_cpx(t_cpx a, t_cpx b)
{
	t_cpx	mult;

	mult.x = (a.x * b.x) - (a.y * b.y);
	mult.y = (a.x * b.y) + (a.y * b.x);
	return (mult);
}

t_cpx	ft_div_cpx(t_cpx a, t_cpx b)
{
	double	const_div;
	t_cpx		to_div;

	const_div = 1 / (pow(b.x, 2) + pow(b.y, 2));
	to_div.x = (a.x * b.x) + (a.y * b.y);
	to_div.y = (a.y * b.x) - (a.x * b.y);
	ft_real_const_cpx(&to_div, const_div);
	return (to_div);
}

void	ft_sqr_cpx(t_cpx *a, double real_c, double img_c)
{
	t_cpx	tmp;

	tmp = *a;
	a->x = pow(tmp.x, 2) - pow(tmp.y, 2) + real_c;
	a->y = 2 * tmp.x * tmp.y + img_c;
}

t_cpx	ft_power_cpx(t_cpx a, int n)
{
	t_cpx	tmp;

	tmp = a;
	if (n == 0)
	{
		tmp.x = 0;
		tmp.y = 0;
		return (tmp);
	}
	if (n == 1)
		return (tmp);
	tmp = ft_power_cpx(a, n / 2);
	if (n % 2 == 0)
		return (ft_mult_cpx(tmp, tmp));
	return (ft_mult_cpx(a, ft_mult_cpx(tmp, tmp)));
}
