/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 11:15:55 by nilim             #+#    #+#             */
/*   Updated: 2026/09/15 12:32:47 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdint.h>

void	ft_putptr_fd(uintptr_t n, t_options *opts)
{
	if (n > 15)
		ft_putptr_fd(n / 16, opts);
	if (n % 16 < 10)
		pf_putchar_fd('0' + (n % 16), opts);
	else
		pf_putchar_fd('a' + (n % 16 - 10), opts);
}
