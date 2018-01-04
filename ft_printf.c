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

#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	t_info		pf;

	va_start(pf.ap, format);
	start_initialization(&pf);
//	while (*format)
//	{
//		if (*format == '%')
//		{
//			if (*(++format) == '%')
//				write(1, "%", 1);
//		}
//		else
//			write(1, format, 1);
//		format++;
//	}
	va_end(pf.ap);
	return (pf.printed);
}

void	test_handler(void)
{
	printf(" - test\n");
	return ;
}


