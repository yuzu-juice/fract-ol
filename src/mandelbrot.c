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

static void	calc_mandelbrot(t_vars *vars)
{
	t_complex		c;
	t_coordinates	coordinate;

	c.re = 0;
	c.im = 0;
	vars->scale = 4.0 / WIDTH / vars->zoom ;
	coordinate.x = 0;
	while (coordinate.x < WIDTH)
	{
		coordinate.y = 0;
		while (coordinate.y < HEIGHT)
		{
			calc_pixel(vars, c, coordinate.x, coordinate.y);
			coordinate.y++;
		}
		coordinate.x++;
	}
}

int	mandelbrot(void)
{
	t_vars	vars;

	init_fractol(&vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_handler, &vars);
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.fractal_func = calc_mandelbrot;
	render_next_frame(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
