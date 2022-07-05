/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:51:56 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:31:07 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	parse_argument(va_list *ap, t_printf *tab, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = parse_char(ap, tab);
	else if (c == 's')
		i = parse_string(ap, tab);
	else if (c == 'p')
		i = parse_pointer(ap, tab);
	else if (c == 'd' || c == 'i')
		i = parse_signed_int(ap, tab);
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		i = parse_unsigned_int(ap, tab);
	else if (c == 'f')
		i = parse_float(ap, tab);
	else if (c == '%')
		i = parse_percent(tab);
	else
		i = -1;
	return (i);
}

int	get_flags_and_converted_arg(const char *format, va_list *ap, int *i)
{
	int			ret;
	t_printf	tab;

	ft_memset(&tab, 0, sizeof(t_printf));
	*i += determine_flags(&format[*i], &tab);
	if (format[*i] && (ft_isdigit(format[*i]) || format[*i] == '*'))
		*i += get_width(&tab, ap, &format[*i]);
	if (format[*i] && format[*i] == '.')
		*i += get_precision(&format[*i], ap, &tab);
	if (format[*i] && (format[*i] == 'h'
			|| format[*i] == 'l' || format[*i] == 'L'))
		*i += get_length_modifiers(&format[*i], &tab);
	tab.c = format[*i];
	parse_all_modifiers(&tab);
	if (!format[*i] || !valid_conversion_marker(format[*i]))
		return (0);
	ret = parse_argument(ap, &tab, format[*i]);
	(*i)++;
	return (ret);
}

void	ft_printf_write_output(char *str, int *i, int *printed)
{
	write_string(&str[(*i)]);
	*printed += ft_strlen(&str[(*i)]);
	*i += ft_strlen(&str[(*i)]);
}

int	ft_printf_internals(const char *format, va_list *ap)
{
	int		i;
	int		printed;
	int		jump_length;
	int		ret;

	i = 0;
	jump_length = 0;
	printed = 0;
	while (format[i])
	{
		jump_length = count_jump_length((char *)&format[i]);
		if (jump_length > -1)
		{
			ft_putnstr((char *)&format[i], jump_length, &printed);
			i += jump_length + 1;
			ret = get_flags_and_converted_arg((char *)format, ap, &i);
			if (ret == -1)
				return (ret);
			printed += ret;
		}
		else
			ft_printf_write_output((char *)format, &i, &printed);
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_printf_internals(format, &ap);
	va_end(ap);
	return (ret);
}
