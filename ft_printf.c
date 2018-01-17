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

int		ft_printf(const char *format, ...)
{
	int 	t;
	t_info	p;

	start_initialization(&p);
	va_start(p.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
				ft_putchar('%');
			else if ((t = read_format((char **)(&format), &p)) != -1)
				p.type_handlers[t](&p.ap, p.cur_flags);
			else
				continue ;
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(p.ap);
	cleaning(&p);
	return (p.outlen);
}

/* read_format: read flags and other mods while correct type specifier (return i-th)
 * or end of the line (return -1) will be finded */
int		read_format(char **format, t_info *p)
{
	int 	i;

	ft_bzero(p->cur_flags, sizeof(t_flags));
	while (**format)
	{
		i = 0;
		while (i < TYPES)
			if (**format == p->types[i++])
				return (--i);
		if (**format == '-')
			p->cur_flags->left++;
		else if (**format == '+')
			p->cur_flags->sign++;
		else if (**format == ' ')
			p->cur_flags->space++;
		else if (**format == '#')
			p->cur_flags->hash++;
		else if (**format == '0')
			p->cur_flags->zero++;
		else
			if (!check_mods(format, p))
				break ;
		(*format)++;
	}
	return (-1);
}

int 	check_mods(char **format, t_info *p)
{
	return (0);
}

void	type_low_d(va_list *ap, t_flags *flags)
{
	int 	num;
	char	*s_num;

	num = va_arg(*ap, int);
	s_num = ft_itoa(num);
	ft_putstr(s_num);
}