/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 17:04:09 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 13:46:32 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_power(int r, int n)
{
	int				i;
	unsigned int	value;

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

static int	ft_calctens(unsigned int n)
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

char	*ft_uitoa(unsigned int n)
{
	int		i;
	int		tens;
	char	*str;

	i = 0;
	str = malloc(12 * sizeof(char));
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n *= -1;
	}
	tens = ft_calctens(n);
	while (tens >= 0)
	{
		str[i] = '0' + ((n / ft_power(10, tens)) % 10);
		i++;
		tens--;
	}
	str[i] = '\0';
	return (str);
}
