/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:44:10 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:32:27 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

unsigned long long	get_unsigned_int_conversion(va_list *ap, t_printf *tab)
{
	unsigned long long	ret;

	if (tab->conversion[0] == 'h' && tab->conversion[1] == 'h')
		ret = (unsigned char)va_arg(*ap, unsigned int);
	else if (tab->conversion[0] == 'h')
		ret = (unsigned short int)va_arg(*ap, unsigned int);
	else if (tab->conversion[0] == 'l' && tab->conversion[1] == 'l')
		ret = va_arg(*ap, unsigned long long);
	else if (tab->conversion[0] == 'l')
		ret = va_arg(*ap, unsigned long);
	else
		ret = (unsigned long long)va_arg(*ap, unsigned int);
	return (ret);
}

char	*get_unsigned_string_conversion(va_list *ap,
	t_printf *tab, unsigned long long *num)
{
	char	*num_string;
	int		base;
	int		up;

	up = 0;
	base = get_base(tab->c, &up);
	*num = get_unsigned_int_conversion(ap, tab);
	num_string = ft_itoa_base(*num, base, up);
	if (!num_string)
		return (NULL);
	return (num_string);
}

int	parse_unsigned_int(va_list *ap, t_printf *tab)
{
	unsigned long long	num;
	char				*num_str;
	char				*str;
	int					i;

	i = 0;
	num_str = get_unsigned_string_conversion(ap, tab, &num);
	if (!num_str)
		return (-1);
	if (num == 0 && (tab->precision_flag && tab->precision == 0))
		tab->is_zero = 1;
	else
		i = ft_strlen(num_str);
	get_uint_str_len(tab, &i, num);
	str = parse_integer_argument(tab, num_str, i, 0);
	if (!str)
		return (-1);
	write_len(str, i);
	ft_strdel(&str);
	ft_strdel(&num_str);
	return (i);
}
