/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:52:09 by takitaga          #+#    #+#             */
/*   Updated: 2025/02/20 01:58:44 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <math.h>
#include <complex.h>
#include "minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define WIDTH 1920 / 2
#define HEIGHT 1080 / 2
#define MAXITER 1000

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEUP = 4,
	ON_MOUSEDOWN= 5,
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
	void 	(*fractal_func)(struct s_vars *);
	double	zoom;
	int julia_x;
	int julia_y;

	t_data	img;
}			t_vars;

typedef struct	s_complex {
	double	re;
	double	im;
}			t_complex;

typedef struct s_coordinates {
	int	x;
	int	y;
}			t_coordinates;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		render_next_frame(t_vars *vars);
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int	mouse_handler(int button, int x, int y, t_vars *vars);
int 	julia(int x, int y);
int		mandelbrot(void);
t_complex complex_add(t_complex z, t_complex c);
t_complex complex_square(t_complex z);
