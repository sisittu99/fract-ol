/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:18:35 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/22 20:09:25 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_map_arrows(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->mlx.virt_min.x -= 0.1 * e->mlx.zoom;
		e->mlx.virt_max.x -= 0.1 * e->mlx.zoom;
	}
	else if (keycode == 125)
	{
		e->mlx.virt_min.x += 0.1 * e->mlx.zoom;
		e->mlx.virt_max.x += 0.1 * e->mlx.zoom;
	}
	else if (keycode == 123)
	{
		e->mlx.virt_min.y -= 0.1 * e->mlx.zoom;
		e->mlx.virt_max.y -= 0.1 * e->mlx.zoom;
	}
	else if (keycode == 124)
	{
		e->mlx.virt_min.y += 0.1 * e->mlx.zoom;
		e->mlx.virt_max.y += 0.1 * e->mlx.zoom;
	}
	print_pxl(e);
}

void	ft_zoom(int x, int y, t_env *e, int isplus)
{
	t_cpx		virt_pos;
	long double	zoom_fact;

	if (isplus == 1)
		zoom_fact = 0.9f;
	else
		zoom_fact = 1.1f;
	if (e->mlx.zoom <= 2.0f)
	{
		//creiamo il delta al quale poi applicare il fattore zoom
		virt_pos = virtual_to_real(e->mlx, x, y);
		e->mlx.zoom *= zoom_fact;
		//ora lo applichiamo a virt_max&min
		e->mlx.virt_max.x = e->mlx.virt_max.x * zoom_fact + virt_pos.x * (1 - zoom_fact);
		e->mlx.virt_max.y = e->mlx.virt_max.y * zoom_fact + virt_pos.y * (1 - zoom_fact);
		e->mlx.virt_min.x = e->mlx.virt_min.x * zoom_fact + virt_pos.x * (1 - zoom_fact);
		e->mlx.virt_min.y = e->mlx.virt_min.y * zoom_fact + virt_pos.y * (1 - zoom_fact);
		//piccolo spieghino reminder:
		//virt_max è stato modificato secondo lo zoom factor, il che basterebbe per zoomare.
		//Tuttavia, per permettere lo zoom nella posizione del mouse (dettata dalle coordinate e ricalcolate in virt_pos)
		//bisogna trovare un modo per rimanere nel punto zoomato. Questo forse non sarà preciso, ma di sicuro ci si avvicina!

		//e->mlx.virt_min.x = (1 - ((virt_pos.x - e->mlx.virt_min.x) * 2 * (1 - zoom_fact)) / (e->mlx.virt_max.x - e->mlx.virt_min.x));
		print_pxl(e);
	}
}

int	new_julia(t_env *e, int x, int y)
{
		write(1, "sono qui\n", 9);
		if (e->var.mandelbrot)
			e->var.mandelbrot = 0;
		e->function = &ft_julia;
		e->var.julia = virtual_to_real(e->mlx, x, y);
		write(1, "ancora qui\n", 11);
		print_pxl(e);
		write(1, "fine\n", 5);
		return (0);
}

int	destroy_win(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	write(1, "See ya!\n", 8);
	exit(0);
}

int	ft_mouse_manage(int keycode, int x, int y, t_env *e)
{
	printf("key:\t\t%d\n", keycode);
	printf("coord_x:\t%d\t\t\tcorrd_y:\t%d\n", x, y);
	if (keycode == 4)
		ft_zoom(x, y, e, 1);
	if (keycode == 5)
		ft_zoom(x, y, e, 0);
	if (keycode == 1 && e->var.mandelbrot > 0)
		new_julia(e, x, y);
	return (0);
}

void palette(int keycode, t_env *e)
{
	if (keycode == 29)
		e->col.palette = 0;
	if (keycode == 18)
		e->col.palette = 1;
	if (keycode == 19)
		e->col.palette = 2;
	if (keycode == 20)
		e->col.palette = 3;
	print_pxl(e);
}

int	ft_command(int keycode, int x, int y, t_env *e)
{
	printf("key:\t\t%d\n", keycode);
	if (keycode == 53)
		destroy_win(e);
	else if (keycode == 49)
	{
		which_function(e);
		ft_init_e(e);
		print_pxl(e);
	}
	else if (keycode >= 18 && keycode <= 29)
		palette(keycode, e);
	else if (keycode == 256 && (!e->var.burning && !e->var.mandelbrot))
		new_julia(e, x, y);
	else if (keycode <= 126 && keycode >= 123)
		move_map_arrows(keycode, e);
	return (-1);
}
