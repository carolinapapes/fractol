/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:46:50 by capapes           #+#    #+#             */
/*   Updated: 2024/05/27 19:54:29 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "fractol.h"

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


	mouse_x = (double)x * vars->canvas.pixel_size + vars->canvas.origin_x;
	mouse_y = (double)y * vars->canvas.pixel_size - vars->canvas.origin_y;
	ft_draw_mousewheel(x, y, vars);
	if (button == 5)
	{
		if (vars->canvas.pixel_size > 1e24)
			return (0);
		vars->canvas.pixel_size *= 1.05;
	}
	else if (button == 4)
	{
		if (vars->canvas.pixel_size < 1e-24)
			return (0);
		vars->canvas.pixel_size /= 1.05;
	}
	else
		return (0);
	vars->canvas.origin_x = mouse_x - ((double)x * vars->canvas.pixel_size);
	vars->canvas.origin_y = -mouse_y + ((double)y * vars->canvas.pixel_size);

	get_fractol(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
