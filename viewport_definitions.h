
#ifndef VIEWPORT_DEFINITIONS_H

#define VIEWPORT_DEFINITIONS_H

#define WIN_SIZE 600
#define MAX_ITER 256

#define ORIGIN 0.5 * WIN_SIZE
#define PIXEL_SIZE 4. / WIN_SIZE

// Mandelbrot set
#define MANDELBROT_ORIG_X -0.66 * WIN_SIZE

void ft_iterate_viewport(void (*fn)(t_vars *vars, int x, int y, int color), int color, t_vars *vars);
void ft_initialize_canvas(t_vars *vars);

#endif