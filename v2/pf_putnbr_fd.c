/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:14:27 by nilim             #+#    #+#             */
/*   Updated: 2026/09/15 12:33:51 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	pf_putnbr_fd(long n, t_options *opts)
{
	if (n > 9)
		pf_putnbr_fd(n / 10, opts);
	pf_putchar_fd('0' + (n % 10), opts);
}
