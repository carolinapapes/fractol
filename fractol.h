/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:32:58 by capapes           #+#    #+#             */
/*   Updated: 2024/05/22 19:25:32 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define  WIN_SIZE 1200
# define  MAX_ITER 1000

# define KEY_ESC 53

// MANDELBROT DEFINITION
# define TRANS_THIRD (WIN_SIZE * 0.66)
# define TRANS_HALF (WIN_SIZE * 0.5)


typedef struct s_transform
{
	double		translate_x;
	double		translate_y;
	double		scale;
	void		(*fn)(double y0, double x0, double *y, double *x);
}	t_transform;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

void	mandelbrot_eq(double y0, double x0, double *y, double *x);
void	julia_eq(double y0, double x0, double *y, double *x);
int		is_mandelbrot_set(double x0, double y0, t_transform canvas);
void	mandelbar_eq(double y0, double x0, double *y, double *x);

#endif