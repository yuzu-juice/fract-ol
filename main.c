#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"

#define WIDTH 1920
#define HEIGHT 1080
#define MAXITER 1000

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}			t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;

	t_data	img;
}			t_vars;

typedef struct	s_complex {
	double	re;
	double	im;
}			t_complex;

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
