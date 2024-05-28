#include "./libs/minilibx_opengl/mlx.h"
#include "fractol.h"
#include "viewport_definitions.h"

void	ft_select_fractal(t_transform *canvas, int set)
{
	if (set == 0)
		canvas->fn = mandelbrot_eq;
	else if (set == 1)
		canvas->fn = mandelbar_eq;
	else if (set == 2)
		canvas->fn = julia_eq;
	else
		canvas->fn = ft_julia_sin;
}

void	ft_initialize_canvas(t_vars *vars)
{
	vars->canvas.pixel_size = PIXEL_SIZE;
	vars->canvas.origin_x = MANDELBROT_ORIG_X * PIXEL_SIZE;
	vars->canvas.origin_y = ORIGIN * PIXEL_SIZE;
	vars->canvas.iters = MAX_ITER;
	vars->canvas.fractal = 0;
	ft_select_fractal(&vars->canvas, vars->canvas.fractal);
}

void	ft_iterate_viewport(void (*fn)(t_vars *vars, int x, int y, int color), int color, t_vars *vars)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
			fn(vars, x, y, color);
	}
	return ;
}

void	ft_clear_viewport(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), &(vars->img.l_len), &(vars->img.endian));
	ft_iterate_viewport(ft_mlx_pixel_put, 0x00FFFFFF, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
