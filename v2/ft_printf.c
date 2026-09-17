/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:50:22 by nilim             #+#    #+#             */
/*   Updated: 2026/09/17 15:05:06 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	debug(t_options *opts)
{
	printf("prec: %d\n", opts->prec);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	printsum;
	t_options		*options;

	printsum = 0;
	va_start(args, format);
	options = ft_calloc(1, sizeof(t_options));
	while (*format)
	{
		if (*format == '%' && parse(format, options))
		{
			format += options->prog;
			setarglen(options, args);
			putarg(options, args);
			printsum += options->count;
		}
		else
		{
			pf_putchar_fd(*format++, options);
			printsum++;
		}
	}
	va_end(args);
	free(options);
	return (printsum);
}
