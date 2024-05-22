/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:32:58 by capapes           #+#    #+#             */
/*   Updated: 2024/05/22 16:25:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define  WIN_SIZE 600
# define  MAX_ITER 1000

// MANDELBROT DEFINITION
# define TRANS_THIRD (WIN_SIZE * 0.66)
# define TRANS_HALF (WIN_SIZE * 0.5)


typedef struct s_transform
{
	double		translate_x;
	double		translate_y;
	double		scale;
}	t_transform;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_data;

int	is_mandelbrot_set(double x0, double y0, t_transform canvas);

#endif