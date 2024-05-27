/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:32:58 by capapes           #+#    #+#             */
/*   Updated: 2024/05/27 18:32:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define  WIN_SIZE 600
# define  MAX_ITER 150

// Keyboard LETTERS

# define KEY_A 0
# define KEY_B 11
# define KEY_C 8
# define KEY_D 2
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_S 1
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_W 13
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6

// Keyboard ARROWS

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125

// Keyboard NUMPAD

# define KEY_DIV 75
# define KEY_MUL 67
# define KEY_MIN 78
# define KEY_PLU 69
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92

// Keyboard MISC

# define KEY_SPC 49
# define KEY_ESC 53
# define KEY_TAB 48
# define KEY_CTR 256 //stop mouse
# define KEY_CMD 259

// Mouse

# define M_L_BUTT 1      // Left mouse button
# define M_R_BUTT 2     // Right mouse button
# define M_MID_BUTT 3    // Middle mouse button
# define SCRL_U 4        // Mouse scroll up (Zoom in)
# define SCRL_D 5      // Mouse scroll down (Zoom out)
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
	int			iters;
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