/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:27:28 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/25 16:06:25 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	which_colour(int it, t_env *e)
{
	if (e->col.palette == 0)
	{
		e->col.r = 255 - (it % 255) * 10;
		e->col.g = 255 - (it % 255) * 10;
		e->col.b = 255 - (it % 255) * 10;
	}
	else if (e->col.palette == 1)
	{
		e->col.r = (it * 7 % 255);
		e->col.g = (it % 255);
		e->col.b = (it % 255);
	}
	else if (e->col.palette == 2)
	{
		e->col.r = (it * 2 % 255);
		e->col.g = (it * 15 % 255);
		e->col.b = (it * 50 % 255);
	}
	else if (e->col.palette == 3)
	{
		e->col.r = (it % 255);
		e->col.g = (it * 12 % 255);
		e->col.b = 255 - (it * 15 % 255);
	}
	else if (e->col.palette == 4)
	{
		e->col.r = 255 - (it * 7 % 255);
		e->col.g = 255 - (it * 7 % 255);
		e->col.b = (it % 255);
	}
	else if (e->col.palette == 5)
	{
		e->col.r = ((int) pow(it, 2) * 30) % 255;
		e->col.g = ((int) pow(it, 2) * 80) % 255;
		e->col.b = (it * 40) % 255;
	}
	return ;
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

void	print_intro(void)
{
	ft_putstr_fd("Welcome on board of the magician world of Fract-olz!\n", 1);
	ft_putstr_fd("It's your captain Matt Complex, and I have the pleasure to teach you how ", 1);
	ft_putstr_fd("to move in this complex world.\n", 1);
}

void	print_expl(t_env e)
{
	ft_putstr_fd("\nSeems like you chose ", 1);
	if (e.var.julia.x)
	{
		ft_putstr_fd("Julia!\n\nYou must know you're actually watching Mandelbrot set's primitive, ", 1);
		ft_putstr_fd("with a constant set at (0.285, 0.01).\n If you wish, close this window ", 1);
		ft_putstr_fd("(or press ESC), open Mandelbrot set, then click on any point and see the magic!", 1);
	}
	else if (e.var.burning)
	{
		ft_putstr_fd("the majestic Burning Ship!\n\nDid you know this is a trivial Mandelbrot set, ", 1);
		ft_putstr_fd("but any numbers are positive? That's the power of math xoxo\n", 1);
	}
	else
	{
		ft_putstr_fd("the mother of everything, the easiest and still beautiful Mandelbrot set!\n", 1);
		ft_putstr_fd("\nHere you have the possibility to click for any point and watch its respective", 1);
		ft_putstr_fd(" primitive function, which always happens to be a Julia set with ", 1);
		ft_putstr_fd("its constant set to that point you clicked! Thus you're able to see any ", 1);
		ft_putstr_fd("Julia set you want :)\nYou can always reset the window and turn back to Mandy!\n", 1);
	}
}

void	print_commands(t_env e)
{
	ft_putstr_fd("\n\n\n", 1);
	ft_putstr_fd("ฅ^•ﻌ•^ฅ         (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧          ฅ^•ﻌ•^ฅ\n", 1);
	ft_putstr_fd("\n\n\t\t**** COMMANDS ****\n\n", 1);
	ft_putstr_fd("ARROWS:\t\t\t\t\tmove inside the map\n", 1);
	ft_putstr_fd("1, 2, 3, 4, 5, 0:\t\t\tchange colours\n", 1);
	ft_putstr_fd("[space]\t\t||  R:\t\t\treset to the beginning\n", 1);
	ft_putstr_fd("[mouse wheel]\t|| ( +  &&  - ):\tzoom\n", 1);
	if (!e.var.julia.x && !e.var.burning)
		ft_putstr_fd("[left click]:\t\t\tpass to the respective Julia set", 1);
	ft_putstr_fd("\nESC:\t\t\t\t\tclose window\n\n", 1);
}

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
			which_colour(iterations, e);
			my_mlx_pixel_put(e, j, i);
		}
		j = -1;
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_env	e;

	e.argc = argc;
	e.argv = argv;
	e.mlx.mlx = mlx_init();
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT, "So, you chose truth");
	which_function(&e);
	ft_init_e(&e);
	print_pxl(&e);
	print_intro();
	print_expl(e);
	print_commands(e);
	mlx_hook(e.mlx.win, 2, 5, ft_command, &e);
	mlx_hook(e.mlx.win, 17, 0, destroy_win, &e);
	mlx_mouse_hook(e.mlx.win, ft_mouse_manage, &e);
	mlx_loop(e.mlx.mlx);
}
