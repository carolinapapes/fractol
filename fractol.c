/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:34:21 by capapes           #+#    #+#             */
/*   Updated: 2024/05/24 15:48:10 by capapes          ###   ########.fr       */
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
	canvas->translate_y = canvas->translate_origin_y * WIN_SIZE;
	canvas->translate_x = canvas->translate_origin_x * WIN_SIZE;
	canvas->scale = canvas->zoom / WIN_SIZE;
	if (set == 0)
		canvas->fn = mandelbrot_eq;
	else if (set == 1)
		canvas->fn = mandelbar_eq;
	else
		canvas->fn = julia_eq;
}

void	drawgrid(t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	
	y = -1;
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			if (x % (WIN_SIZE / 10) == 0)
				ft_mlx_pixel_put(&(vars->img), x, y, 0x00000000);
			if (y % (WIN_SIZE / 10) == 0)
				ft_mlx_pixel_put(&(vars->img), x, y, 0x00000000);
		}
	}
	i = -6;
	while ( ++i < 6)
	{
		ft_mlx_pixel_put(&(vars->img), vars->canvas.translate_x + i, vars->canvas.translate_y, 0x00FF0000);
		ft_mlx_pixel_put(&(vars->img), vars->canvas.translate_x, vars->canvas.translate_y + i, 0x00FF0000);

	}
	return ;

}


void	get_fractol(t_vars *vars)
{
	double		x;
	double		y;
	int			i;

	y = -1;
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), &(vars->img.l_len), &(vars->img.endian));
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			i = is_mandelbrot_set(x, y, vars->canvas);
			if (i == MAX_ITER)
				ft_mlx_pixel_put(&(vars->img), x, y, 0x00FFFFFF);
			else
				ft_mlx_pixel_put(&(vars->img), x, y, 0x0000FFFF);
		}
	}
	drawgrid(vars);
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
	vars.canvas.zoom = 4;
	vars.canvas.translate_origin_x = 0.66;
	vars.canvas.translate_origin_y = 0.5;
	ft_set_canvas(&vars.canvas, 0);
	get_fractol(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, ft_keyhandler, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_button, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_handler, &vars);
	mlx_loop(vars.mlx);
}
