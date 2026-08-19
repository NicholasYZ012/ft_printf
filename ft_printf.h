/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:48:48 by nilim             #+#    #+#             */
/*   Updated: 2026/08/15 16:28:22 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct s_options
{
	unsigned int	dash;
	unsigned int	positive;
	unsigned int	zero;
	unsigned int	space;
	unsigned int	pound;
	int				width;
	int				prec;
	char			spec;
	int				numsign;
	unsigned int	arglen;
	unsigned int	prog;
}	t_options;

int		ft_printf(const char *format, ...);
int		parse(const char *format, t_options *opts);
void	ft_putarg(t_options *opts, va_list args);
void	ft_setarglen(t_options *opts, va_list args);
void	ft_putuint_fd(unsigned int n, char format, int fd);
void	ft_putptr_fd(uintptr_t n, int fd);

void	strchk(t_options *opts);

#endif