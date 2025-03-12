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

static void	calc_pixel(t_vars *vars, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		scale;
	int			i;
	int			color;

	i = 0;
	scale = vars->scale;
	z.re = (x - WIDTH / 2.0) * scale + vars->shift_x;
	z.im = (y - HEIGHT / 2.0) * scale + vars->shift_y;
	c.re = vars->julia_x;
	c.im = vars->julia_y;
	while ((z.re * z.re) + (z.im * z.im) < 4 && i < MAXITER)
	{
		z = complex_square(z);
		z = complex_add(z, c);
		i++;
	}
	if (i == MAXITER)
		color = 0xFFFFFF;
	else
		color = i * 0xFF00FF / MAXITER;
	my_mlx_pixel_put(&vars->img, x, y, color);
}

static void	calc_julia(t_vars *vars)
{
	t_coordinates	coordinate;

	vars->scale = 4.0 / WIDTH / vars->zoom ;
	coordinate.x = 0;
	while (coordinate.x < WIDTH)
	{
		coordinate.y = 0;
		while (coordinate.y < HEIGHT)
		{
			calc_pixel(vars, coordinate.x, coordinate.y);
			coordinate.y++;
		}
		coordinate.x++;
	}
}

int	julia(double x, double y)
{
	t_vars	vars;

	init_fractol(&vars);
	vars.julia_x = x;
	vars.julia_y = y;
	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_handler, &vars);
	vars.img.addr = mlx_get_data_addr(
			vars.img.img,
			&vars.img.bits_per_pixel,
			&vars.img.line_length,
			&vars.img.endian
			);
	vars.fractal_func = calc_julia;
	render_next_frame(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
