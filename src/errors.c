/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 22:56:01 by takitaga          #+#    #+#             */
/*   Updated: 2025/03/10 22:56:01 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	print_args_error(void)
{
	ft_putstr_fd("Usage  : ./fractol [Mandelbrot|Julia value1 value2]\n", 2);
	ft_putstr_fd("Example1: ./fractol Mandelbrot\n", 2);
	ft_putstr_fd("Example2: ./fractol Julia -0.11 0.67\n", 2);
	ft_putstr_fd("Example3: ./fractol Julia -0.12 0.74\n", 2);
	ft_putstr_fd("Example4: ./fractol Julia -0.15652 1.03225\n", 2);
	ft_putstr_fd("Example5: ./fractol Julia -0.39054 -0.58679\n", 2);
	ft_putstr_fd("Example6: ./fractol Julia 0.11031 -0.67037\n", 2);
	return (1);
}

int	print_error(void)
{
	ft_putstr_fd("Something error happned...\n", 2);
	return (1);
}
