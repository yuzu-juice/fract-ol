/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:42:27 by takitaga          #+#    #+#             */
/*   Updated: 2025/03/10 19:42:37 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractol(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		print_error();
		exit(1);
	}
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Julia");
	if (!vars->win)
	{
		free(vars->mlx);
		print_error();
		exit(1);
	}
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img.img)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		print_error();
		exit(1);
	}
	vars->zoom = 1.0;
	vars->shift_x = 0.0;
	vars->shift_y = 0.0;
}
