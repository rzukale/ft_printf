/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:05:04 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:32:55 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_base(char c, int *up)
{
	int	base;

	if (c == 'u')
		base = 10;
	else if (c == 'o')
		base = 8;
	else if (c == 'x')
		base = 16;
	else
	{
		(*up) = 1;
		base = 16;
	}
	return (base);
}

void	get_uint_str_lentwo(t_printf *tab, int *i)
{
	if (tab->blank_sign || tab->sign)
		(*i) += 1;
	if (tab->width > (*i))
		tab->width -= (*i);
	else
		tab->width = 0;
	(*i) += tab->width;
}

void	get_uint_str_len(t_printf *tab, int *i, unsigned long long num)
{
	if ((!tab->is_zero && tab->precision_flag
			&& ((tab->precision <= (*i)) || tab->precision < 0)))
	{
		tab->precision = 0;
		tab->precision_flag = 0;
		tab->zero_padding = 0;
	}
	if (tab->precision_flag)
		tab->zero_padding = 0;
	if (tab->precision > (*i))
		tab->precision -= (*i);
	else
		tab->precision = 0;
	if (tab->c == 'o' && tab->hash_sign && tab->precision == 0
		&& (num != 0 || (tab->precision_flag && tab->precision == 0)))
		tab->precision++;
	(*i) += tab->precision;
	if ((tab->c == 'x' || tab->c == 'X') && num > 0 && tab->hash_sign)
		(*i) += 2;
	else
		tab->is_zero = 1;
	get_uint_str_lentwo(tab, i);
}
