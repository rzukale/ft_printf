/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:45:43 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:33:22 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	count_null_string_len(t_printf *tab, int *i)
{
	if (tab->precision_flag)
	{
		if (tab->precision <= 6)
			(*i) = tab->precision;
	}	
	if (tab->width > (*i))
		tab->width -= (*i);
	else
		tab->width = 0;
	if (tab->precision < 0)
	{
		(*i) = 6;
		tab->precision = 0;
		tab->width = 0;
	}
}

void	count_string_len(t_printf *tab, int *i, char **str)
{
	while ((*str)[*i] && (!tab->precision_flag || (*i) < tab->precision))
		(*i)++;
	if (tab->width > (*i))
		tab->width -= (*i);
	else
		tab->width = 0;
}

int	parse_string(va_list *ap, t_printf *tab)
{
	int		i;
	char	*tmp_str;
	char	*str;

	i = 0;
	str = va_arg(*ap, char *);
	if (!str)
	{
		i = 6;
		count_null_string_len(tab, &i);
		tmp_str = parse_string_arg(tab, "(null)", i);
	}
	else
	{
		count_string_len(tab, &i, &str);
		tmp_str = parse_string_arg(tab, str, i);
	}
	if (!tmp_str)
		return (-1);
	write_len(tmp_str, i + tab->width);
	ft_strdel(&tmp_str);
	return (i + tab->width);
}
