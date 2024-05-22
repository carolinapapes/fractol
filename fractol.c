/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:34:21 by capapes           #+#    #+#             */
/*   Updated: 2024/05/22 19:29:18 by capapes          ###   ########.fr       */
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


void	ft_initiate_canvas(t_transform *canvas, int set)
{
	canvas->translate_y = TRANS_HALF * 4. / WIN_SIZE;
	canvas->translate_x = canvas->translate_y;
	canvas->scale = 4. / WIN_SIZE;
	if (set == 0)
	{
		canvas->translate_x = TRANS_THIRD * 4. / WIN_SIZE;
		canvas->fn = mandelbrot_eq;
	}
	else if (set == 1)
		canvas->fn = mandelbar_eq;
	else
		canvas->fn = julia_eq;
}

t_data	get_fractol(void *mlx)
{
	double		x;
	double		y;
	t_data		img;
	t_transform	canvas;
	int			i;

	y = -1;
	ft_initiate_canvas(&canvas, 0);
	img.img = mlx_new_image(mlx, WIN_SIZE, WIN_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			i = is_mandelbrot_set(x, y, canvas);
			if (i == MAX_ITER)
				ft_mlx_pixel_put(&img, x, y, 0x00FF0000);
			else
				ft_mlx_pixel_put(&img, x, y, 0x0000FFFF);
		}
	}
	return (img);
}

int	ft_close(int key_code, t_vars *vars)
{
	printf("\n%d\n", key_code);
	if (key_code != KEY_ESC)
		return (0);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data		img;
	t_vars		vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_putstr_fd("error", 2);
	vars.win = mlx_new_window(vars.mlx, WIN_SIZE, WIN_SIZE, "Fractol");
	if (vars.win == NULL)
		ft_putstr_fd("error", 2);
	img = get_fractol(vars.mlx);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, ft_close, &vars);
	mlx_loop(vars.mlx);
}
