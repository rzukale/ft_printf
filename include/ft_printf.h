/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 13:52:38 by rzukale           #+#    #+#             */
/*   Updated: 2022/07/06 01:48:44 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

typedef struct s_printf
{
	char		conversion[3];
	int			width;
	int			precision;
	int			sign;
	int			blank_sign;
	int			zero_padding;
	int			hash_sign;
	int			left_justify;
	int			precision_flag;
	char		c;
	int			is_zero;
	int			num_conversion_prec;
}				t_printf;

int					ft_printf(const char *format, ...);
int					ft_printf_internals(const char *format, va_list *ap);
void				ft_printf_write_output(char *str, int *i, int *printed);
int					get_flags_and_converted_arg(const char *format,
						va_list *ap, int *i);
int					parse_argument(va_list *ap, t_printf *tab, char c);
void				parse_all_modifiers(t_printf *tab);
void				parse_all_modifiers_two(t_printf *tab);
int					write_string(char *str);
void				ft_putnstr(char *str, int len, int *printed);
int					count_jump_length(char *str);
int					parse_unsigned_int(va_list *ap, t_printf *tab);
char				*get_unsigned_string_conversion(va_list *ap,
						t_printf *tab, unsigned long long *num);
unsigned long long	get_unsigned_int_conversion(va_list *ap, t_printf *tab);
void				get_uint_str_len(t_printf *tab, int *i,
						unsigned long long num);
void				get_uint_str_lentwo(t_printf *tab, int *i);
int					get_base(char c, int *up);
int					parse_string(va_list *ap, t_printf *tab);
void				count_string_len(t_printf *tab, int *i, char **str);
void				count_null_string_len(t_printf *tab, int *i);
char				*ft_longlong_itoa_base(long long n, int base);
void				get_sint_strlen(t_printf *tab, int *i,
						long long num, int neg);
void				get_sint_sign_width(t_printf *tab, int *i, long long num);
int					parse_signed_int(va_list *ap, t_printf *tab);
void				get_initial_values(t_printf *tab,
						int *i, char **num_str, long long num);
char				*parse_integer_argument(t_printf *tab, char *str,
						size_t str_len, int is_negative);
int					add_integer_prefix(t_printf *tab,
						char *str, int is_negative);
long long			get_signed_int_conversion(va_list *ap, t_printf *tab);
int					parse_pointer(va_list *ap, t_printf *tab);
char				*parse_pointer_str(t_printf *tab,
						int *ret, unsigned long ptr);
char				*parse_pointer_arg(t_printf *tab, char *str,
						size_t str_len, char *prefix);
int					add_number_to_string(char *dest, char *str);
int					add_pointer_prefix(t_printf *tab, char *str, char *prefix);
int					configure_ptr_len(t_printf *tab, int len);
void				configure_nullptr_len(t_printf *tab, int *ret);
int					parse_percent(t_printf *tab);
int					valid_conversion_marker(char c);
int					get_length_modifiers(const char *format, t_printf *tab);
int					get_precision(const char *format,
						va_list *ap, t_printf *tab);
int					get_width(t_printf *tab, va_list *ap, const char *format);
int					determine_flags(const char *format, t_printf *tab);
int					parse_float(va_list *ap, t_printf *tab);
long double			get_double_va_arg(t_printf *tab, va_list *ap);
void				get_double_len_modifiers(t_printf *tab,
						int *i, int is_negative);
char				*parse_double_argument(t_printf *tab, char *str,
						size_t str_len, int is_negative);
char				*ft_ftoa(long double num, int precision, int is_negative);
long double			get_fraction(long double num, char **str, int precision);
void				round_up(char **str, int i,
						int past_precision, int *add_space);
char				*get_whole_part(long long num);
int					count_digits(long long nbr);
void				check_sign(long double *num, int *neg, int *i);
int					parse_char(va_list *ap, t_printf *tab);
void				write_len(char *str, int len);
char				*parse_string_arg(t_printf *tab, char *str, size_t str_len);
size_t				add_string_padding(size_t width, char c, char *str);

#endif
