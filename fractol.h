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
