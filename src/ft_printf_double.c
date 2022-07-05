/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:23:20 by rzukale           #+#    #+#             */
/*   Updated: 2022/07/06 01:44:26 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_ftoa(long double num, int precision, int is_negative)
{
	char		*whole;
	char		*frac;
	char		*str;
	long double	offset;
	int			space;

	if (is_negative)
		num = -num;
	whole = get_whole_part((long long)num);
	offset = get_fraction(num, &frac, precision);
	if (!whole || !frac)
		return (NULL);
	str = ft_strjoin_freeable(whole, frac, 1, 1);
	space = 0;
	if (offset > 0.5 || (offset == 0.5 && (str[ft_strlen(str) - 1] - '0') % 2 == 1))
		round_up(&str, ft_strlen(str) - 1, 0, &space);
	if (space)
		str = ft_strjoin_freeable("1", str, 0, 1);
	if (is_negative)
		str = ft_strjoin_freeable("-", str, 0, 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*parse_double_argument(t_printf *tab, char *str,
	size_t str_len, int is_negative)
{
	char	*ret;
	int		i;

	ret = ft_strnew(str_len);
	if (!ret)
		return (NULL);
	i = 0;
	if (tab->width > 0 && !tab->left_justify && !tab->zero_padding)
		i += add_string_padding(tab->width, ' ', &ret[i]);
	i += add_integer_prefix(tab, &ret[i], is_negative);
	if (tab->width > 0 && !tab->left_justify && tab->zero_padding)
		i += add_string_padding(tab->width, '0', &ret[i]);
	i += add_number_to_string(&ret[i], str);
	if (tab->hash_sign && tab->precision == 0)
		ret[i++] = '.';
	if (tab->width > 0 && tab->left_justify)
		i += add_string_padding(tab->width, ' ', &ret[i]);
	ret[i] = '\0';
	return (ret);
}

void	get_double_len_modifiers(t_printf *tab, int *i, int is_negative)
{
	if (tab->hash_sign && tab->precision == 0)
		(*i)++;
	if (tab->blank_sign || tab->sign)
	{
		if (is_negative)
		{
			tab->blank_sign = 0;
			tab->sign = 0;
		}
		else
			(*i) += 1;
	}
	if (tab->width > (*i))
		tab->width -= (*i);
	else
		tab->width = 0;
	(*i) += tab->width;
}

long double	get_double_va_arg(t_printf *tab, va_list *ap)
{
	long double	num;

	num = 0;
	if (tab->conversion[0] == 'l' || tab->conversion[0] == 0)
		num = (double)va_arg(*ap, double);
	else
		num = (long double)va_arg(*ap, long double);
	if (!tab->precision_flag)
		tab->precision = 6;
	return (num);
}

int	parse_float(va_list *ap, t_printf *tab)
{
	char		*tmp;
	char		*str;
	long double	num;
	int			i;
	int			neg;

	neg = 0;
	i = 0;
	num = get_double_va_arg(tab, ap);
	check_sign(&num, &neg, &i);
	tmp = ft_ftoa(num, tab->precision, neg);
	if (!tmp)
		return (-1);
	i = ft_strlen(tmp);
	get_double_len_modifiers(tab, &i, neg);
	str = parse_double_argument(tab, tmp, i, neg);
	if (!str)
		return (-1);
	write_len(str, i);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (i);
}
