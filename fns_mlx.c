#include "fractol.h"
#include "./libs/minilibx_opengl/mlx.h"
#include <stdlib.h>
#include "viewport_definitions.h"

void	ft_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.addr + (y * vars->img.l_len + x * (vars->img.bpp >> 3));
	*(unsigned int *)dst = color;
}

int initializate_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		ft_putstr_fd("error", 2);
		return (1);
	}
	vars->win = mlx_new_window(vars->mlx, WIN_SIZE, WIN_SIZE, "Fract-ol");
	if (vars->win == NULL)
	{
		ft_putstr_fd("error", 2);
		return (1);
	}
	return (0);
}

int	ft_close_mlx( t_vars *vars)
{
	vars = NULL;
	if (vars)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
	}
	exit(0);
	return (0);
}

void	clear_mlx(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIN_SIZE, WIN_SIZE);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &(vars->img.bpp), &(vars->img.l_len), &(vars->img.endian));
	ft_iterate_viewport(ft_mlx_pixel_put, 0x00FFFFFF, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

