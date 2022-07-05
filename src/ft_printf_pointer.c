/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:12:56 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:35:28 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	add_number_to_string(char *dest, char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
	{
		str++;
	}
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	return (i);
}

char	*parse_pointer_arg(t_printf *tab, char *str,
		size_t str_len, char *prefix)
{
	char	*tmp;
	size_t	i;

	tmp = ft_strnew(str_len);
	if (!tmp)
		return (NULL);
	i = 0;
	if (tab->width > 0 && !tab->left_justify && !tab->zero_padding)
		i += add_string_padding(tab->width, ' ', &tmp[i]);
	i += add_pointer_prefix(tab, &tmp[i], prefix);
	if (tab->width > 0 && !tab->left_justify && tab->zero_padding)
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

char	*parse_pointer_str(t_printf *tab, int *ret, unsigned long ptr)
{
	char	*num;
	char	*str;

	num = ft_itoa_base(ptr, 16, 0);
	if (!num)
		return (NULL);
	*ret = ft_strlen(num) + 2;
	*ret = configure_ptr_len(tab, *ret);
	str = parse_pointer_arg(tab, num, *ret, "0x");
	ft_strdel(&num);
	return (str);
}

int	parse_pointer(va_list *ap, t_printf *tab)
{
	unsigned long	ptr;
	char			*str;
	int				ret;

	ret = 0;
	ptr = (unsigned long)va_arg(*ap, void *);
	if (ptr == 0)
	{
		configure_nullptr_len(tab, &ret);
		str = parse_string_arg(tab, "0x0", ret);
		ret += tab->width;
	}
	else
		str = parse_pointer_str(tab, &ret, ptr);
	if (!str)
		return (-1);
	write_len(str, ret);
	ft_strdel(&str);
	return (ret);
}
