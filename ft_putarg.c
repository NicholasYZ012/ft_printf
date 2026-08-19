/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:39:07 by nilim             #+#    #+#             */
/*   Updated: 2026/08/15 16:58:08 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>

static void	putprecstr_fd(t_options *opts, char *str, int fd)
{
	if (opts->prec <= -1)
		return (ft_putstr_fd(str, fd));
	while (opts->prec-- && *str)
		ft_putchar_fd(*str++, fd);
}

static void	putposnum_fd(t_options *opts, int nb, int fd)
{
	if (opts->prec == 0)
		return ;
	if (++opts->numsign == 0 && nb != -2147483648)
		ft_putchar_fd('-', 1);
	if (nb > 0)
		return (ft_putnbr_fd(nb, fd));
	if (nb < 0)
		ft_putnbr_fd(nb *= -1, fd);
}

static void	dashhandler(t_options *opts, int prog)
{
	if (!opts->dash && prog == 0)
	{
		if (opts->zero && opts->prec < 0)
		{
			if (++opts->numsign == 0)
				ft_putchar_fd('-', 1);
			while (opts->width > 0 && opts->width--)
				ft_putchar_fd('0', 1);
		}
		else
			while (opts->width > 0 && opts->width--)
				ft_putchar_fd(' ', 1);
	}
	else if (opts->dash && prog == 1)
		while (opts->width > 0 && opts->width--)
			ft_putchar_fd(' ', 1);
}

static void	flaghandler(t_options *opts, va_list oriargs)
{
	va_list	args;

	va_copy(args, oriargs);
	dashhandler(opts, 0);
	if (opts->positive && opts->spec != 'u')
		if (va_arg(args, int) >= 0 && ft_strchr("dip", opts->spec))
			ft_putchar_fd('+', 1);
	if (!opts->positive && opts->space && ft_strchr("dip", opts->spec))
		if (va_arg(args, int) >= 0 || opts->spec == 'p')
			ft_putchar_fd(' ', 1);
	if ((va_arg(args, unsigned int) && opts->pound) || opts->spec == 'p')
	{
		if (ft_strchr("xp", opts->spec))
			ft_putstr_fd("0x", 1);
		else if (opts->spec == 'X')
			ft_putstr_fd("0X", 1);
	}
	while (ft_strchr("diupxX", opts->spec) && opts->prec-- > (int)opts->arglen)
		ft_putchar_fd('0', 1);
	va_end(args);
}

void	ft_putarg(t_options *opts, va_list args)
{
	if (opts->spec == '%')
		return (ft_putchar_fd('%', 1));
	flaghandler(opts, args);
	if (opts->spec == 'i' || opts->spec == 'd')
		putposnum_fd(opts, va_arg(args, int), 1);
	else if (opts->spec == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (opts->spec == 's')
		putprecstr_fd(opts, va_arg(args, char *), 1);
	else if (ft_strchr("uxX", opts->spec))
		ft_putuint_fd(va_arg(args, unsigned int), opts->spec, 1);
	else if (opts->spec == 'p')
		ft_putptr_fd((uintptr_t)va_arg(args, void *), 1);
	dashhandler(opts, 1);
}
