/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:34:21 by capapes           #+#    #+#             */
/*   Updated: 2024/05/27 19:53:48 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "./libs/libft/libft.h"
#include "fractol.h"
#include <stdio.h>

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp >> 3));
	*(unsigned int *)dst = color;
}



void	ft_set_canvas(t_transform *canvas, int set)
{
	if (set == 0)
		canvas->fn = mandelbrot_eq;
	else if (set == 1)
		canvas->fn = mandelbar_eq;
	else
		canvas->fn = julia_eq;
}


void ft_clear_window(t_vars *vars)
{
	double		x;
	double		y;

	y = -1;
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), &(vars->img.l_len), &(vars->img.endian));
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
			ft_mlx_pixel_put(&(vars->img), x, y, 0x00FFFFFF);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}


void	get_fractol(t_vars *vars)
{
	double		x;
	double		y;
	int			i;

	y = -1;
	ft_clear_window(vars);
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), &(vars->img.l_len), &(vars->img.endian));
	printf("\n iters: %d", vars->canvas.iters);
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			i = is_mandelbrot_set(x, y, vars->canvas);
			if (i == vars->canvas.iters)
				ft_mlx_pixel_put(&(vars->img), x, y, 0x00FFFFFF);
			else
				ft_mlx_pixel_put(&(vars->img), x, y,  i % 10 * 0x00181818 + i * 1080);
		}
	}
	// drawgrid(vars);
	return ;
}



int	ft_close_button( t_vars *vars)
{
	vars = NULL;
	printf("17  EXIT PROGRAM\n");
	exit(0);
	return (0);
}



int	main(void)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_putstr_fd("error", 2);
	vars.win = mlx_new_window(vars.mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	if (vars.win == NULL)
		ft_putstr_fd("error", 2);
	vars.canvas.pixel_size = 4. / WIN_SIZE;
	vars.canvas.origin_x = -0.66 * WIN_SIZE * vars.canvas.pixel_size;
	vars.canvas.origin_y = 0.5 * WIN_SIZE * vars.canvas.pixel_size;
	vars.canvas.iters = MAX_ITER;
	ft_set_canvas(&vars.canvas, 3);
	get_fractol(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, ft_keyhandler, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_button, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_handler, &vars);
	mlx_loop(vars.mlx);
}


// WOWOW
// while (++x < WIN_SIZE)
// 		{
// 			i = is_mandelbrot_set(x, y, vars->canvas);
// 			if (i == vars->canvas.iters)
// 				ft_mlx_pixel_put(&(vars->img), x, y, 0x00FFFFFF);
// 			else
// 				ft_mlx_pixel_put(&(vars->img), x, y, ((0x00000020 + (i % 10 * 0x00181818 + i * 1000)) << 8 >> 8) + 0xff000000);
// 		}

// void	drawgrid(t_vars *vars)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	y = -1;
// 	while (++y < WIN_SIZE)
// 	{
// 		x = -1;
// 		while (++x < WIN_SIZE)
// 		{
// 			if (x % (WIN_SIZE / 10) == 0)
// 				ft_mlx_pixel_put(&(vars->img), x, y, 0x00333333);
// 			if (y % (WIN_SIZE / 10) == 0)
// 				ft_mlx_pixel_put(&(vars->img), x, y, 0x00333333);
// 		}
// 	}
// 	i = -6;
// 	while ( ++i < 6)
// 	{
// 		ft_mlx_pixel_put(&(vars->img), vars->canvas.translate_x + i, vars->canvas.translate_y, 0x00FF0000);
// 		ft_mlx_pixel_put(&(vars->img), vars->canvas.translate_x, vars->canvas.translate_y + i, 0x00FF0000);

// 	}
// 	return ;

// }