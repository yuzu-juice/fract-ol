#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render_next_frame(t_vars *vars)
{
	t_complex	c;
	t_complex	z;
	int		x;
	int		y;
	int		i;
	double		scale;
	double 		tmp;

	c.re = 0.4;
	c.im = -0.325;
	scale = 4.0 / WIDTH;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z.re = (x - WIDTH / 2.0) * scale;
			z.im = (y - HEIGHT / 2.0) * scale;
			i = 0;
			while (z.re * z.re + z.im * z.im < 4 && i < MAXITER)
			{
				tmp = z.re * z.re - z.im * z.im + c.re;
				z.im = 2 * z.re * z.im + c.im;
				z.re = tmp;
				i++;
			}
			my_mlx_pixel_put(&vars->img, x, y, i * 0xFF / MAXITER);
			y++;
		}
		x++;
	}
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
	if (keycode == XK_Escape)
		close_window(vars);
	return (0);
}

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	if (!vars.win)
	{
		free(vars.mlx);
		return (1);
	}
	mlx_hook(vars.win, ON_DESTROY, 0, close_window, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
