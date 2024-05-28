/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:56:34 by capapes           #+#    #+#             */
/*   Updated: 2024/05/28 19:00:59 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "viewport_defs.h"
#include "./libs/libft/libft.h"


// void	ft_parse_second_arg(char **argv, t_vars *vars)
// {

// }

void	ft_parse_args(int argc, char **argv, t_vars *vars)
{
	if (argc == 2 && !ft_strncmp("mandelbrot", (const char *)*(argv + 1), 11))
		vars->viewport.fractal = MANDELBROT;
	if ((argc == 2 || argc == 3) && !ft_strncmp("julia", (const char *)*(argv + 1), 6))
	{
		// if (argc == 3)

		vars->viewport.fractal = JULIA;
	}
	if ((argc == 2 || argc == 3) && !ft_strncmp("julia_sin", (const char *)*(argv + 1), 10))
		vars->viewport.fractal = JULIA_SIN;
	if (argc == 2 && !ft_strncmp("mandelbar", (const char *)*(argv + 1), 10))
		vars->viewport.fractal = MANDELBAR;
	else
		vars->viewport.fractal = -1;
	return ;
}