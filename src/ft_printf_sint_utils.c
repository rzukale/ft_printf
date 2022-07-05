/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sint_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:13:26 by rzukale           #+#    #+#             */
/*   Updated: 2022/07/06 01:48:38 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_sint_sign_width(t_printf *tab, int *i, long long num)
{
	if (num >= 0 && (tab->blank_sign || tab->sign))
		(*i) += 1;
	if (tab->width > (*i))
	{
		tab->width -= (*i);
		if (tab->precision_flag && tab->zero_padding && tab->precision > 0)
			tab->zero_padding = 0;
	}
	else
		tab->width = 0;
	(*i) += tab->width;
}

void	get_sint_strlen(t_printf *tab, int *i, long long num, int neg)
{
	if ((num != 0 && tab->precision_flag && tab->precision <= ((*i) - neg))
		|| tab->precision < 0)
	{
		if (tab->precision > 0)
		{
			tab->precision = 0;
			tab->precision_flag = 0;
			tab->zero_padding = 0;
		}
		else
		{
			tab->precision = 0;
			tab->precision_flag = 0;
		}
	}
	if (tab->precision_flag && tab->precision > ((*i) - neg))
		tab->precision -= ((*i) - neg);
	else
	{
		tab->precision = 0;
		if ((*i) > 0)
			tab->precision_flag = 0;
	}
	(*i) += tab->precision;
	get_sint_sign_width(tab, i, num);
}

char	*ft_longlong_itoa_base(long long n, int base)
{
	char	*base_digits;
	char	*digit;
	char	*next_digit;
	char	*final_str;

	base_digits = "0123456789abcdef";
	digit = ft_strnew(3);
	if (base < 2 || base > 16 || !(digit))
		return (NULL);
	if ((n < 0 && n > (long long)(-base)) || (n >= 0 && n < (long long)base))
	{
		if (n < 0 && base == 10)
			digit[0] = '-';
		return (ft_strncat(digit, &base_digits[ft_abs(n % base)], 1));
	}
	digit[0] = base_digits[ft_abs((int)(n % base))];
	next_digit = ft_longlong_itoa_base(n / (long long)base, base);
	if (!next_digit)
	{
		free(digit);
		return (NULL);
	}
	final_str = ft_strjoin_freeable(next_digit, digit, 1, 1);
	return (final_str);
}
