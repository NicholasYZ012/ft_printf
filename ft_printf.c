/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:50:22 by nilim             #+#    #+#             */
/*   Updated: 2026/08/15 16:41:12 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>
void	strchk(t_options *opts)
{
	printf("\n\ndash = %d\n", opts->dash);
	printf("pos = %d\n", opts->positive);
	printf("zero = %d\n", opts->zero);
	printf("space= %d\n", opts->space);
	printf("pound = %d\n", opts->pound);
	printf("width = %d\n", opts->width);
	printf("prec = %d\n", opts->prec);
	printf("arglen = %d\n", opts->arglen);
	printf("spec = %c\n\n", opts->spec);
}

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
			// strchk(options);
			ft_setarglen(options, args);
			// strchk(options);
			ft_putarg(options, args);
		}
		else
			ft_putchar_fd(*format++, 1);
	}
	va_end(args);
	free(options);
	return (1);
}
