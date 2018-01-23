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

int		start_initialization(t_info *p)
{
	ft_bzero(p, sizeof(t_info));
	if (!(p->cur_flags = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	ft_bzero(p->cur_flags, sizeof(t_flags));
	if (!(p->output = (char *)malloc(sizeof(char))))
		return (0);
	*(p->output) = '\0';
	p->types = "aAcCdDeEfFgGinoOpsSuUxX";
	handlers_init(p->type_handlers);
	return (1);
}

void	handlers_init(t_handler *type_handlers)
{
	type_handlers[0] = NULL;
	type_handlers[1] = NULL;
	type_handlers[2] = &type_low_c;
	type_handlers[3] = &type_high_c;
	type_handlers[4] = &type_low_di;
	type_handlers[5] = &type_high_d;
	type_handlers[6] = NULL;
	type_handlers[7] = NULL;
	type_handlers[8] = NULL;
	type_handlers[9] = NULL;
	type_handlers[10] = NULL;
	type_handlers[11] = NULL;
	type_handlers[12] = &type_low_di;
	type_handlers[13] = &type_low_n;
	type_handlers[14] = &type_low_o;
	type_handlers[15] = &type_high_o;
	type_handlers[16] = &type_low_p;
	type_handlers[17] = &type_low_s;
	type_handlers[18] = NULL;
	type_handlers[19] = &type_low_u;
	type_handlers[20] = &type_high_u;
	type_handlers[21] = &type_low_x;
	type_handlers[22] = &type_high_x;
}

void	cleaning(t_info *p)
{
	if (p->cur_flags)
		free(p->cur_flags);
	if (p->output)
		free(p->output);
}
