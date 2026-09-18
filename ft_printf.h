/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:48:48 by nilim             #+#    #+#             */
/*   Updated: 2026/09/18 10:00:27 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# define DSH 0b10000
# define POS 0b01000
# define ZER 0b00100
# define SPC 0b00010
# define PND 0b00001

// Flags:5 (-+0 #)

typedef struct s_options
{
	int		flag;
	int		width;
	int		oriwidth;
	int		prec;
	char	spec;
	int		numsign;
	int		arglen;
	int		prog;
	int		count;
}	t_options;

int		ft_printf(const char *format, ...);
int		parse(const char *format, t_options *opts);
int		putarg(t_options *opts, va_list args);
void	setarglen(t_options *opts, va_list args);
int		pf_putchar_fd(char c, t_options *opts);
void	pf_putstr_fd(char *s, t_options *opts);
void	pf_putnbr_fd(long long n, t_options *opts);
int		ft_putuint_fd(unsigned int n, char format, t_options *opts);
void	ft_putptr_fd(uintptr_t n, t_options *opts);

void	debug(t_options *opts);

#endif