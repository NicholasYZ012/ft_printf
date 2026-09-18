/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:07:13 by nilim             #+#    #+#             */
/*   Updated: 2026/09/18 09:54:25 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	pf_putstr_fd(char *s, t_options *opts)
{
	if (s == NULL)
		return (pf_putstr_fd("(null)", opts));
	while (*s)
		pf_putchar_fd(*s++, opts);
}
