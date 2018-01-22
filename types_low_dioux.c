/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_low_dioux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:41:32 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/22 12:34:47 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_low_di(void *info)
{
	t_info		*p;
	long long	num;

	p = (t_info *)info;
	if (p->cur_flags->l)
		num = va_arg(p->ap, long);
	else if (p->cur_flags->ll)
		num = va_arg(p->ap, long long);
	else if (p->cur_flags->h)
		num = (short)va_arg(p->ap, int);
	else if (p->cur_flags->hh)
		num = (char)va_arg(p->ap, int);
	else if (p->cur_flags->j)
		num = va_arg(p->ap, intmax_t);
	else if (p->cur_flags->z)
		num = va_arg(p->ap, ssize_t);
	else
		num = va_arg(p->ap, int);
	string_to_output(p, ft_itoa_base(num, 10));
}

void	type_low_o(void *info)
{
	t_info				*p;
	unsigned long long	num;

	p = (t_info *)info;
	num = to_unsigned(p);
	string_to_output(p, llu_base(num, 8));
}

void	type_low_u(void *info)
{
	t_info				*p;
	unsigned long long	num;

	p = (t_info *)info;
	num = to_unsigned(p);
	string_to_output(p, llu_base(num, 10));
}

void	type_low_x(void *info)
{
	t_info				*p;
	unsigned long long	num;

	p = (t_info *)info;
	num = to_unsigned(p);
	string_to_output(p, llu_base(num, 16));
}

void	type_high_x(void *info)
{
	int i;
	char *t;
	t_info *p;
	unsigned long long num;

	p = (t_info *) info;
	num = to_unsigned(p);
	t = llu_base(num, 16);
	i = 0;
	while (t[i])
	{
		if (ft_islower(t[i]))
			t[i] = ft_toupper(t[i]);
		i++;
	}
	string_to_output(p, t);
}
