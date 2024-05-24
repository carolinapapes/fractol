/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:12:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/24 17:23:34 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_eq(double y0, double x0, double *y, double *x)
{
	double	aux;

	aux = 2 * *x * *y + y0;
	*x = *x * *x - *y * *y + x0;
	*y = aux;
	return ;
}

void	julia_eq(double y0, double x0, double *y, double *x)
{
	double	aux;

	y0 = 0;
	x0 = 0;
	aux = 2 * *x * *y;
	*x = *x * *x - *y * *y;
	*y = aux;
	return ;
}

void	mandelbar_eq(double y0, double x0, double *y, double *x)
{
	double	aux;

	aux = y0 - 2 * *x * *y;
	*x = *x * *x - *y * *y + x0;
	*y = aux;
	return ;
}

int	is_mandelbrot_set(double x0, double y0, t_transform canvas)
{
	double	x;
	double	y;
	int		i;

	x0 = x0 * canvas.pixel_size + canvas.origin_x;
	y0 = y0 * canvas.pixel_size - canvas.origin_y;
	x = x0;
	y = y0;
	i = -1;
	while (x * x + y * y <= 4 && ++i < MAX_ITER)
		(canvas.fn)(y0, x0, &y, &x);
	return (i);
}
