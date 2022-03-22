/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:28 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/22 12:41:07 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_pxl	which_colour(int it)
{
	t_pxl	col;

	col.r = (it % 255) * 3;
	col.g = (it % 255) * 3;
	col.b = (it % 255) * 3;
	return (col);
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

//**************************************************************************************


// int	mouse_hook(int keycode)
// {
// 	printf("mouse key:\t%d\n", keycode);
// 	return (0);
// }

void	print_pxl(t_env *e)
{
	int	i;
	int	j;
	int	iterations;

	i = -1;
	j = -1;
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	while (++i < HEIGHT)
	{
		while (++j < WIDTH)
		{
			iterations = e->function(e->mlx, e->var, j, i);
			e->col = which_colour(iterations);
			my_mlx_pixel_put(&e->img, j, i, ft_colour(e->col));
		}
		j = -1;
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->img.img, 0, 0);
}

//*************************************************************************************

int	main(int argc, char **argv)
{
	t_env	e;

	which_function(&e, argc, argv);
	ft_init_e(&e);
	print_pxl(&e);
	mlx_hook(e.mlx.win, 2, 1L<<0, ft_command, &e);
	mlx_mouse_hook(e.mlx.win, ft_mouse_manage, &e);
	mlx_loop(e.mlx.mlx);
}
