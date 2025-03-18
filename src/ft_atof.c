/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:26:05 by takitaga          #+#    #+#             */
/*   Updated: 2025/03/18 12:26:29 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	parse_sign(const char **nptr)
{
	double	sign;

	sign = 1.0;
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '+')
		(*nptr)++;
	else if (**nptr == '-')
	{
		(*nptr)++;
		sign = -1.0;
	}
	return (sign);
}

static double	parse_integer(const char **nptr)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**nptr))
	{
		result = result * 10.0 + **nptr - '0';
		(*nptr)++;
	}
	return (result);
}

static double	parse_fraction(const char **nptr)
{
	double	result;
	double	scale;

	result = 0.0;
	scale = 0.1;
	if (**nptr == '.')
	{
		(*nptr)++;
		while (ft_isdigit(**nptr))
		{
			result += scale * (**nptr - '0');
			scale *= 0.1;
			(*nptr)++;
		}
	}
	return (result);
}

double	ft_atof(const char *nptr)
{
	double	sign;
	double	result;

	sign = parse_sign(&nptr);
	result = parse_integer(&nptr);
	result += parse_fraction(&nptr);
	return (sign * result);
}
