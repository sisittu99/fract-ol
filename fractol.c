/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:28 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/17 18:23:21 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_e(t_env *e)
{
	e->col.r = 0;
	e->col.g = 0;
	e->col.b = 0;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "Hello world!");
	e->img.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bits_per_pixel,
			&e->img.line_length, &e->img.endian);
}


unsigned int	ft_colour(t_pxl x)
{
	unsigned int	colour;

	colour = 0;
	colour |= (unsigned int)(x.b);
	colour |= (unsigned int)(x.g) * (unsigned int)pow(16, 2);
	colour |= (unsigned int)(x.r) * (unsigned int)pow(16, 4);
	return (colour);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//**************************************************************************************


// int	mouse_hook(int keycode)
// {
// 	printf("mouse key:\t%d\n", keycode);
// 	return (0);
// }

void	ft_circle(t_env *e)
{
	int	i;
	int	j;

	i = 0; j = 0;
	while (i++ < HEIGHT - 1)
	{
		while (j++ < WIDTH - 1)
		{
			if (i % 100 == 0)
				e->col.r++;
			if (j % 105 == 0)
				e->col.g++;
			if (i * j % 2 == 1)
				e->col.b++;
			if (e->col.r == 255)
			{
				e->col.r = 1;
				e->col.g = 1;
				e->col.b = 1;
			}
			if (pow((i - e->mlx.x), 2) + pow((j - e->mlx.y), 2) < 300*300)
				my_mlx_pixel_put(&e->img, j, i, ft_colour(e->col));
		}
		j = 0;
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->img.img, 0, 0);
}

//***************************************************************************************

int	ft_command(int keycode, t_env *e)
{
	printf("key:\t\t%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		write(1, "See ya!\n", 8);
		exit(0);
	}
	else if (keycode == 126)
	{
		e->mlx.x -= 100;
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
		ft_init_e(e);
		ft_circle(e);
		mlx_hook(e->mlx.win, 2, 1L<<0, ft_command, e);
		mlx_loop(e->mlx.mlx);
	}
	else if (keycode == 125)
	{
		e->mlx.x += 100;
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
		ft_init_e(e);
		ft_circle(e);
		mlx_hook(e->mlx.win, 2, 1L<<0, ft_command, e);
		mlx_loop(e->mlx.mlx);
	}
	else if (keycode == 123)
	{
		e->mlx.y -= 100;
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
		ft_init_e(e);
		ft_circle(e);
		mlx_hook(e->mlx.win, 2, 1L<<0, ft_command, e);
		mlx_loop(e->mlx.mlx);
	}
	else if (keycode == 124)
	{
		e->mlx.y += 100;
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
		ft_init_e(e);
		ft_circle(e);
		mlx_hook(e->mlx.win, 2, 1L<<0, ft_command, e);
		mlx_loop(e->mlx.mlx);
	}
	return (0);
}

//*************************************************************************************

int	main()
{
	t_env	e;
	e.mlx.x = HEIGHT / 2;
	e.mlx.y = WIDTH / 2;
	ft_init_e(&e);
	ft_circle(&e);
	mlx_hook(e.mlx.win, 2, 1L<<0, ft_command, &e);
	mlx_loop(e.mlx.mlx);
}
