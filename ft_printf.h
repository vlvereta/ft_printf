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

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define TYPES 23

# include <stdio.h> // delete later

typedef struct		s_flags
{
	int				width;
	int				prec;
	int				left;
	int				sign;
	int				space;
	int				hash;
	int				zero;
	int 			l;
	int 			ll;
	int 			h;
	int 			hh;
	int 			j;
	int 			z;
	int 			t;
	int 			high_l;
}					t_flags;

typedef void		(*type_handler)(va_list *, t_flags *);

typedef struct		s_info
{
	va_list			ap;
	const char		*types;
	type_handler 	type_handlers[TYPES];
	struct s_flags	*cur_flags;
	char 			*output;
	int				outlen;
}					t_info;

int					ft_printf(const char *format, ...);
int					start_initialization(t_info *p);
void				handlers_init(type_handler *type_handlers);
int					read_format(char **format, t_info *p);
int					check_mods(char **format, t_info *p);

void	type_low_d(va_list *ap, t_flags *flags);


void				cleaning(t_info *p);
#endif
