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

void	type_low_c(void *info)
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
		if ((s = va_arg(p->ap, char *)))
			string_to_output(p, ft_strdup(s));
		else
			string_to_output(p, ft_strdup("(null)"));
	}
}

void	type_high_c(void *info)
{
	t_info	*p;
	wchar_t	c;
	char	*unichar;

	p = (t_info *)info;
	c = va_arg(p->ap, wchar_t);
	if ((unichar = (char *)malloc(sizeof(char) * 5)))
	{
		wchar_encoder((unsigned int)c, &unichar);
		string_to_output(p, unichar);
	}
}

void	type_high_s(void *info)
{
	t_info	*p;
	wchar_t *s;
	char	*unichar;

	p = (t_info *)info;
	if ((s = va_arg(p->ap, wchar_t *)))
	{
		while (*s)
		{
			if ((unichar = (char *)malloc(sizeof(char) * 5)))
			{
				wchar_encoder((unsigned int) *s, &unichar);
				string_to_output(p, unichar);
				s++;
			}
		}
	}
	else
		string_to_output(p, ft_strdup("(null)"));
}
