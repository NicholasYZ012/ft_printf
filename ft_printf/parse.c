/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:42:30 by nilim             #+#    #+#             */
/*   Updated: 2026/08/12 13:29:05 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// 
// void	width_handler(const char *format, t_options *opts)
// void	prec_handler(const char *format, t_options *opts)

static void	flag_parser(const char *format, t_options *opts)
{
	if (format[opts->prog] == '-')
		opts->dash_flag = 1;
	else if (format[opts->prog] == '+')
		opts->positive_flag = 1;
	else if (format[opts->prog] == '0')
		opts->zero_flag = 1;
	else if (format[opts->prog] == ' ')
		opts->space_flag = 1;
	else if (format[opts->prog] == '#')
		opts->pound_flag = 1;
}

int	parse(const char *format, t_options *opts)
{
	opts->prog = 0;
	while (format[opts->prog])
	{
		opts->prog++;
		if (ft_strchr("-+0 #", format[opts->prog]))
			flag_parser(format, opts);
		else if (ft_strchr("cspdiuxX%", format[opts->prog]))
		{
			opts->specifier = format[opts->prog];
			return (++opts->prog);
		}
		else
			return (opts->prog = 0);
	}
	return (-1);
}
