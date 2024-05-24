/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:47:31 by capapes           #+#    #+#             */
/*   Updated: 2024/05/23 16:22:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./libs/minilibx_opengl/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("\n EXIT PROGRAM\n");
	exit(0);
	return ;
}

void	ft_move(int key_code, t_vars *vars)
{
	if (key_code == KEY_UP)
		vars->canvas.translate_origin_y += 0.01;
	if (key_code == KEY_DOWN)
		vars->canvas.translate_origin_y -= 0.01;
	if (key_code == KEY_LEFT)
		vars->canvas.translate_origin_x += 0.01;
	if (key_code == KEY_RIGHT)
		vars->canvas.translate_origin_x -= 0.01;
	ft_set_canvas(&(vars->canvas), 0);
	get_fractol(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	ft_keyhandler(int key_code, t_vars *vars)
{
	if (key_code == KEY_ESC)
		ft_close(vars);
	if (key_code == KEY_UP || key_code == KEY_DOWN
		|| key_code == KEY_LEFT || key_code == KEY_RIGHT)
		ft_move(key_code, vars);
	return (0);
}