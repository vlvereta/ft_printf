/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlvereta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 23:15:03 by vlvereta          #+#    #+#             */
/*   Updated: 2018/01/03 23:18:32 by vlvereta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef void (*type_handler)();

typedef struct		s_info
{
	va_list			ap;
	const char		*types;
	type_handler 	type_handlers[23];
	struct s_flags	*cur_flags;
	int				printed;
}					t_info;

typedef struct		s_flags
{
	int				width;
	int				prec;
	int				left;
	int				sign;
	int				space;
	int				hash;
	int				zero;
}					t_flags;

int					ft_printf(const char *format, ...);
void				start_initialization(t_info *pf);
void				flags_init(t_flags *flags);
void				handlers_init(type_handler *type_handlers);


void	test_handler(void);
#endif
