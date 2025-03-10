/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:57:26 by takitaga          #+#    #+#             */
/*   Updated: 2025/02/20 01:58:57 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calc_julia(t_vars *vars)
{
	t_complex	z;
	t_complex	c;
	t_coordinates coordinate;
	int		i;
	double		scale;
	int	color;

	c.re = 0.4;
	c.im = -0.325;
	scale = 4.0 / WIDTH / vars->zoom ;
	coordinate.x = 0;
	while (coordinate.x < WIDTH)
	{
		coordinate.y = 0;
		while (coordinate.y < HEIGHT)
		{
			z.re = vars->julia_x / 1000 + (coordinate.x - WIDTH / 2.0) * scale;
			z.im = vars->julia_y / 1000 + (coordinate.y - HEIGHT / 2.0) * scale;
			i = 0;
			while ((z.re * z.re) + (z.im * z.im) < 4  && i < MAXITER)
			{
				z = complex_square(z);
				z = complex_add(z, c);
				i++;
			}
			if (i == MAXITER)
				color = 0xFFFFFF;
			else
				color = i * 0xFF00FF / MAXITER;
			my_mlx_pixel_put(&vars->img, coordinate.x, coordinate.y, color);
			coordinate.y++;
		}
		coordinate.x++;
	}
}

int	julia(int x, int y)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Julia");
	if (!vars.win)
	{
		free(vars.mlx);
		return (1);
	}
	vars.zoom = 1.0;
	vars.julia_x = x;
	vars.julia_y = y;
	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_handler, &vars);
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.fractal_func = calc_julia;
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
