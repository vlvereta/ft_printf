/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_low_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 09:41:32 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/28 12:34:47 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	function to operate with d and i types specifiers
*/

void	type_low_di(void *info)
{
	t_info		*p;
	long long	num;
	char		*result;

	p = (t_info *)info;
	if (p->cur_flags->z)
		num = va_arg(p->ap, ssize_t);
	else if (p->cur_flags->j)
		num = va_arg(p->ap, intmax_t);
	else if (p->cur_flags->ll)
		num = va_arg(p->ap, long long);
	else if (p->cur_flags->l)
		num = va_arg(p->ap, long);
	else if (p->cur_flags->h)
		num = (short)va_arg(p->ap, int);
	else if (p->cur_flags->hh)
		num = (char)va_arg(p->ap, int);
	else
		num = va_arg(p->ap, int);
	if (!(result = ft_itoa_base(num, 10)))
		return ;
	check_flags_for_di(p->cur_flags, &result);
	string_to_output(p, result);
}

void	check_flags_for_di(t_flags *flags, char **str)
{
	int 	i;
	char	sign;
	char	*result;

	sign = 0;
	if (**str == '-' || flags->space || flags->sign)
	{
		sign = (**str == '-' ? '-' : sign);
		sign = (flags->space && **str != '-' ? ' ' : sign);
		sign = (flags->sign && **str != '-' ? '+' : sign);
	}
	result = (**str == '-' ? *str + 1 : *str);
	result = precision_for_di(flags, result, sign);
	result = width_for_di(flags, result, sign);
	if (sign)
	{
		i = 1;
		while (result[i] == ' ')
			i++;
		result[--i] = sign;
	}
	*str = result;
}

char	*precision_for_di(t_flags *flags, char *str, char sign)
{
	int 	len;
	int 	new_len;
	char	*result;

	if ((len = ft_strlen(str)))
	{
		if (flags->prec > len && (result = ft_strnew(flags->prec)))
		{
			new_len = flags->prec;
			ft_memset(result, '0', new_len);
			while (len)
				result[--new_len] = str[--len];
			sign == '-' ? free(--str) : free(str);
			return (result);
		}
		if (sign == '-')
		{
			result = ft_strdup(str);
			free(--str);
			return (result);
		}
	}
	return (str);
}

char	*width_for_di(t_flags *flags, char *str, char sign)
{
	int		len;
	int		last;
	int 	new_len;
	char	*result;

	if ((len = (sign ? ft_strlen(str) + 1 : ft_strlen(str))))
	{
		new_len = (flags->width > len ? flags->width : len);
		if ((new_len > len || sign) && (result = ft_strnew(new_len)))
		{
			ft_memset(result, ' ', new_len);
			if (flags->zero && !flags->prec && !flags->left)
				ft_memset(result, '0', new_len);
			last = (flags->left ? len : new_len);
			len = (sign ? len - 1 : len);
			while (len)
				result[--last] = str[--len];
			free(str);
			return (result);
		}
	}
	return (str);
}
