/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:37:04 by capapes           #+#    #+#             */
/*   Updated: 2024/05/28 18:56:20 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/libft/libft.h"

void	fr_msg_mlx_error(void)
{
	ft_putstr_fd("error", 2);
}

void	fr_msg_error_args(void)
{
	ft_putstr_fd("Error, please initiate with at leat one argument\n", 2);
	ft_putstr_fd(" mandelbrot | julia <n> | julia_sin <n>| mandelbar\n", 2);
	ft_putstr_fd(" n must be 0, 1, 2 or 3\n", 2);
}

void	fr_msg_help(void)
{
	ft_putstr_fd("-----------------------------------------------------\n", 1);
	ft_putstr_fd("FRACT-OL\n", 1);
	ft_putstr_fd("-----------------------------------------------------\n", 1);
	ft_putstr_fd(" mandelbrot | julia <n> | julia_sin <n>| mandelbar\n", 1);
	ft_putstr_fd(" n must be 0, 1, 2 or 3\n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" + | -\t\t\titr nbr\n", 1);
	ft_putstr_fd(" arrows\t\t\tmove\n", 1);
	ft_putstr_fd(" wheel\t\t\tzoom\n", 1);
}
