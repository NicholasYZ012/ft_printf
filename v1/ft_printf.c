/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:50:22 by nilim             #+#    #+#             */
/*   Updated: 2026/09/12 12:35:48 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

void	debug(t_options *opts)
{
	printf("\nDEBUG\n");
	printf("width: %d\n", opts->width);
	printf("prec: %d\n", opts->prec);
	printf("arglen: %u\n", opts->arglen);
	printf("EBUG\n");
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	printsum;
	t_options		*options;

	va_start(args, format);
	options = ft_calloc(1, sizeof(t_options));
	while (*format)
	{
		if (*format == '%' && parse(format, options))
		{
			format += options->prog;
			setarglen(options, args);
			putarg(options, args);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			options->count++;
		}
	}
	va_end(args);
	printsum = options->count;
	free(options);
	return (printsum);
}
