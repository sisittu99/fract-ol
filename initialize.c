/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:11:41 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/25 15:36:39 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	which_function(t_env *e)
{
	e->var.mandelbrot = 2;
	e->var.julia.x = 0;
	e->var.julia.y = 0;
	e->var.burning = 0;
	if (e->argc < 2)
		print_calls();
	else if (!ft_strncmp(e->argv[1], "mandelbrot", 10))
	{
		if (!e->argv[2])
			print_calls();
		if (e->argv[2][0] > '0' && e->argv[2][0] <= '9')
		{
			e->var.mandelbrot = ft_atoi(e->argv[2]);
			e->function = &ft_mandelbrot_math;
		}
		else
			print_calls();
	}
	else if (!ft_strncmp(e->argv[1], "julia", 5))
	{
		e->var.julia.x = 0.285;
		e->var.julia.y = 0.01;
		e->function = &ft_julia;
	}
	else if (!ft_strncmp(e->argv[1], "burning_ship", 13))
	{
		e->var.burning = 1;
		e->function = &ft_burning_ship;
	}
	else
		print_calls();
}

void	ft_init_e(t_env *e)
{
	e->col.r = 0;
	e->col.g = 0;
	e->col.b = 0;
	e->col.palette = 0;
	e->mlx.virt_min.x = -2;
	e->mlx.virt_max.x = 2;
	e->mlx.virt_min.y = -2;
	e->mlx.virt_max.y = 2;
	e->mlx.zoom = 1.0f;
	e->img.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bits_per_pixel,
			&e->img.line_length, &e->img.endian);
}
