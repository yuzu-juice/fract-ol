/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:12:11 by takitaga          #+#    #+#             */
/*   Updated: 2025/03/10 19:27:56 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	calc_pixel(t_vars *vars, t_complex c, int x, int y)
{
	t_complex	z;
	double		scale;
	int			i;
	int			color;

	i = 0;
	scale = vars->scale;
	z.re = (x - WIDTH / 2.0) * scale + vars->shift_x;
	z.im = (y - HEIGHT / 2.0) * scale + vars->shift_y;
	while ((z.re * z.re) + (z.im * z.im) < 2 && i < MAXITER)
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

int	render_next_frame(t_vars *vars)
{
	vars->fractal_func(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	double	shift_step;

	shift_step = 0.1 / vars->zoom;
	if (keycode == XK_Escape)
		close_window(vars);
	else if (keycode == XK_Left)
		vars->shift_x -= shift_step;
	else if (keycode == XK_Right)
		vars->shift_x += shift_step;
	else if (keycode == XK_Up)
		vars->shift_y -= shift_step;
	else if (keycode == XK_Down)
		vars->shift_y += shift_step;
	render_next_frame(vars);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == ON_MOUSEUP)
		vars->zoom *= 1.2;
	if (button == ON_MOUSEDOWN)
		vars->zoom *= 0.8;
	render_next_frame(vars);
	return (0);
}
