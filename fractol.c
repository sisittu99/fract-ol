/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:28 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/16 15:57:16 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_pxl	x;

	x.r = 0;
	x.g = 0;
	x.b = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	int i = 0;
	int j = 0;
	while (i++ < WIDTH - 1)
	{
		while (j++ < HEIGHT - 1)
		{
			if (i % 100 == 0)
				x.r++;
			if (j % 105 == 0)
				x.g++;
			x.b++;
			if (x.r == 255)
			{
				x.r = 1;
				x.g = 1;
				x.b = 1;
			}
			my_mlx_pixel_put(&img, i, j, ft_colour(x));
		}
		j = 0;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
