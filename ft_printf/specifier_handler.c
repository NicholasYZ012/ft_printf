/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 21:39:07 by nilim             #+#    #+#             */
/*   Updated: 2026/08/11 21:40:03 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	specifier_handler(t_options *opts, va_list args)
{
	if (opts->specifier == 'i')
		ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
}