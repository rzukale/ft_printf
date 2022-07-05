/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:21:48 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:31:54 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_jump_length(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '%')
				return (i);
			i++;
		}
	}
	return (-1);
}

void	ft_putnstr(char *str, int len, int *printed)
{
	*printed += len;
	write(1, str, len);
}

int	write_string(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

void	parse_all_modifiers_two(t_printf *tab)
{
	if (tab->blank_sign && tab->c != 'd' && tab->c != 'i'
		&& tab->c != 'f' && tab->c != 'F')
		tab->blank_sign = 0;
	if (tab->sign && tab->c != 'd' && tab->c != 'i'
		&& tab->c != 'f' && tab->c != 'F')
		tab->sign = 0;
	if (tab->hash_sign && (tab->c == 'c' || tab->c == 'd' || tab->c == 'i'
			|| tab->c == 'n' || tab->c == 'p' || tab->c == 's'
			|| tab->c == 'u'))
		tab->hash_sign = 0;
	if (tab->zero_padding && tab->precision_flag && (tab->c == 'd'
			|| tab->c == 'i' || tab->c == 'o' || tab->c == 'u'
			|| tab->c == 'x' || tab->c == 'X'))
		tab->zero_padding = 0;
	if (tab->c == 'p' && tab->zero_padding && !tab->precision_flag)
		tab->left_justify = 1;
}

void	parse_all_modifiers(t_printf *tab)
{
	if (tab->left_justify && tab->zero_padding)
		tab->zero_padding = 0;
	if (tab->width < 0)
	{
		tab->width *= -1;
		tab->left_justify = 1;
	}
	if (tab->sign && tab->blank_sign)
	{
		tab->blank_sign = 0;
	}
	if (tab->width < 0)
	{
		tab->left_justify = 1;
		tab->width *= -1;
	}
	if (tab->precision_flag && tab->precision < 0)
	{
		tab->precision = 0;
		tab->precision_flag = 0;
	}
	parse_all_modifiers_two(tab);
}
