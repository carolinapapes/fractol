// WOWOW
// while (++x < WIN_SIZE)
// 		{
// 			i = is_mandelbrot_set(x, y, vars->canvas);
// 			if (i == vars->canvas.iters)
// 				ft_mlx_pixel_put(&(vars->img), x, y, 0x00FFFFFF);
// 			else
// 				ft_mlx_pixel_put(&(vars->img), x, y, ((0x00000020 + (i % 10 * 0x00181818 + i * 1000)) << 8 >> 8) + 0xff000000);
// 		}


// void	drawgrid(t_vars *vars)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	y = -1;
// 	while (++y < WIN_SIZE)
// 	{
// 		x = -1;
// 		while (++x < WIN_SIZE)
// 		{
// 			if (x % (WIN_SIZE / 10) == 0)
// 				ft_mlx_pixel_put(&(vars->img), x, y, 0x00333333);
// 			if (y % (WIN_SIZE / 10) == 0)
// 				ft_mlx_pixel_put(&(vars->img), x, y, 0x00333333);
// 		}
// 	}
// 	i = -6;
// 	while ( ++i < 6)
// 	{
// 		ft_mlx_pixel_put(&(vars->img), vars->canvas.translate_x + i, vars->canvas.translate_y, 0x00FF0000);
// 		ft_mlx_pixel_put(&(vars->img), vars->canvas.translate_x, vars->canvas.translate_y + i, 0x00FF0000);

// 	}
// 	return ;

// }