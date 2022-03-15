/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:54:37 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/14 16:54:37 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_lib.h"

t_cpx	ft_create_cpx(float x, float y)
{
	t_cpx	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_cpx	ft_add_cpx(t_cpx a, t_cpx b)
{
	t_cpx	added;

	added.x = a.x + b.x;
	added.y = a.y + b.y;
	return (added);
}

t_cpx	ft_sub_cpx(t_cpx a, t_cpx b)
{
	t_cpx	sub;

	sub.x = a.x - b.x;
	sub.y = a.y - b.y;
	return (sub);
}

void	ft_real_const_cpx(t_cpx *a, float c)
{
	(*a).x *= c;
	(*a).y *= c;
}


