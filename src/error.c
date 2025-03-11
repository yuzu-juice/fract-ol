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
	ft_putstr_fd("Example: ./fractol Julia n m\n", 2);
	return (1);
}

int	print_error(void)
{
	ft_putstr_fd("Something error happned...\n", 2);
	return (1);
}
