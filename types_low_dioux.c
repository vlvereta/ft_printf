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

/*
**	function to operate with d and i types specifiers
*/

//void	type_low_di(void *info)
//{
//	t_info		*p;
//	long long	num;
//	char		*result;
//
//	p = (t_info *)info;
//	if (p->cur_flags->z)
//		num = va_arg(p->ap, ssize_t);
//	else if (p->cur_flags->j)
//		num = va_arg(p->ap, intmax_t);
//	else if (p->cur_flags->ll)
//		num = va_arg(p->ap, long long);
//	else if (p->cur_flags->l)
//		num = va_arg(p->ap, long);
//	else if (p->cur_flags->h)
//		num = (short)va_arg(p->ap, int);
//	else if (p->cur_flags->hh)
//		num = (char)va_arg(p->ap, int);
//	else
//		num = va_arg(p->ap, int);
//	if (!(result = ft_itoa_base(num, 10)))
//		return ;
//	check_flags_for_di(p->cur_flags, &result);
//	string_to_output(p, result);
//}
//
//void	check_flags_for_di(t_flags *flags, char **str)
//{
//	char	*result;
//
//	result = *str;
//	result = sign_or_space(flags, result);
//	result = precision_for_di(flags, result);
//	result = width_for_di(flags, result);
//	*str = result;
//}
//
//char	*sign_or_space(t_flags *flags, char *str)
//{
//	char	*result;
//
//	if (!str)
//		return (str);
//	if (flags->sign && *str != '-')
//		result = ft_strjoin("+", str);
//	else if (flags->space && *str != '-')
//		result = ft_strjoin(" ", str);
//	else
//		return (str);
//	free(str);
//	return (result);
//}
//
//char	*precision_for_di(t_flags *flags, char *str)
//{
//	int 	len;
//	int		sign;
//	int 	digits;
//	int 	result_len;
//	char	*result;
//
//	if ((len = ft_strlen(str)))
//	{
//		sign = (*str == '-' || *str == '+' || *str == ' ' ? 1 : 0);
//		if ((digits = len - sign) && flags->prec > digits)
//		{
//			result_len = flags->prec + sign;
//			if ((result = ft_strnew(result_len)))
//			{
//				ft_memset(result, '0', result_len);
//				if (sign)
//					result[0] = *str;
//				while (digits--)
//					result[--result_len] = str[--len];
//				free(str);
//				return (result);
//			}
//		}
//	}
//	return (str);
//}
//
//char	*width_for_di(t_flags *flags, char *str)
//{
//	int 	i;
//	int 	len;
//	int 	sign;
//	char	*result;
//
//	if ((len = ft_strlen(str)))
//	{
//		sign = (*str == '-' || *str == '+' || *str == ' ' ? 1 : 0);
//		if (flags->width > len && (result = ft_strnew(flags->width)))
//		{
//			if (flags->zero && !flags->left && !flags->prec)
//				ft_memset(result, '0', flags->width);
//			else
//				ft_memset(result, ' ', flags->width);
//			if (sign && !result[0])
//				result[0] = *(str++);
//			len = (result[0] == ' ' ? len : len - 1);
//			i = (flags->left ? 1 : flags->width - len);
//			while (*str)
//				result[i++] = *(str++);
//			return (result);
//		}
//	}
//	return (str);
//}




char	*check_hash(char *num, char type)
{
	char	*result;

	if (!num)
		return (num);
	if (type == 'o' && *num)
		result = ft_strjoin("0", num);
	else if (type == 'x' && *num)
		result = ft_strjoin("0x", num);
	else if (type == 'X' && *num)
		result = ft_strjoin("0X", num);
	else
		return (num);
	free(num);
	return (result);
}

void	type_low_o(void *info)
{
	char				*r;
	t_info				*p;
	unsigned long long	num;

	p = (t_info *)info;
	if ((num = to_unsigned(p)) && p->cur_flags->hash)
		r = check_hash(llu_base(num, 8), 'o');
	else
		r = llu_base(num, 8);
	string_to_output(p, r);
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
	char				*r;
	t_info				*p;
	unsigned long long	num;

	p = (t_info *)info;
	if ((num = to_unsigned(p)) && p->cur_flags->hash)
		r = check_hash(llu_base(num, 16), 'x');
	else
		r = llu_base(num, 16);
	string_to_output(p, r);
}

void	type_high_x(void *info)
{
	int					i;
	char				*r;
	t_info				*p;
	unsigned long long	num;

	p = (t_info *)info;
	if ((num = to_unsigned(p)) && p->cur_flags->hash)
		r = check_hash(llu_base(num, 16), 'X');
	else
		r = llu_base(num, 16);
	i = 0;
	while (r[i])
	{
		if (ft_islower(r[i]))
			r[i] = ft_toupper(r[i]);
		i++;
	}
	string_to_output(p, r);
}
