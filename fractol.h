/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:32:58 by capapes           #+#    #+#             */
/*   Updated: 2024/05/24 18:29:10 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define  WIN_SIZE 600
# define  MAX_ITER 300

# define KEY_ESC 53
// Keyboard ARROWS

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

// MANDELBROT DEFINITION

typedef struct s_transform
{
	double		translate_x;
	double		translate_y;
	double		translate_origin_x;
	double		translate_origin_y;
	double		pixel_size;
	double		origin_x;
	double		origin_y;
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
	void		*mlx;
	void		*win;
	t_transform	canvas;
	t_data		img;
}				t_vars;

void	mandelbrot_eq(double y0, double x0, double *y, double *x);
void	julia_eq(double y0, double x0, double *y, double *x);
int		is_mandelbrot_set(double x0, double y0, t_transform canvas);
void	mandelbar_eq(double y0, double x0, double *y, double *x);
int		ft_keyhandler(int key_code, t_vars *vars);
int		ft_mouse_handler(int button, int x, int y, t_vars *vars);
void	get_fractol(t_vars *vars);
void	ft_set_canvas(t_transform *canvas, int set);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif