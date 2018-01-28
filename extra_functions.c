/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:42:38 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/22 09:43:52 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*wchar_encoder(unsigned int c, char **unichar)
{
	char	*wc;

	wc = *unichar;
	ft_bzero(wc, sizeof(char) * 5);
	if (c < 128)
		wc[0] = c;
	else if (c < 2048)
	{
		wc[0] = c >> 6 | 0xC0;
		wc[1] = (c << 26) >> 26 | 0x80;
	}
	else if (c < 65536)
	{
		wc[0] = ((c >> 12) << 28) >> 28 | 0xE0;
		wc[1] = ((c >> 6) << 26) >> 26 | 0x80;
		wc[2] = (c << 26) >> 26 | 0x80;
	}
	else
	{
		wc[0] = ((c >> 18) << 29) >> 29 | 0xF0;
		wc[1] = ((c >> 12) << 26) >> 26 | 0x80;
		wc[2] = ((c >> 6) << 26) >> 26 | 0x80;
		wc[3] = (c << 26) >> 26 | 0x80;
	}
	return (wc);
}

void				char_to_output(t_info *p, char c)
{
	char			*temp;
	unsigned long	i;
	unsigned long	j;
	unsigned long	new_len;

	new_len = p->outlen + 1;
	if ((temp = ft_strnew(new_len)))
	{
		i = 0;
		j = 0;
		while (i < p->outlen)
			temp[j++] = p->output[i++];
		temp[j] = c;
		free(p->output);
		p->output = temp;
		p->outlen = new_len;
	}
}

void				string_to_output(t_info *p, char *s)
{
	char			*temp;
	unsigned long	i;
	unsigned long	j;
	unsigned long	new_len;

	if (s && *s)
	{
		new_len = p->outlen + ft_strlen(s);
		if ((temp = ft_strnew(new_len)))
		{
			i = 0;
			j = 0;
			while (j < p->outlen)
				temp[j++] = p->output[i++];
			free(p->output);
			i = 0;
			while (j < new_len)
				temp[j++] = s[i++];
			free(s);
			p->output = temp;
			p->outlen = new_len;
		}
	}
}

unsigned long long	to_unsigned(t_info *p)
{
	if (p->cur_flags->z)
		return (va_arg(p->ap, size_t));
	else if (p->cur_flags->j)
		return (va_arg(p->ap, uintmax_t));
	else if (p->cur_flags->ll)
		return (va_arg(p->ap, unsigned long long));
	else if (p->cur_flags->l)
		return (va_arg(p->ap, unsigned long));
	else if (p->cur_flags->h)
		return ((unsigned short)va_arg(p->ap, int));
	else if (p->cur_flags->hh)
		return ((unsigned char)va_arg(p->ap, int));
	else
		return (va_arg(p->ap, unsigned int));
}

char				*llu_base(unsigned long long value, int base)
{
	int					size;
	char				*result;
	unsigned long long	temp;

	temp = value;
	size = (!value ? 1 : 0);
	while (temp)
	{
		temp /= base;
		size++;
	}
	if ((result = (char *)malloc(sizeof(char) * (size + 1))))
	{
		result[size] = '\0';
		if (!value)
			result[--size] = '0';
		while (value)
		{
			temp = value % base;
			result[--size] = (temp > 9 ? temp + 87 : temp + '0');
			value /= base;
		}
	}
	return (result);
}
