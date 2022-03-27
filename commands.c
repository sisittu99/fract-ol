/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:18:35 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/25 15:33:54 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_map_arrows(int keycode, t_env *e)
{
	if (keycode == 123)
	{
		e->mlx.virt_min.x -= 0.15 * e->mlx.zoom;
		e->mlx.virt_max.x -= 0.15 * e->mlx.zoom;
	}
	else if (keycode == 124)
	{
		e->mlx.virt_min.x += 0.15 * e->mlx.zoom;
		e->mlx.virt_max.x += 0.15 * e->mlx.zoom;
	}
	else if (keycode == 126)
	{
		e->mlx.virt_min.y -= 0.15 * e->mlx.zoom;
		e->mlx.virt_max.y -= 0.15 * e->mlx.zoom;
	}
	else if (keycode == 125)
	{
		e->mlx.virt_min.y += 0.15 * e->mlx.zoom;
		e->mlx.virt_max.y += 0.15 * e->mlx.zoom;
	}
	print_pxl(e);
}

void	ft_zoom(int x, int y, t_env *e, int isplus)
{
	t_cpx		virt_pos;
	double	zoom_fact;

	if (isplus == 1)
		zoom_fact = 0.9f;
	else
		zoom_fact = 1.1f;
	if (!(e->mlx.zoom > 1.7f && isplus == 0))
	{
		virt_pos = virtual_to_real(e->mlx, x, HEIGHT - y);
		e->mlx.zoom *= zoom_fact;
		e->mlx.virt_max.x = e->mlx.virt_max.x * zoom_fact
					+ virt_pos.x * (1 - zoom_fact);
		e->mlx.virt_max.y = e->mlx.virt_max.y * zoom_fact
					+ virt_pos.y * (1 - zoom_fact);
		e->mlx.virt_min.x = e->mlx.virt_min.x * zoom_fact
					+ virt_pos.x * (1 - zoom_fact);
		e->mlx.virt_min.y = e->mlx.virt_min.y * zoom_fact
					+ virt_pos.y * (1 - zoom_fact);
		print_pxl(e);
	}
}

int	new_julia(t_env *e, int x, int y)
{
	e->var.mandelbrot = 2;
	e->function = &ft_julia;
	e->var.julia = virtual_to_real(e->mlx, x, y);
	print_pxl(e);
	return (0);
}

int	ft_mouse_manage(int keycode, int x, int y, t_env *e)
{
	if (keycode == 4)
		ft_zoom(x, y, e, 1);
	if (keycode == 5)
		ft_zoom(x, y, e, 0);
	if (keycode == 1 && !e->var.burning && e->var.mandelbrot == 2)
		new_julia(e, x, y);
	return (0);
}

int	ft_command(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		destroy_win(e);
		return (0);
	}
	if (keycode == 49 || keycode == 15)
	{
		which_function(e);
		ft_init_e(e);
		print_pxl(e);
		mlx_loop(e->mlx.mlx);
		return (0);
	}
	if (keycode >= 18 && keycode <= 29)
	{
		palette(keycode, e);
		return (0);
	}
	else if (keycode <= 126 && keycode >= 123)
		move_map_arrows(keycode, e);
	else if (keycode == 69)
		ft_zoom(WIDTH / 2, HEIGHT / 2, e, 1);
	else if (keycode == 78)
		ft_zoom(WIDTH / 2, HEIGHT / 2, e, 0);
	return (0);
}
