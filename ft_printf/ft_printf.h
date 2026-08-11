/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:48:48 by nilim             #+#    #+#             */
/*   Updated: 2026/08/11 22:08:45 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_options
{
	unsigned int	dash_flag;
	unsigned int	positive_flag;
	unsigned int	zero_flag;
	unsigned int	space_flag;
	unsigned int	pound_flag;
	unsigned int	width;
	unsigned int	prec;
	char			specifier;
	unsigned int	prog;
}	t_options;

int		ft_printf(const char *format, ...);
int		parse(const char *format, t_options *opts);
void	specifier_handler(t_options *opts, va_list args);

#endif