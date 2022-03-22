/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:43:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/22 17:43:10 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cpx	virtual_to_real(t_vars mlx, int x, int y)
{
	t_cpx	res;

	res.x = mlx.virt_min.x + ((x * (mlx.virt_max.x - mlx.virt_min.x)) / WIDTH);
	res.y = mlx.virt_min.y + ((y * (mlx.virt_max.y - mlx.virt_min.y)) / WIDTH);
	return (res);
}

int	ft_mandelbrot_math(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cpx		val;
	t_cpx		constant;
	long double	tmp;

	i = 0;
	val.x = 0.0;
	val.y = 0.0;
	tmp = 0.0;
	constant = virtual_to_real(mlx, x, y);

	while (i < 1000 && var.mandelbrot == 2)
	{
		// ft_newton_bin(&val, var.mandelbrot, constant.x, constant.y);
		tmp = val.x * val.x - val.y * val.y + constant.x;
		val.y = 2 * val.y * val.x + constant.y;
		val.x = tmp;
		if (pow(val.x, 2) + pow(val.y, 2) > 2.0*2.0)
			break ;
		i++;
	}
	return (i);
}

int	ft_julia(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cpx		val;
	t_cpx		constant;
	long double	tmp;

	i = 0;
	tmp = 0.0;
	val = virtual_to_real(mlx, x, y);
	constant = var.julia;

	while (i < 100)
	{
		// ft_newton_bin(&val, 2, constant.x, constant.y);
		tmp = val.x * val.x - val.y * val.y + constant.x;
		val.y = 2 * val.y * val.x + constant.y;
		val.x = tmp;
		if (pow(val.x, 2) + pow(val.y, 2) > 2.0*2.0)
			break ;
		i++;
	}
	return (i);
}

int	ft_burning_ship(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cpx		val;
	t_cpx		constant;
	long double	tmp;

	i = 0;
	tmp = 0.0;
	val.x = 0.0;
	val.y = 0.0;
	constant = virtual_to_real(mlx, x, y);


	while (i < 100 && var.julia.x == 0.0)
	{
		tmp = fabsl(val.x * val.x - val.y * val.y + constant.x);
		val.y = fabsl(2 * val.y * val.x + constant.y);
		val.x = tmp;
		if (pow(val.x, 2) + pow(val.y, 2) > 2.0*2.0)
			break ;
		i++;
	}
	return (i);
}
