/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/03 23:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	start_initialization(t_info *pf)
{
	pf->types = "sSpdDioOuUxXcCeEfFgGaAn";
	pf->cur_flags = (t_flags *)malloc(sizeof(t_flags));
	flags_init(pf->cur_flags);
	handlers_init(pf->type_handlers);
	pf->printed = 0;
}

void	flags_init(t_flags *flags)
{
	flags->hash = 0;
	flags->left = 0;
	flags->prec = 0;
	flags->sign = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->width = 0;
}

void	handlers_init(type_handler *type_handlers)
{
	type_handlers[0] = &test_handler;
	type_handlers[1] = NULL;
	type_handlers[2] = NULL;
	type_handlers[3] = NULL;
	type_handlers[4] = NULL;
	type_handlers[5] = NULL;
	type_handlers[6] = NULL;
	type_handlers[7] = NULL;
	type_handlers[8] = NULL;
	type_handlers[9] = NULL;
	type_handlers[10] = NULL;
	type_handlers[11] = NULL;
	type_handlers[12] = NULL;
	type_handlers[13] = NULL;
	type_handlers[14] = NULL;
	type_handlers[15] = NULL;
	type_handlers[16] = NULL;
	type_handlers[17] = NULL;
	type_handlers[18] = NULL;
	type_handlers[19] = NULL;
	type_handlers[20] = NULL;
	type_handlers[21] = NULL;
	type_handlers[22] = NULL;
}
