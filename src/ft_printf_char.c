/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:01:39 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:39:17 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	add_string_padding(size_t width, char c, char *str)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		str[i] = c;
		i++;
	}
	return (i);
}

char	*parse_string_arg(t_printf *tab, char *str, size_t str_len)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	tmp = ft_strnew(str_len + tab->width);
	if (!tmp)
		return (NULL);
	i = 0;
	if (tab->width > 0 && !tab->zero_padding && !tab->left_justify)
		i += add_string_padding(tab->width, ' ', &tmp[i]);
	else if (tab->width > 0 && tab->zero_padding && !tab->left_justify)
		i += add_string_padding(tab->width, '0', &tmp[i]);
	j = 0;
	while (j < str_len)
		tmp[i++] = str[j++];
	if (tab->width > 0 && tab->left_justify && tab->zero_padding)
		i += add_string_padding(tab->width, '0', &tmp[i]);
	else if (tab->width > 0 && tab->left_justify && !tab->zero_padding)
		i += add_string_padding(tab->width, ' ', &tmp[i]);
	tmp[i] = '\0';
	return (tmp);
}

void	write_len(char *str, int len)
{
	write(1, str, len);
}

int	parse_char(va_list *ap, t_printf *tab)
{
	char	c;
	char	*str;

	c = va_arg(*ap, int);
	if (tab->width > 1)
		tab->width--;
	else
		tab->width = 0;
	if (tab->left_justify)
		tab->zero_padding = 0;
	str = parse_string_arg(tab, &c, 1);
	if (!str)
		return (-1);
	write_len(str, tab->width + 1);
	ft_strdel(&str);
	return (tab->width + 1);
}
