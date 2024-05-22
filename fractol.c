/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:34:21 by capapes           #+#    #+#             */
/*   Updated: 2024/05/22 16:28:03 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libs/minilibx_opengl/mlx.h"
#include "./libs/libft/libft.h"
#include "fractol.h"
#include <stdio.h>

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp >> 3));
	*(unsigned int *)dst = color;
}


void	ft_initiate_canvas(t_transform *canvas)
{
	(*canvas).translate_x = TRANS_THIRD * 4. / WIN_SIZE;
	(*canvas).translate_y = TRANS_HALF * 4. / WIN_SIZE;
	(*canvas).scale = 4. / WIN_SIZE;
}

t_data	get_fractol(void *mlx)
{
	double		x;
	double		y;
	t_data		img;
	t_transform	canvas;
	int			i;

	y = -1;

	img.img = mlx_new_image(mlx, WIN_SIZE, WIN_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	ft_initiate_canvas(&canvas);


	while (++y < WIN_SIZE)
	{
		x = -1;
		while (++x < WIN_SIZE)
		{
			i = is_mandelbrot_set(x, y, canvas);
			if (i == MAX_ITER)
				ft_mlx_pixel_put(&img, x, y, 0x00000000);
			else
				ft_mlx_pixel_put(&img, x, y, i * 0x02004080);
		}
	}
	return (img);

}

int	main(void)
{
	t_data		img;
	void		*mlx_win;
	void		*mlx;


	mlx = mlx_init();
	if (mlx == NULL)
		ft_putstr_fd("error", 2);
	mlx_win = mlx_new_window(mlx, WIN_SIZE, WIN_SIZE, "Fractol");
	if (mlx_win == NULL)
		ft_putstr_fd("error", 2);
	img = get_fractol(mlx);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
