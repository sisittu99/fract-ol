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
	if (!e.var.burning)
		ft_putstr_fd("[left click]:\t\t\tpass to the respective Julia set", 1);
	ft_putstr_fd("\nESC:\t\t\t\t\tclose window\n\n", 1);
}
