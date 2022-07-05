/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:20:09 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:36:56 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	determine_flags(const char *format, t_printf *tab)
{
	int	i;

	i = 0;
	while (format[i] && (format[i] == '-' || format[i] == '+'
			|| format[i] == ' ' || format[i] == '#' || format[i] == '0'))
	{
		if (format[i] == '-')
			tab->left_justify = 1;
		else if (format[i] == '+')
			tab->sign = 1;
		else if (format[i] == ' ')
			tab->blank_sign = 1;
		else if (format[i] == '#')
			tab->hash_sign = 1;
		else if (format[i] == '0')
			tab->zero_padding = 1;
		i++;
	}
	return (i);
}

int	get_width(t_printf *tab, va_list *ap, const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '*')
	{
		tab->width = va_arg(*ap, int);
		i++;
	}
	else
	{
		tab->width = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	if (i != 0 && format[i] && ft_isdigit(format[i]))
	{
		tab->width = ft_atoi(&format[i]);
		i++;
	}
	return (i);
}

int	get_precision(const char *format, va_list *ap, t_printf *tab)
{
	int	i;

	i = 1;
	tab->precision_flag = 1;
	if (format[i] == '*')
	{
		tab->precision = va_arg(*ap, int);
		tab->num_conversion_prec = 1;
		i++;
	}
	else if (ft_isdigit(format[i]))
	{
		tab->precision = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	else
	{
		tab->precision = 0;
	}
	return (i);
}

int	get_length_modifiers(const char *format, t_printf *tab)
{
	int	i;

	i = 0;
	if (format[i] == 'h' || format[i] == 'l')
	{
		tab->conversion[i] = format[i];
		if (format[i + 1] && format[i + 1] == format[i])
		{
			i++;
			tab->conversion[i] = format[i];
		}
	}
	else
	{
		tab->conversion[i] = format[i];
	}
	i++;
	return (i);
}

int	valid_conversion_marker(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'o' || c == 'x' || c == 'X'
		|| c == 'f' || c == '%')
		return (1);
	return (0);
}
