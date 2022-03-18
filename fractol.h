/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:37:38 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/18 15:20:05 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./math_lib/math_lib.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef DIM

#  define DIM
#  define WIDTH 1920
#  define HEIGHT 1080

# endif

typedef struct s_pxl
{
	int	r;
	int	g;
	int	b;
}	t_pxl;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_vars;


typedef struct s_env
{
	t_data	img;
	t_pxl	col;
	t_vars	mlx;
}	t_env;

void	move_map_arrows(int keycode, t_env *e);
int		ft_command(int keycode, t_env *e);

#endif
