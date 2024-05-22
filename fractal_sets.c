/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:12:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/22 16:33:59 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_eq(double y0, double x0, double *y, double *x)
{
	double	aux;

	aux = 2 * *x * *y + y0;
	*x = *x * *x - *y * *y + x0;
	*y = aux;
	return (*x * *x + *y * *y <= 4);
}

int	is_mandelbrot_set(double x0, double y0, t_transform canvas)
{
	double	x;
	double	y;
	int		i;

	x0 = x0 * canvas.scale - canvas.translate_x;
	y0 = y0 * canvas.scale - canvas.translate_y;
	x = x0;
	y = y0;
	i = -1;
	while (mandelbrot_eq(y0, x0, &y, &x) && ++i < MAX_ITER)
		;
	return (i);
}

int	is_julia_set(double x0, double y0)
{
	double	x;
	double	y;
	double	aux;
	int		i;

	x = (x0 - TRANS_HALF) * 4 / WIN_SIZE;
	y = (TRANS_HALF - y0) * 4 / WIN_SIZE;
	i = -1;
	while ((x * x + y * y) <= (4) && ++i < MAX_ITER)
	{
		aux = (2 * x * y);
		x = (x * x) - (y * y);
		y = aux;
	}
	return (i);
}

int	is_mandelbar_set(double x0, double y0)
{
	double	x;
	double	y;
	double	aux;
	int		i;

	x0 = (x0 - TRANS_HALF) * 4 / WIN_SIZE;
	y0 = (TRANS_HALF - y0) * 4 / WIN_SIZE;
	x = x0;
	y = y0;
	i = -1;
	while ((x * x + y * y) <= (4) && ++i < MAX_ITER)
	{
		aux = (2 * x * y) + x0;
		y = (x * x) - (y * y) + y0;
		x = aux;
	}
	return (i);
}
