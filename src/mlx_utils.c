#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
    double shift_step = 0.1 / vars->zoom;
    if (keycode == XK_Escape)
        close_window(vars);
    else if (keycode == XK_Left)
        vars->shift_x -= shift_step;
    else if (keycode == XK_Right)
        vars->shift_x += shift_step;
    else if (keycode == XK_Up)
        vars->shift_y += shift_step;
    else if (keycode == XK_Down)
        vars->shift_y -= shift_step;
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
