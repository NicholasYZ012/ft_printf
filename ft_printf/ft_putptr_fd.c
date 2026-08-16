/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 11:15:55 by nilim             #+#    #+#             */
/*   Updated: 2026/08/14 11:23:32 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdint.h>

void	ft_putptr_fd(uintptr_t n, int fd)
{
	if (n > 15)
		ft_putptr_fd(n / 16, fd);
	if (n % 16 < 10)
		ft_putchar_fd('0' + (n % 16), fd);
	else
		ft_putchar_fd('a' + (n % 16 - 10), fd);
}
