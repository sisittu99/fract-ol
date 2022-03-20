/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:11:41 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/20 11:02:04 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_calls(void)
{
	ft_putstr_fd("Please write the function you want:\n", 2);
	ft_putstr_fd("1)\tmandelbrot [define the exponent too!]\n", 2);
	ft_putstr_fd("2)\tjulia\n", 2);
	ft_putstr_fd("3)\tburning_ship\n", 2);
	ft_putstr_fd("\n\n\nEx.:\t\"./fractol mandelbrot 5\"", 2);
	exit(0);
}

void	which_function(t_env *e, int argc, char **argv)
{
	e->var.mandelbrot = 0;
	e->var.julia.x = 0;
	e->var.julia.y = 0;
	e->var.burning = 0;
	write(1, "test1\n", 6);
	if (argc < 2)
		print_calls();
	else if (!ft_strncmp(argv[1], "mandelbrot", 10))
	{
		write(1, "test2\n", 6);
		if (!argv[2])
			print_calls();
		if (argv[2][0] > '0' && argv[2][0] <= '9')
		{
			e->var.mandelbrot = ft_atoi(argv[2]);
			e->function = &ft_mandelbrot_math;
		}
		else
			print_calls();
	}
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		e->var.julia.x = 0.285;
		e->var.julia.y = 0.01;
		e->function = &ft_julia;
			write(1, "test3\n", 6);
	}
	else if (!ft_strncmp(argv[1], "burning_ship", 13))
	{
		e->var.burning = 1;
		e->function = &ft_burning_ship;
		write(1, "test4\n", 6);
	}
	else
		print_calls();
	write(1, "test5\n", 6);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_init_e(t_env *e)
{
	e->col.r = 0;
	e->col.g = 0;
	e->col.b = 0;
	e->col.palette = 1;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "So, you chose truth");
	e->mlx.virt_min.x = -2;
	e->mlx.virt_max.x = 2;
	e->mlx.virt_min.y = -2;
	e->mlx.virt_max.y = 2;
	e->mlx.zoom = 1.0;
	e->img.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bits_per_pixel,
			&e->img.line_length, &e->img.endian);
}
