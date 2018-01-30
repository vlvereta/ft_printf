/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:35:01 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/29 14:35:16 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_low_p(void *info)
{
	t_info	*p;
	void	*ptr;
	char	*result;

	p = (t_info *)info;
//	ptr = va_arg(p->ap, void *);
//	if (!(result = llu_base((unsigned long long)ptr, 16)))
//		return ;
	if (!(ptr = va_arg(p->ap, void *)) && !p->cur_flags->prec)
		result = ft_strnew(0);
	else if (!(result = llu_base((unsigned long long)ptr, 16)))
		return ;
	p->cur_flags->hash = 1;
	check_flags_for_oux(p->cur_flags, &result, 'x');
	string_to_output(p, result);
}

void	type_low_o(void *info)
{
	t_info				*p;
	unsigned long long	num;
	char				*result;

	p = (t_info *)info;
//	num = to_unsigned(p);
//	if (!(result = llu_base(num, 8)))
//		return ;
	if (!(num = to_unsigned(p)) && !p->cur_flags->prec && !p->cur_flags->hash)
		result = ft_strnew(0);
	else if (!(result = llu_base(num, 8)))
		return ;
	if (!num && p->cur_flags->hash)
		p->cur_flags->hash = 0;
	check_flags_for_oux(p->cur_flags, &result, 'o');
	string_to_output(p, result);
}

void	type_high_o(void *info)
{
	t_info	*p;

	p = (t_info *)info;
	p->cur_flags->l = 1;
	type_low_o(p);
}

void	type_low_x(void *info)
{
	t_info				*p;
	unsigned long long	num;
	char				*result;

	p = (t_info *)info;
//	num = to_unsigned(p);
//	if (!(result = llu_base(num, 16)))
//		return ;
	if (!(num = to_unsigned(p)) && !p->cur_flags->prec)
		result = ft_strnew(0);
	else if (!(result = llu_base(num, 16)))
		return ;
	if (!num && p->cur_flags->hash)
		p->cur_flags->hash = 0;
	check_flags_for_oux(p->cur_flags, &result, 'x');
	string_to_output(p, result);
}

void	type_high_x(void *info)
{
	int					i;
	t_info				*p;
	unsigned long long	num;
	char				*result;

	p = (t_info *)info;
//	num = to_unsigned(p);
//	if (!(result = llu_base(num, 16)))
//		return ;
	if (!(num = to_unsigned(p)) && !p->cur_flags->prec)
		result = ft_strnew(0);
	else if (!(result = llu_base(num, 16)))
		return ;
	if (!num && p->cur_flags->hash)
		p->cur_flags->hash = 0;
	check_flags_for_oux(p->cur_flags, &result, 'x');
	i = 0;
	while (result[i])
	{
		if (ft_islower(result[i]))
			result[i] = ft_toupper(result[i]);
		i++;
	}
	string_to_output(p, result);
}
