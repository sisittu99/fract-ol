/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:37:38 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/16 15:44:49 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./math_lib/math_lib.h"
# include "./mlx/mlx.h"

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

#endif
