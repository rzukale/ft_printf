/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 22:30:47 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:36:08 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	parse_percent(t_printf *tab)
{
	char	c;
	char	*str;

	c = '%';
	if (tab->width > 1)
		tab->width--;
	else
		tab->width = 0;
	tab->precision_flag = 0;
	tab->precision = 0;
	if (tab->left_justify)
		tab->zero_padding = 0;
	str = parse_string_arg(tab, &c, 1);
	if (!str)
		return (-1);
	write_len(str, tab->width + 1);
	ft_strdel(&str);
	return (tab->width + 1);
}
