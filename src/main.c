#include "../fractol.h"

void	print_error(void)
{
	ft_putstr_fd("Usage: ./fractol [Mandelbrot|Julia]\n", 2);
}

int	handler(void)
{	t_vars	vars;

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

int main(void)
{
	if (argc == 1)
	{
		print_error();
		return (1);
	}
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		if (argc != 2)
		{
			print_error();
			return (1);
		}
		return (mandelbrot());
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		if (argc != 4)
		{
			print_error();
			return (1);
		}
		return (julia());
	}
	print_error();
	return (handler());
}
