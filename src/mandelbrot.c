/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:57:32 by takitaga          #+#    #+#             */
/*   Updated: 2025/02/20 01:58:52 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (!vars.win)
	{
		free(vars.mlx);
		return (1);
	}
	vars.zoom = 1.0;
	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_handler, &vars);
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.fractal_func = calc_mandelbrot;
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

void	calc_mandelbrot(t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	t_coordinates coordinate;
	int		i;
	double		scale;

	c.re = 0.4;
	c.im = -0.325;
	scale = 4.0 / WIDTH / vars->zoom ;
	coordinate.x = 0;
	while (coordinate.x < WIDTH)
	{
		coordinate.y = 0;
		while (coordinate.y < HEIGHT)
		{
			z.re = (coordinate.x - WIDTH / 2.0) * scale;
			z.im = (coordinate.y - HEIGHT / 2.0) * scale;
			i = 0;
			while (hypot(z.re, z.im) < 2 && i < MAXITER)
			{
				z = complex_square(z);
				z = complex_add(z, c);
				i++;
			}
			my_mlx_pixel_put(&vars->img, coordinate.x, coordinate.y, i * 0xFF / MAXITER);
			coordinate.y++;
		}
		coordinate.x++;
	}
}
