/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:12:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/28 17:57:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

int	eq_mandelbrot(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	aux = 2 * *x * *y + *y0;
	*x = *x * *x - *y * *y + *x0;
	*y = aux;
	return (*x * *x + *y * *y < 4);
}

int	eq_julia(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	*x0 = -0.7;
	*y0 = 0.27015;
	aux = *x * *x - *y * *y + *x0;
	*y = 2 * *x * *y + *y0;
	*x = aux;
	return (*x * *x + *y * *y < 4);
}

int	eq_mandelbar(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	aux = *y0 - 2 * *x * *y;
	*x = *x * *x - *y * *y + *x0;
	*y = aux;
	return (*x * *x + *y * *y < 4);
}

int	eq_julia_sin(double *y0, double *x0, double *y, double *x)
{
	double	aux;

	*x0 = 1.0;
	*y0 = 0.2;
	aux = sin(*x) * cosh(*y) + *y0;
	*x = cos(*x) * sinh(*y) + *x0;
	*y = aux;
	return (fabs(*y) < 50);
}

int	fractal_get(double x0, double y0, t_viewport viewport)
{
	double	x;
	double	y;
	int		i;

	x0 = x0 * viewport.pixel_size + viewport.origin_x;
	y0 = y0 * viewport.pixel_size - viewport.origin_y;
	x = x0;
	y = y0;
	i = 0;
	while ((viewport.fn)(&y0, &x0, &y, &x) && ++i < viewport.iters)
		;
	return (i);
}

// fn complex_sin(z: Complex) -> Complex {
//     Complex { 
//         a: z.a.sin() * z.b.cosh(),
//         b: z.a.cos() * z.b.sinh()
//     }
// }

// fn csinz(x: f32, y: f32) -> f32 {
//     let mut z = Complex { a: x, b: y };
//     let c = Complex { a: 1.0, b: 0.0 };
//     let max = 256;
//     let mut i = 0;
//     while i < max && z.b.abs() < 50.0 {
//         z = c * complex_sin(z);
//         i += 1;
//     }
//     return i as f32 / max as f32;
// }