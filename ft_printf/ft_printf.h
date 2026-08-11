/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:48:48 by nilim             #+#    #+#             */
/*   Updated: 2026/08/11 17:37:12 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
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
	char			specifier;
}	t_options;

int		ft_printf(const char *format, ...);
int		parse(const char *format, t_options *opts);

#endif