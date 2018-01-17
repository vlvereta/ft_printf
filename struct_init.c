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

	// must be freed at the end
	if (!(p->cur_flags = (t_flags *)malloc(sizeof(t_flags))))
		return (0);
	ft_bzero(p->cur_flags, sizeof(t_flags));

	// must be freed at the end
	if (!(p->output = (char *)malloc(sizeof(char))))
		return (0);
	*(p->output) = '\0';
	p->types = "aAcCdDeEfFgGinoOpsSuUxX";
	handlers_init(p->type_handlers);
	return (1);
}

void	handlers_init(type_handler *type_handlers)
{
	type_handlers[0] = NULL;
	type_handlers[1] = NULL;
	type_handlers[2] = NULL;
	type_handlers[3] = NULL;
	type_handlers[4] = &type_low_d;
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

void	cleaning(t_info *p)
{
	if (p->cur_flags)
		free(p->cur_flags);
	if (p->output)
		free(p->output);
}