/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 12:44:08 by nilim             #+#    #+#             */
/*   Updated: 2026/08/07 11:57:53 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

static int	ft_calctens(long n)
{
	int	tens;

	tens = 0;
	while (n > 9)
	{
		n /= 10;
		tens++;
	}
	return (tens);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		tens;
	long	n2;

	n2 = (long)n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 *= -1;
	}
	tens = ft_calctens(n2);
	while (tens >= 0)
	{
		ft_putchar_fd('0' + ((n2 / ft_power(10, tens)) % 10), fd);
		tens--;
	}
}
