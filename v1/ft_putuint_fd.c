/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:52:20 by nilim             #+#    #+#             */
/*   Updated: 2026/08/15 14:36:05 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putuint_fd(unsigned int n, char format, int fd)
{
	if (ft_strchr("xX", format))
	{
		if (n > 15)
			ft_putuint_fd(n / 16, format, fd);
	}
	else if (n > 9)
		ft_putuint_fd(n / 10, format, fd);
	if (n % 16 < 10)
		ft_putchar_fd('0' + (n % 16), fd);
	else if (format == 'X')
		ft_putchar_fd('A' + (n % 16 - 10), fd);
	else if (format == 'x')
		ft_putchar_fd('a' + (n % 16 - 10), fd);
	else
		ft_putchar_fd('0' + (n % 10), fd);
}
