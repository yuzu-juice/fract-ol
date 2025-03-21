/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga <takitaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:52:09 by takitaga          #+#    #+#             */
/*   Updated: 2025/03/19 18:25:38 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <math.h>
# include <complex.h>
# include "minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 960
# define HEIGHT 540

enum
{
	ON_MOUSEUP = 4,
	ON_MOUSEDOWN= 5,
	ON_DESTROY = 17
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	(*fractal_func)(struct s_vars*);
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	scale;
	double	shift_x;
	double	shift_y;
	int		color;
	int		max_iter;

	t_data	img;
}			t_vars;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_coordinates
{
	int		x;
	int		y;
}			t_coordinates;

void		init_fractol(t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			render_next_frame(t_vars *vars);
int			close_window(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			mouse_handler(int button, int x, int y, t_vars *vars);
int			julia(double x, double y);
int			mandelbrot(void);
t_complex	complex_add(t_complex z, t_complex c);
t_complex	complex_square(t_complex z);
int			print_args_error(void);
int			print_error(void);
double		ft_atof(const char *nptr);

#endif
