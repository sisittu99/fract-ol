/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerchi <mcerchi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:54:45 by mcerchi           #+#    #+#             */
/*   Updated: 2022/03/14 16:54:45 by mcerchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_LIB_H
# define MATH_LIB_H

# include "../libft/libft.h"
# include <math.h>

typedef struct s_cpx
{
	double	x;
	double	y;
}	t_cpx;

//basic_math.c
t_cpx	ft_create_cpx(double x, double y);
t_cpx	ft_add_cpx(t_cpx a, t_cpx b);
t_cpx	ft_sub_cpx(t_cpx a, t_cpx b);
void	ft_real_const_cpx(t_cpx *a, double c);
//math_mult_n_div.c
t_cpx	ft_mult_cpx(t_cpx a, t_cpx b);
t_cpx	ft_div_cpx(t_cpx a, t_cpx b);
void	ft_sqr_cpx(t_cpx *a,  double real_c, double img_c);
t_cpx	ft_power_cpx(t_cpx a, int n);

void	ft_newton_bin(t_cpx *a, int n, double real_c, double img_c);
int		coeff(int n, int k);
int		factorial(int nb);


#endif
