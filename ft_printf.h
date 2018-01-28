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

#include <stdio.h>

typedef struct		s_flags
{
	int				width;
	int				prec;
	int				left;
	int				sign;
	int				space;
	int				hash;
	int				zero;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				j;
	int				z;
	int				high_l;
}					t_flags;

typedef void		(*t_handler)(void *);

typedef struct		s_info
{
	va_list			ap;
	const char		*types;
	t_handler		type_handlers[TYPES];
	struct s_flags	*cur_flags;
	char			*output;
	unsigned long	outlen;
}					t_info;

int					ft_printf(const char *format, ...);
int					start_initialization(t_info *p);
void				handlers_init(t_handler *type_handlers);
int					read_format(char **format, t_info *p);
int					read_mods(char **format, t_info *p);
void				read_precision(char **format, t_info *p);
int					read_size(char **format, t_info *p);

void				type_low_c(void *info);
void				type_high_c(void *info);

void				type_low_di(void *info);
void				check_flags_for_di(t_flags *flags, char **str);
char				*precision_for_di(t_flags *flags, char *str, char sign);
char				*width_for_di(t_flags *flags, char *str, char sign);
void				type_high_d(void *info);

void				type_low_n(void	*info);
void				type_low_o(void *info);
void				type_high_o(void *info);
void				type_low_p(void	*info);
void				type_low_s(void *info);
void				type_high_s(void *info);
void				type_low_u(void *info);
void				type_high_u(void *info);
void				type_low_x(void *info);
void				type_high_x(void *info);



char				*wchar_encoder(unsigned int c, char **unichar);
void				char_to_output(t_info *p, char c);
void				string_to_output(t_info *p, char *s);
char				*llu_base(unsigned long long value, int base);
unsigned long long	to_unsigned(t_info *p);

void				cleaning(t_info *p);
#endif
