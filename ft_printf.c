/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/03 23:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_pit pf;

	pf.specifier = "sSpdDioOuUxXcC";

	va_start(pf.ap, format);
	while (*format)
	{
		if (*format == '%')
//			check_specifier(format, pf);
		else
			write(1, format, 1);
		format++;
	}
	va_end(pf.ap);
	return (0);
}



