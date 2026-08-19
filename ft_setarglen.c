/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setarglen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 22:47:58 by nilim             #+#    #+#             */
/*   Updated: 2026/08/15 16:58:58 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>

static int	ft_strnlen(const char *str, size_t n)
{
	size_t	c;

	c = 0;
	while (str[c] && c < n)
		c++;
	return (c);
}

static unsigned int	intlen(t_options *opts, int n)
{
	unsigned int	c;

	c = 0;
	if (n < 0)
		opts->numsign = -1;
	else if (n == 0)
		return (1);
	while (n && ++c)
		n /= 10;
	return (c);
}

static unsigned int	uintlen(unsigned int n, char base)
{
	unsigned int	c;

	c = 0;
	if (ft_strchr("xX", base))
		while (n && ++c)
			n /= 16;
	else
		while (n && ++c)
			n /= 10;
	return (c);
}

static unsigned int	uiptrlen(uintptr_t n)
{
	unsigned int	c;

	c = 0;
	while (n && ++c)
		n /= 16;
	return (c);
}

void	ft_setarglen(t_options *opts, va_list oriargs)
{
	va_list	args;

	va_copy(args, oriargs);
	if (ft_strchr("di", opts->spec))
		opts->arglen = intlen(opts, va_arg(args, int));
	else if (ft_strchr("c%", opts->spec))
		opts->arglen = 1;
	else if (opts->spec == 's' && opts->prec < 0)
		opts->arglen = ft_strlen(va_arg(args, char *));
	else if (opts->spec == 's')
		opts->arglen = ft_strnlen(va_arg(args, char *), opts->prec);
	else if (opts->spec == 'p')
		opts->arglen = uiptrlen((uintptr_t)va_arg(args, void *));
	else if (ft_strchr("uxX", opts->spec))
		opts->arglen = uintlen(va_arg(args, unsigned int), opts->spec);
	va_end(args);
	opts->width -= opts->arglen;
	if ((opts->pound && ft_strchr("xX", opts->spec)) || opts->spec == 'p')
		opts->width -= 2;
	if (ft_strchr("idu", opts->spec) && (opts->positive || opts->space))
		opts->width--;
	if (ft_strchr("idupxX", opts->spec) && opts->prec > (int)opts->arglen)
		opts->width -= opts->prec - (int)opts->arglen;
}
