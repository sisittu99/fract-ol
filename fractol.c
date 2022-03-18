/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:28 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/18 16:16:17 by mcerchi          ###   ########.fr       */
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

	i = -1; j = -1;
	while (i++ < HEIGHT)
	{
		while (j++ < WIDTH)
		{
			//1) chiamare la funzione di calcolo, ricordandoci di basarci sullo "spazio virtuale" e quindi facendo le giuste proporzioni!
			//calcolare il colore: partiamo dalláppartenenza o meno al set, poi a seconda delle iterazioni
			//		vediamo quale colore assegnare.
			my_mlx_pixel_put(&e->img, j, i, ft_colour(e->col));
		}
		j = -1;
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->img.img, 0, 0);
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
