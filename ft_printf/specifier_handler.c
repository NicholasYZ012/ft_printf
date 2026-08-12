/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:39:07 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 13:29:53 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	specifier_handler(t_options *opts, va_list args)
{
	if (opts->specifier == 'i' || opts->specifier == 'd')
		return (ft_putstr_fd(ft_itoa(va_arg(args, int)), 1));
	else if (opts->specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (opts->specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (opts->specifier == 'p')
		return ;
	else if (opts->specifier == 'u')
		return (ft_putstr_fd(ft_uitoa(va_arg(args, unsigned int)), 1));
	else if (opts->specifier == 'x')
		return ;
	else if (opts->specifier == 'X')
		return ;
	else if (opts->specifier == '%')
		return (ft_putchar_fd('%', 1));
}
