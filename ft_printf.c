/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:50:22 by nilim             #+#    #+#             */
/*   Updated: 2026/08/24 10:39:19 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_options	*options;

	va_start(args, format);
	options = ft_calloc(1, sizeof(t_options));
	while (*format)
	{
		if (*format == '%' && parse(format, options))
		{
			format += options->prog;
			ft_setarglen(options, args);
			ft_putarg(options, args);
		}
		else
			ft_putchar_fd(*format++, 1);
	}
	va_end(args);
	free(options);
	return (1);
}
