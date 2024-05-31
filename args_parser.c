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
#include <math.h>

int	ft_is_float(char *str)
{
	int	i;
	int	dot;

	printf("is_float: %s\n", str);
	dot = 0;
	i = -1;
	if ((*str == '-' || *str == '+') && ft_isdigit(str[1]))
		str++;
	while (*str && ++i < 6)
	{
		printf("int i = %d\n", i);
		if (!ft_isdigit(*str) && (!dot && *str == '.'))
		{
			dot = 1;
			i = -1;
			printf("dot = 1\n");
		}
		else if (!ft_isdigit(*str))
		{
			printf("is_float: false\n");
			return (0);
		}
		str++;
	}
	return (1);
}

double	ft_atof(char *str)
{
	double	n;
	double	d;
	int		i;
	int		decimals;
	int		sign;

	n = 0;
	d = 0;
	decimals = 0;
	sign = 1;
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ++i)
		sign = -1;
	while (str[i] && str[i] != '.')
		n = n * 10 + str[i++] - '0';
	if (str[i++] == '.')
		while (str[i] && ++decimals)
			d = d * 10 + str[i++] - '0';
	if (decimals)
		d = d / pow(10, decimals);
	printf("atof: %f\n", (n + d) * sign);
	return ((n + d) * sign);
}

int	set_julia(int argc, char **argv, t_vars *vars)
{
	if (argc == 4)
	{
		if (!ft_is_float(argv[2]) || !ft_is_float(argv[3]))
			return (0);
		vars->viewport.julia_var_x = ft_atof(argv[2]);
		vars->viewport.julia_var_y = ft_atof(argv[3]);
	}
	return (1);
}

int	set_julia_sin(int argc, char **argv, t_vars *vars)
{
	if (argc == 4)
	{
		if (!ft_is_float(argv[2]) || !ft_is_float(argv[3]))
			return (0);
		vars->viewport.julia_sin_x = ft_atof(argv[2]);
		vars->viewport.julia_sin_y = ft_atof(argv[3]);
	}
	return (1);
}

void ft_initialization(t_vars *vars)
{
	vars->viewport.fractal = -1;
	vars->viewport.julia_var_x = -0.7;
	vars->viewport.julia_var_y = 0.27015;
	vars->viewport.julia_sin_x = 1;
	vars->viewport.julia_sin_y = 0.2;
}

void	ft_parse_args(int argc, char **argv, t_vars *vars)
{
	ft_initialization(vars);
	if (argc == 2 && !ft_strncmp("mandelbrot", (const char *)argv[1], 11))
		vars->viewport.fractal = MANDELBROT;
	else if ((argc == 2 || argc == 4) && !ft_strncmp("julia", (const char *)argv[1], 6) && set_julia(argc, argv, vars))
		vars->viewport.fractal = JULIA;
	else if ((argc == 2 || argc == 4) && !ft_strncmp("julia_sin", (const char *)argv[1], 10) && set_julia_sin(argc, argv, vars))
		vars->viewport.fractal = JULIA_SIN;
	else if (argc == 2 && !ft_strncmp("mandelbar", (const char *)argv[1], 10))
		vars->viewport.fractal = MANDELBAR;
	return ;
}