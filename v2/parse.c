/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:42:30 by nilim             #+#    #+#             */
/*   Updated: 2026/09/17 10:13:50 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// Flags:5 (-+0 #)

static void	flag_parser(const char flag, t_options *opts)
{
	if (flag == '-')
		opts->flag |= DSH;
	else if (flag == '+')
		opts->flag |= POS;
	else if (flag == '0')
		opts->flag |= ZER;
	else if (flag == ' ')
		opts->flag |= SPC;
	else if (flag == '#')
		opts->flag |= PND;
}

static void	flag_validator(t_options *opts)
{
	if ((opts->flag & (POS | SPC)) == (POS | SPC))
		opts->flag &= ~(SPC);
	if ((opts->flag & DSH) != 0 || opts->prec > -1)
		opts->flag &= ~(ZER);
	if (opts->spec == 'p')
		opts->flag |= PND;
	if (ft_strchr("di", opts->spec))
		opts->flag &= (DSH | POS | ZER | SPC);
	else if (ft_strchr("pxX", opts->spec))
		opts->flag &= (DSH | ZER | PND);
	else
		opts->flag &= (DSH | ZER);
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
		while (ft_isdigit(format[++(opts->prog)]))
			opts->prec = (opts->prec * 10) + (format[opts->prog] - '0');
	if (ft_strchr("cspdiuxX%", format[opts->prog]))
	{
		opts->spec = format[opts->prog];
		flag_validator(opts);
		return (++opts->prog);
	}
	else
		return (opts->prog = 0);
}
