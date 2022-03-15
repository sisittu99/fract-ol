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
	mult.y = (a.x * b.y) - (a.y * b.x);
	return (mult);
}

t_cpx	ft_div_cpx(t_cpx a, t_cpx b)
{
	float	const_div;
	t_cpx	to_div;

	const_div = 1 / (pow(b.x, 2) + pow(b.y, 2));
	to_div.x = (a.x * b.x) + (a.y * b.y);
	to_div.y = (a.y * b.x) - (a.x * b.y);
	ft_real_const_cpx(&to_div, const_div);
	return (to_div);
}

void	ft_sqr_cpx(t_cpx *a)
{
	t_cpx	tmp;

	tmp = ft_create_cpx(pow((*a).x, 2), pow((*a).y, 2));
	*a = tmp;
}
