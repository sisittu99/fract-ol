/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:37:38 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/25 15:18:50 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./math_lib/math_lib.h"
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef DIM

#  define DIM
#  define WIDTH 640
#  define HEIGHT 640

# endif

typedef struct s_pxl
{
	int	palette;
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
	void		*mlx;
	void		*win;
	t_cpx		virt_max;
	t_cpx		virt_min;
	double	zoom;
}	t_vars;

typedef struct s_bool
{
	int		mandelbrot;
	t_cpx	julia;
	int		burning;
}	t_bool;

typedef struct s_env
{
	int		(*function)(t_vars mlx, t_bool var, int x, int y);
	t_data	img;
	t_pxl	col;
	t_vars	mlx;
	t_bool	var;
	int		argc;
	char	**argv;
}	t_env;

//colours.c
void			which_colour(int it, t_env *e);
void			which_colour_two(int it, t_env *e);
unsigned int	ft_colour(t_pxl x);
void			palette(int keycode, t_env *e);
//calculus.c
t_cpx			virtual_to_real(t_vars mlx, int x, int y);
t_cpx			mandelbrot_calc(t_bool var, t_cpx val, t_cpx constant);
int				ft_mandelbrot_math(t_vars mlx, t_bool var, int x, int y);
int				ft_julia(t_vars mlx, t_bool var, int x, int y);
int				ft_burning_ship(t_vars mlx, t_bool var, int x, int y);
//commands.c
int				ft_mouse_manage(int keycode, int x, int y, t_env *e);
int				new_julia(t_env *e, int x, int y);
void			move_map_arrows(int keycode, t_env *e);
void			ft_zoom(int x, int y, t_env *e, int isplus);
int				ft_command(int keycode, t_env *e);
//initialize.c
void			which_function(t_env *e);
void			ft_init_e(t_env *e);
//print.c
void			print_calls(void);
void			print_intro(void);
void			print_expl(t_env e);
void			print_commands(t_env e);
//fractol.c
int				destroy_win(t_env *e);
void			my_mlx_pixel_put(t_env *e, int x, int y);

void			print_pxl(t_env *e);

#endif
