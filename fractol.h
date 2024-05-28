/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:32:58 by capapes           #+#    #+#             */
/*   Updated: 2024/05/28 18:53:39 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# include <stdio.h>

typedef struct s_viewport
{
	double		pixel_size;
	double		origin_x;
	double		origin_y;
	double		translate_x;
	double		translate_y;
	int			iters;
	int			fractal;
	int			background;
	int			palette;
	int			julia_var;
	int			(*fn)(double *y0, double *x0, double *y, double *x);
}	t_viewport;

typedef struct s_data
{
	char	*addr;
	void	*img;
	int		bpp;
	int		endian;
	int		l_len;
}	t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_viewport	viewport;
}				t_vars;

void	ft_parse_args(int argc, char **argv, t_vars *vars);
int		eq_mandelbrot(double *y0, double *x0, double *y, double *x);
int		eq_julia(double *y0, double *x0, double *y, double *x);
int		eq_julia_sin(double *y0, double *x0, double *y, double *x);
int		eq_mandelbar(double *y0, double *x0, double *y, double *x);
int		fractal_get(double x0, double y0, t_viewport viewport);
void	fractal_new(t_vars *vars);
void	fr_msg_mlx_error(void);
void	fr_msg_error_args(void);
void	fr_msg_help(void);
int		hkeys(int key_code, t_vars *vars);
void	hmlx_img_blank(t_vars *vars);
int		hmlx_close( t_vars *vars);
int		hmlx_initializate(t_vars *vars);
void	hmlx_pixel_put(t_vars *vars, int x, int y, int color);
int		hmouse_scroll(int button, int x, int y, t_vars *vars);
int		palette_get(int palette, int iteration);
void	vp_iterate(void (*fn)(t_vars *vars, int x, int y), t_vars *vars);
void	vp_initialize(t_vars *vars, int fractal);

#endif