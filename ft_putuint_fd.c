/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:52:20 by nilim             #+#    #+#             */
/*   Updated: 2026/09/18 10:01:03 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_putuint_fd(unsigned int n, char format, t_options *opts)
{
	if (ft_strchr("xX", format))
	{
		if (n > 15)
			ft_putuint_fd(n / 16, format, opts);
	}
	else if (n > 9)
		ft_putuint_fd(n / 10, format, opts);
	if (format == 'u')
		return (pf_putchar_fd('0' + (n % 10), opts));
	if (n % 16 < 10)
		pf_putchar_fd('0' + (n % 16), opts);
	else if (format == 'X')
		pf_putchar_fd('A' + (n % 16 - 10), opts);
	else if (format == 'x')
		pf_putchar_fd('a' + (n % 16 - 10), opts);
	return (0);
}
