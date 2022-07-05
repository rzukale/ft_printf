/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:18:22 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:35:55 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	configure_nullptr_len(t_printf *tab, int *ret)
{
	(*ret) = 3;
	if (tab->width > (*ret))
		tab->width -= (*ret);
	else
		tab->width = 0;
	if (tab->precision_flag && tab->precision == 0 && !tab->width)
		(*ret)--;
	if (tab->precision_flag && tab->precision > 0)
	{
		tab->precision--;
		tab->left_justify = 1;
		tab->zero_padding = 1;
		tab->width = tab->precision;
	}
	if (tab->precision_flag && tab->precision == 0 && tab->zero_padding)
	{
		if (tab->width > 0)
		{
			tab->width++;
			(*ret)--;
		}
		tab->zero_padding = 0;
	}
}

int	configure_ptr_len(t_printf *tab, int len)
{
	int	ret;

	ret = len;
	tab->hash_sign = 1;
	if (tab->precision_flag && tab->precision > (ret - 2))
		tab->precision -= (ret - 2);
	else
	{
		tab->precision_flag = 0;
		tab->precision = 0;
	}
	ret += tab->precision;
	if (ret < tab->width)
		tab->width -= ret;
	else
		tab->width = 0;
	ret += tab->width;
	return (ret);
}

int	add_pointer_prefix(t_printf *tab, char *str, char *prefix)
{
	size_t	i;

	i = 0;
	if (tab->hash_sign && !(tab->precision_flag && tab->precision == 0))
	{
		str[i] = prefix[i];
		i++;
		str[i] = prefix[i];
		i++;
	}
	return (i);
}
