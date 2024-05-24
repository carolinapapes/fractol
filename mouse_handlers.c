/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:46:50 by capapes           #+#    #+#             */
/*   Updated: 2024/05/24 16:50:12 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "fractol.h"
#include <stdio.h>



void ft_draw_mousewheel(int x, int y, t_vars *vars)
{
	int	i;

	i = -6;
	while (++i < 6)
	{
		ft_mlx_pixel_put(&(vars->img), x + i, y, 0x00FF0000);
		ft_mlx_pixel_put(&(vars->img), x, y + i, 0x00FF0000);
	}
}

int	ft_mouse_handler(int button, int x, int y, t_vars *vars)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;


	// Normalize mouse coordinates to [0, 1] range
    mouse_x = (double)x / WIN_SIZE;
    mouse_y = (double)y / WIN_SIZE;

	// Determine the zoom factor based on the button pressed
    if (button == 5) // Zoom in
        zoom_factor = 1.1;
    else if (button == 4) // Zoom out
        zoom_factor = 1 / 1.1;
    else
        return (0); // Only handle zoom in and out

	// Update zoom level
    vars->canvas.zoom *= zoom_factor;


    // Adjust translation origins to center the zoom on the mouse position
// Adjust translation origins to center the zoom on the mouse position
    vars->canvas.translate_origin_x = (vars->canvas.translate_origin_x + (mouse_x - 0.5)) / zoom_factor - (mouse_x - 0.5);
    vars->canvas.translate_origin_y = (vars->canvas.translate_origin_y + (mouse_y - 0.5)) / zoom_factor - (mouse_y - 0.5);


	ft_set_canvas(&(vars->canvas), 0);
	get_fractol(vars);
	ft_draw_mousewheel( x,  y, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	
	// Debugging prints
	printf("button: %d\n x: %d, y: %d \n", button, x, y);
	printf("mouse: x: %f, y: %f \n", mouse_x, mouse_y);
	printf("zoom: %f, origin-x: %f, origin-y: %f \n", vars->canvas.zoom, vars->canvas.translate_origin_x, vars->canvas.translate_origin_y);

	return (0);
}
