/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:35:01 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/29 14:35:16 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_low_o(void *info)
{
	t_info				*p;
	unsigned long long	num;
	char				*result;

	p = (t_info *)info;
	num = to_unsigned(p);
	if (!(result = llu_base(num, 8)))
		return ;
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
	num = to_unsigned(p);
	if (!(result = llu_base(num, 16)))
		return ;
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
	num = to_unsigned(p);
	if (!(result = llu_base(num, 16)))
		return ;
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
