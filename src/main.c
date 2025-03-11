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

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (print_args_error());
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		if (argc != 2)
			return (print_args_error());
		return (mandelbrot());
	}
	if (ft_strncmp(argv[1], "Julia", 5) == 0)
	{
		if (argc != 4)
			return (print_args_error());
		return (julia(ft_atof(argv[2]), ft_atof(argv[3])));
	}
	return (print_args_error());
}
