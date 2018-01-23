/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_low_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 12:34:58 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/22 12:35:08 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_low_c(void	*info)
{
	char	c;
	t_info	*p;

	p = (t_info *)info;
	if (p->cur_flags->l)
		type_high_c(info);
	else
	{
		c = (char)va_arg(p->ap, int);
		char_to_output(p, c);
	}
}

void	type_low_s(void *info)
{
	char	*s;
	t_info	*p;

	p = (t_info *)info;
	if (p->cur_flags->l)
		type_high_s(info);
	else
	{
		s = va_arg(p->ap, char *);
		string_to_output(p, ft_strdup(s));
	}
}

void	type_high_c(void *info)
{
	wchar_t	c;
	t_info	*p;

	p = (t_info *)info;
	c = va_arg(p->ap, wchar_t);

	if (c < 128)
		ft_putchar(c);
	if (c > 127 && c < 2048)
	{
		ft_putchar((c >> 6) + 192);
		ft_putchar((c & 63) + 128);
	}
	if (c > 2047 && c < 65536)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
	}
	if (c > 65535 && c < 2097152)
	{
		ft_putchar((c >> 18) + 240);
		ft_putchar(((c >> 12) & 63) + 128);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
	}
}

void	type_high_s(void *info)
{
	return ;
}
