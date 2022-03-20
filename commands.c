/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:18:35 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/20 14:29:11 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	move_map_arrows(int keycode, t_env *e)
// {
// 	if (keycode == 126)
// 		e->mlx.virt_max -= 20;
// 	else if (keycode == 125)
// 		e->mlx.x += 20;
// 	else if (keycode == 123)
// 		e->mlx.y -= 20;
// 	else if (keycode == 124)
// 		e->mlx.y += 20;
// 	mlx_clear_window(e->mlx.mlx, e->mlx.win);
// //		ft_init_e(e);
// 	print_pxl(e);
// 	mlx_hook(e->mlx.win, 2, 1L<<0, ft_command, e);
// 	mlx_loop(e->mlx.mlx);
// }

void	zoom_plus(int x, int y, t_env *e)
{
	t_cpx	virt_pos;
	double	zoom_fact;
	
	zoom_fact = 0.95;
	//creiamo il delta al quale poi applicare il fattore zoom
	virt_pos = ft_sub_cpx(e->mlx.virt_max, e->mlx.virt_min);
	virt_pos.x = x * virt_pos.x / WIDTH;
	virt_pos.y = y * virt_pos.y / HEIGHT;
	virt_pos = ft_add_cpx(virt_pos, e->mlx.virt_min);
	e->mlx.zoom *= zoom_fact;
	//ora lo applichiamo a virt_max&min
	e->mlx.virt_max.x = e->mlx.virt_max.x * zoom_fact + virt_pos.x * (1 - zoom_fact);
	e->mlx.virt_max.y = e->mlx.virt_max.y * zoom_fact + virt_pos.y * (1 - zoom_fact);
	e->mlx.virt_min.x = e->mlx.virt_min.x * zoom_fact + virt_pos.x * (1 - zoom_fact);
	e->mlx.virt_min.y = e->mlx.virt_min.y * zoom_fact + virt_pos.y * (1 - zoom_fact);
	//piccolo spieghino reminder:
	//virt_max è stato modificato secondo lo zoom factor, il che basterebbe per zoomare.
	//Tuttavia, per permettere lo zoom nella posizione del mouse (dettata dalle coordinate e ricalcolate in virt_pos)
}

int	ft_mouse_manage(int keycode, int x, int y, t_env *e)
{
	if (keycode == 4)
		zoom_plus(x, y, e);
	if (keycode == 5)
		zoom_minus(x, y, e);
}

int	ft_command(int keycode, t_env *e)
{
	printf("key:\t\t%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		write(1, "See ya!\n", 8);
		exit(0);
	}
	// else if (keycode <= 126 && keycode >= 123)
	// 	move_map_arrows(keycode, e);
	return (0);
}
