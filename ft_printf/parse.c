/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:42:30 by nilim             #+#    #+#             */
/*   Updated: 2026/08/11 17:37:05 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse(const char *format, t_options *opts)
{
	int	i;

	i = 0;
	while (format[i])
	{
		i++;
		if (ft_strchr("cspdiuxX%", format[i]))
		{
			opts->specifier = format[i];
			return (i++);
		}
	}
	return (0);
}
