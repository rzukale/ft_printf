/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 16:19:39 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:34:51 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long long	get_signed_int_conversion(va_list *ap, t_printf *tab)
{
	long long	ret;

	if (tab->conversion[0] == 'h' && tab->conversion[1] == 'h')
		ret = (signed char)va_arg(*ap, int);
	else if (tab->conversion[0] == 'h')
		ret = (short int)va_arg(*ap, int);
	else if (tab->conversion[0] == 'l' && tab->conversion[1] == 'l')
		ret = va_arg(*ap, long long);
	else if (tab->conversion[0] == 'l')
		ret = va_arg(*ap, long);
	else
		ret = va_arg(*ap, int);
	return (ret);
}

int	add_integer_prefix(t_printf *tab, char *str, int is_negative)
{
	int	i;

	i = 0;
	if (is_negative)
		str[i++] = '-';
	else if (tab->blank_sign || tab->sign)
	{
		if (tab->blank_sign)
			str[i++] = ' ';
		else
			str[i++] = '+';
	}
	else if (tab->c == 'x' && tab->hash_sign && !tab->is_zero)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	else if (tab->c == 'X' && tab->hash_sign && !tab->is_zero)
	{
		str[i++] = '0';
		str[i++] = 'X';
	}
	return (i);
}

char	*parse_integer_argument(t_printf *tab, char *str,
		size_t str_len, int is_negative)
{
	char	*tmp;
	size_t	i;

	tmp = ft_strnew(str_len);
	if (!tmp)
		return (NULL);
	i = 0;
	if ((tab->width > 0 && !tab->left_justify && !tab->zero_padding))
		i += add_string_padding(tab->width, ' ', &tmp[i]);
	i += add_integer_prefix(tab, &tmp[i], is_negative);
	if (tab->width > 0 && tab->zero_padding && !tab->left_justify)
		i += add_string_padding(tab->width, '0', &tmp[i]);
	if (tab->precision > 0)
		i += add_string_padding(tab->precision, '0', &tmp[i]);
	if (!(tab->precision_flag && tab->precision == 0))
		i += add_number_to_string(&tmp[i], str);
	if (tab->width > 0 && tab->left_justify)
		i += add_string_padding(tab->width, ' ', &tmp[i]);
	tmp[i] = '\0';
	return (tmp);
}

void	get_initial_values(t_printf *tab, int *i, char **num_str, long long num)
{
	if (num == 0 && (tab->precision_flag && tab->precision == 0))
		(*i) = 0;
	else
		(*i) = ft_strlen(*num_str);
}

int	parse_signed_int(va_list *ap, t_printf *tab)
{
	long long	num;
	char		*num_str;
	char		*str;
	int			i;
	int			neg;

	num = get_signed_int_conversion(ap, tab);
	num_str = ft_longlong_itoa_base(num, 10);
	if (!num_str)
		return (-1);
	if (num < 0)
		neg = 1;
	else
		neg = 0;
	get_initial_values(tab, &i, &num_str, num);
	get_sint_strlen(tab, &i, num, neg);
	str = parse_integer_argument(tab, num_str, i, neg);
	if (!str)
		return (-1);
	write_len(str, i);
	ft_strdel(&str);
	ft_strdel(&num_str);
	return (i);
}
