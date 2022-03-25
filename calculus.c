/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:43:53 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/25 15:16:35 by mcerchi          ###   ########.fr       */
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

t_cpx	mandelbrot_calc(t_bool var, t_cpx val, t_cpx constant)
{
	val = ft_power_cpx(val, var.mandelbrot);
	val = ft_add_cpx(val, constant);
	return (val);
}

int	ft_mandelbrot_math(t_vars mlx, t_bool var, int x, int y)
{
	int			i;
	t_cpx		val;
	t_cpx		constant;

	i = 0;
	val.x = 0.0;
	val.y = 0.0;
	constant = virtual_to_real(mlx, x, y);

	while (i < 20)
	{
		val = mandelbrot_calc(var, val, constant);
		if (pow(val.x, 2) + pow(val.y, 2) > 2.0 * 2.0)
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

	i = 0;
	val = virtual_to_real(mlx, x, y);
	constant = var.julia;

	while (i < 20)
	{
		// ft_newton_bin(&val, 2, constant.x, constant.y);
		val = mandelbrot_calc(var, val, constant);
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

	i = 0;
	val.x = 0.0;
	val.y = 0.0;
	constant = virtual_to_real(mlx, x, y);
	while (i < 20 && var.julia.x == 0.0)
	{
		val = mandelbrot_calc(var, val, constant);
		val.x = fabsl(val.x);
		val.y = fabsl(val.y);
		if (pow(val.x, 2) + pow(val.y, 2) > 2.0*2.0)
			break ;
		i++;
	}
	return (i);
}
