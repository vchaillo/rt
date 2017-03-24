/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 11:12:48 by tlegroux          #+#    #+#             */
/*   Updated: 2017/02/13 13:57:25 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stddef.h>
# include <stdbool.h>
# include <math.h>

# define ALTERNATE_FORM 1
# define ZERO_PADDING 2
# define NEGATIVE_FIELDW 4
# define BLANK_SPACE 8
# define FORCE_SIGN 16
# define THOUSANDS_GROUP 32

typedef struct	s_conversion {
	int		attributes;
	size_t	field_width;
	int		precision;
	size_t	lengthmod;
	char	specifier;
}				t_conversion;

int				ft_printf(const char *format, ...);

/*
** parsing.c
*/
size_t			arg_handler(const char *format, va_list *args, size_t *n);
int				parse_specifiers(const char *s, t_conversion *c);
size_t			read_text(const char *s, size_t *n);

/*
** parsing_get.c
*/
size_t			printf_get_attributes(const char *s, t_conversion *c);
size_t			printf_get_field_width(const char *s, t_conversion *c);
size_t			printf_get_specifier(const char *s, t_conversion *c);
size_t			printf_get_precision(const char *s, t_conversion *c);
size_t			printf_get_length_modifier(const char *s, t_conversion *c);

/*
** get_arg.c
*/
uintmax_t		get_unumber(t_conversion *conversion, va_list *ap);
intmax_t		get_number(t_conversion *conversion, va_list *ap);
long double		get_dnumber(t_conversion *conversion, va_list *ap);

/*
** conversion_*.c
*/
int				get_conversion(t_conversion *c, va_list *args, size_t *pn);
char			*conversion_double(t_conversion *conv, va_list *ap);
char			*conversion_int(t_conversion *conv, va_list *ap);
char			*conversion_misc(t_conversion *conv, va_list *ap, size_t *pn);

/*
** formatting.c
** add conversion specific formatting to a string.
*/
void			do_formatting(char **str, t_conversion *conversion, short neg);

/*
** printf_xtoa.c
** convert number into properly formatted string.
** 
*/
char			*printf_uitoa(uintmax_t n, const char base, t_conversion *c);
char			*printf_etoa(long double n, t_conversion *c);
char			*printf_aitoa(long double n, t_conversion *c);
char			*printf_ftoa(long double n, t_conversion *c);

/*
** printf_etoa.c - tools
** get_exponent return the log10 exponent of a decimal number.
** shift_dec shift the decimal point closer to i.ffff,
** 	multiplying or dividing by ten
*/
int				get_exponent(long double n);
void			shift_dec(long double *ptr);

#endif
