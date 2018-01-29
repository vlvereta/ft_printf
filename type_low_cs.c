/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_low_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:02:29 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/29 18:02:40 by vlvereta         ###   ########.fr       */
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
		if (p->cur_flags->width > 1)
			width_for_low_c(p, c);
		else
			char_to_output(p, c);
	}
}

void	width_for_low_c(t_info *p, char c)
{
	char	*result;

	if ((result = ft_strnew(p->cur_flags->width - 1)))
	{
		ft_memset(result, ' ', p->cur_flags->width - 1);
		if (p->cur_flags->zero && !p->cur_flags->left)
			ft_memset(result, '0', p->cur_flags->width - 1);
		if (p->cur_flags->left)
		{
			char_to_output(p, c);
			string_to_output(p, result);
		}
		else
		{
			string_to_output(p, result);
			char_to_output(p, c);
		}
	}
}

void	type_low_s(void *info)
{
	char	*s;
	t_info	*p;
	char	*result;

	p = (t_info *)info;
	if (p->cur_flags->l)
		type_high_s(info);
	else
	{
		if ((s = va_arg(p->ap, char *)))
		{
			if (p->cur_flags->prec >= 0)
				result = precision_for_low_s(p->cur_flags, s);
			else
				result = ft_strdup(s);
			result = width_for_low_s(p->cur_flags, result);
			string_to_output(p, result);
		}
		else
			string_to_output(p, ft_strdup("(null)"));
	}
}

char	*precision_for_low_s(t_flags *flags, char *s)
{
	int		i;
	char	*result;

	if (!flags->prec)
		return (ft_strnew(0));
	if ((result = ft_strnew(flags->prec)))
	{
		i = 0;
		while (*s && i < flags->prec)
			result[i++] = *s++;
		return (result);
	}
	return (ft_strdup(s));
}

char	*width_for_low_s(t_flags *flags, char *s)
{
	int		len;
	int		last;
	char	*result;

	if (flags->width > (len = ft_strlen(s)))
	{
		if ((result = ft_strnew(flags->width)))
		{
			ft_memset(result, ' ', flags->width);
			if (flags->zero && !flags->left)
				ft_memset(result, '0', flags->width);
			last = (flags->left ? len : flags->width);
			while (len)
				result[--last] = s[--len];
			free(s);
			return (result);
		}
	}
	return (s);
}
