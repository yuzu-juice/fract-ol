/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:08:32 by takitaga          #+#    #+#             */
/*   Updated: 2025/02/20 01:56:16 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_error(void)
{
	ft_putstr_fd("Usage: ./fractol [Mandelbrot|Julia]\n", 2);
}

int main(int argc, char *argv[])
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
	return (1);
}
