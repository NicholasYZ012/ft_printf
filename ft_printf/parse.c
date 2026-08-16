/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:42:30 by nilim             #+#    #+#             */
/*   Updated: 2026/08/15 16:27:38 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	flag_parser(const char flag, t_options *opts)
{
	if (flag == '-')
		opts->dash = 1;
	else if (flag == '+')
		opts->positive = 1;
	else if (flag == '0')
		opts->zero = 1;
	else if (flag == ' ')
		opts->space = 1;
	else if (flag == '#')
		opts->pound = 1;
}

int	parse(const char *format, t_options *opts)
{
	ft_bzero(opts, sizeof(t_options));
	opts->prec = (unsigned int)-1;
	while (ft_strchr("-+0 #", format[++opts->prog]))
		flag_parser(format[opts->prog], opts);
	while (ft_isdigit(format[opts->prog]))
		opts->width = (opts->width * 10) + (format[opts->prog++] - '0');
	if (format[opts->prog] == '.' && ++opts->prec == 0)
	{
		if (!ft_isdigit(format[opts->prog + 1]))
			opts->prec = 0;
		while (ft_isdigit(format[++(opts->prog)]))
			opts->prec = (opts->prec * 10) + (format[opts->prog] - '0');
	}
	if (ft_strchr("cspdiuxX%", format[opts->prog]))
	{
		opts->spec = format[opts->prog];
		return (++opts->prog);
	}
	else
		return (opts->prog = 0);
}
