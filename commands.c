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
