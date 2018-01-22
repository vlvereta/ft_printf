/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:42:38 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/22 09:43:52 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_to_output(t_info *p, char c)
{
	int 	i;
	int 	j;
	char	*temp;
	size_t	new_len;

	new_len = ft_strlen(p->output) + 1;
	if ((temp = ft_strnew(new_len)))
	{
		i = 0;
		j = 0;
		while (p->output[i])
			temp[j++] = p->output[i++];
		temp[j] = c;
		free(p->output);
		p->output = temp;
		p->outlen = (int)new_len;
	}
}

void	string_to_output(t_info *p, char *s)
{
	int 	i;
	int 	j;
	char	*temp;
	size_t	new_len;

	new_len = ft_strlen(p->output) + ft_strlen(s);
	if ((temp = ft_strnew(new_len)))
	{
		i = 0;
		j = 0;
		while (p->output[i])
			temp[j++] = p->output[i++];
		free(p->output);
		i = 0;
		while (s[i])
			temp[j++] = s[i++];
		free(s);
		p->output = temp;
		p->outlen = (int)new_len;
	}
}

unsigned long long	to_unsigned(t_info *p)
{
	if (p->cur_flags->l)
		return(va_arg(p->ap, unsigned long));
	else if (p->cur_flags->ll)
		return(va_arg(p->ap, unsigned long long));
	else if (p->cur_flags->h)
		return((unsigned short)va_arg(p->ap, int));
	else if (p->cur_flags->hh)
		return((unsigned char)va_arg(p->ap, int));
	else if (p->cur_flags->j)
		return(va_arg(p->ap, uintmax_t));
	else if (p->cur_flags->z)
		return(va_arg(p->ap, size_t));
	else
		return(va_arg(p->ap, unsigned int));
}

char	*llu_base(unsigned long long value, int base)
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
