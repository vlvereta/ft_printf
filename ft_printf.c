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
	int		t;
	t_info	p;

	start_initialization(&p);
	va_start(p.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
				char_to_output(&p, '%');
			else if ((t = read_format((char **)(&format), &p)) != -1)
				p.type_handlers[t](&p);
			else
				continue ;
		}
		else
			char_to_output(&p, *format);
		format++;
	}
	write(1, p.output, p.outlen);
	va_end(p.ap);
	cleaning(&p);
	return (p.outlen);
}

int		read_format(char **format, t_info *p)
{
	int		i;

	ft_bzero(p->cur_flags, sizeof(t_flags));
	while (**format)
	{
		i = 0;
		while (i < TYPES)
			if (**format == p->types[i++])
				return (--i);
		if (**format == '-')
			p->cur_flags->left = 1;
		else if (**format == '+')
			p->cur_flags->sign = 1;
		else if (**format == ' ')
			p->cur_flags->space = 1;
		else if (**format == '#')
			p->cur_flags->hash = 1;
		else if (**format == '0')
			p->cur_flags->zero = 1;
		else if (!check_mods(format, p))
			break ;
		(*format)++;
	}
	return (-1);
}

int		check_mods(char **format, t_info *p)
{
	if (ft_isdigit(**format))
	{
		p->cur_flags->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	else if (**format == '*')
		p->cur_flags->width = va_arg(p->ap, int);
	else if (**format == '.')
		check_precision(format, p);
	else
		return (check_size(format, p) ? 1 : 0);
	return (1);
}

void	check_precision(char **format, t_info *p)
{
	if (ft_isdigit(*(*format + 1)))
	{
		p->cur_flags->prec = ft_atoi(++(*format));
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	else if (*(*format + 1) == '*')
	{
		(*format)++;
		p->cur_flags->prec = va_arg(p->ap, int);
	}
}

int		check_size(char **format, t_info *p)
{
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		(*format)++;
		p->cur_flags->ll = 1;
	}
	else if (**format == 'l')
		p->cur_flags->l = 1;
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		(*format)++;
		p->cur_flags->hh = 1;
	}
	else if (**format == 'h')
		p->cur_flags->h = 1;
	else if (**format == 'j')
		p->cur_flags->j = 1;
	else if (**format == 'z')
		p->cur_flags->z = 1;
	else if (**format == 'L')
		p->cur_flags->high_l = 1;
	else
		return (0);
	return (1);
}
