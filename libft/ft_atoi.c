/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:31:14 by nilim             #+#    #+#             */
/*   Updated: 2026/08/06 11:10:03 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int r, int n)
{
	int	i;
	int	value;

	i = 0;
	value = r;
	if (n == 0)
		return (1);
	while (i < n - 1)
	{
		value *= r;
		i++;
	}
	return (value);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	value;

	neg = 0;
	value = 0;
	i = 0;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (ft_isdigit(nptr[i]))
		i++;
	while (i > 0)
	{
		value += (*nptr - '0') * (ft_power(10, i - 1));
		i--;
		nptr++;
	}
	if (neg)
		return (value * -1);
	return (value);
}
