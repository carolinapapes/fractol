/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:46:50 by capapes           #+#    #+#             */
/*   Updated: 2024/05/24 18:57:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "fractol.h"
#include <stdio.h>

void	ft_draw_mousewheel(int x, int y, t_vars *vars)
{
	int	i;

	i = -6;
	while (++i < 6)
	{
		ft_mlx_pixel_put(&(vars->img), x + i, y, 0x00555555);
		ft_mlx_pixel_put(&(vars->img), x, y + i, 0x00555555);
	}
}

int	ft_mouse_handler(int button, int x, int y, t_vars *vars)
{
	double	mouse_x;
	double	mouse_y;

	if (vars->canvas.pixel_size < 1e-12)
			return (0);
	mouse_x = (double)x * vars->canvas.pixel_size + vars->canvas.origin_x;
	mouse_y = (double)y * vars->canvas.pixel_size - vars->canvas.origin_y;	
	if (button == 5)
		vars->canvas.pixel_size *= 1.1;
	else if (button == 4)
		vars->canvas.pixel_size /= 1.1;
	else
		return (0);
	if (vars->canvas.pixel_size < 1e-12)
			return (0);
	vars->canvas.origin_x = mouse_x - ((double)x * vars->canvas.pixel_size);
	vars->canvas.origin_y = -mouse_y + ((double)y * vars->canvas.pixel_size);
	ft_set_canvas(&(vars->canvas), 0);
	get_fractol(vars);
	ft_draw_mousewheel(x, y, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);

	// Debugging prints
	// printf("button: %d x: %d, y: %d \n", button, x, y);
	// printf("mouse: x: %f, y: %f \n", mouse_x, mouse_y);
	// printf("pixel size: %f, origin-x: %f, origin-y: %f \n", vars->canvas.pixel_size, vars->canvas.origin_x, vars->canvas.origin_y);

	return (0);
}
