#include "../fractol.h"

t_complex	complex_add(t_complex z, t_complex c)
{
	t_complex	result;

	result.re = z.re + c.re;
	result.im = z.im + c.im;
	return (result);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}
