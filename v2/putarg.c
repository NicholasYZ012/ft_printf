/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:39:07 by nilim             #+#    #+#             */
/*   Updated: 2026/09/15 12:53:55 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>

static void	putprecstr_fd(t_options *opts, char *str)
{
	if (opts->prec <= -1)
		return (pf_putstr_fd(str, opts));
	while (opts->prec-- && *str)
		pf_putchar_fd(*str++, opts);
}

static void	putposnum_fd(t_options *opts, int nb)
{
	if (opts->prec == 0)
		return ;
	if (nb >= 0)
		return (pf_putnbr_fd(nb, opts));
	if (nb < 0)
		pf_putnbr_fd(nb *= -1, opts);
}

static void	dashwidthhandler(t_options *opts, int stage)
{
	if ((opts->flag & DSH) == 0 && stage == 0)
	{
		if ((opts->flag & ZER) != 0)
		{
			if (opts->numsign == -1 && ++opts->numsign == 0)
				pf_putchar_fd('-', opts);
			while (opts->width > opts->arglen + opts->count)
				pf_putchar_fd('0', opts);
		}
		else
		{
			if (opts->arglen >= opts->prec)
				while (opts->width > opts->arglen + opts->count)
					pf_putchar_fd(' ', opts);
			else
				while (opts->width > opts->prec + opts->count)
					pf_putchar_fd(' ', opts);
		}
	}
	else if ((opts->flag & DSH) != 0 && stage == 1)
		while (opts->width > opts->count)
			pf_putchar_fd(' ', opts);
}

static void	flaghandler(t_options *opts)
{
	if ((opts->flag & POS) != 0 && opts->numsign > 0)
		pf_putchar_fd('+', opts);
	if ((opts->flag & SPC) != 0)
		pf_putchar_fd(' ', opts);
	if ((opts->flag & PND) != 0 && ft_strchr("xp", opts->spec))
		pf_putstr_fd("0x", opts);
	else if (opts->spec == 'X')
		pf_putstr_fd("0X", opts);
	while (ft_strchr("diuxX", opts->spec) && opts->prec > (int)opts->arglen)
	{
		if (opts->numsign == -1 && ++opts->numsign == 0)
			pf_putchar_fd('-', opts);
		pf_putchar_fd('0', opts);
		opts->prec--;
	}
}

void	putarg(t_options *opts, va_list args)
{
	if (opts->spec == '%')
		return (pf_putchar_fd('%', opts));
	dashwidthhandler(opts, 0);
	flaghandler(opts);
	if (opts->spec == 'i' || opts->spec == 'd')
		putposnum_fd(opts, va_arg(args, int));
	else if (opts->spec == 'c')
		pf_putchar_fd(va_arg(args, int), opts);
	else if (opts->spec == 's')
		putprecstr_fd(opts, va_arg(args, char *));
	else if (ft_strchr("uxX", opts->spec))
		ft_putuint_fd(va_arg(args, unsigned int), opts->spec, opts);
	else if (opts->spec == 'p')
		ft_putptr_fd((uintptr_t)va_arg(args, void *), opts);
	dashwidthhandler(opts, 1);
}
