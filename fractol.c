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
#include "viewport_definitions.h"

void	ft_colors(t_vars *vars, int x, int y, int color)
{
	int			i;

	i = is_mandelbrot_set(x, y, vars->canvas);
	if (i == vars->canvas.iters)
		ft_mlx_pixel_put(vars, x, y, color);
	else
		ft_mlx_pixel_put(vars, x, y, i % 10 * 0x00181818 + i * 1080);
}

void	get_fractol(t_vars *vars)
{
	clear_mlx(vars);
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), &(vars->img.l_len), &(vars->img.endian));
	ft_iterate_viewport(ft_colors, 0x00FFFFFF, vars);
	return ;
}


int	main(void)
{
	t_vars		vars;

	if (initializate_mlx(&vars))
		return (1);
	ft_initialize_canvas(&vars);
	get_fractol(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, ft_keyhandler, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_mlx, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_handler, &vars);
	mlx_loop(vars.mlx);
}