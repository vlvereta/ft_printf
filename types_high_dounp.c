/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_high_dounp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:10:22 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/23 10:10:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_low_n(void *info)
{
	t_info	*p;
	void	*ptr;

	p = (t_info *)info;
	ptr = va_arg(p->ap, void *);
	if (p->cur_flags->z)
		*((ssize_t *)ptr) = p->outlen;
	else if (p->cur_flags->j)
		*((intmax_t *)ptr) = p->outlen;
	else if (p->cur_flags->ll)
		*((long long *)ptr) = p->outlen;
	else if (p->cur_flags->l)
		*((long *)ptr) = p->outlen;
	else if (p->cur_flags->h)
		*((short *)ptr) = (short)p->outlen;
	else if (p->cur_flags->hh)
		*((char *)ptr) = (char)p->outlen;
	else
		*((int *)ptr) = p->outlen;
}
