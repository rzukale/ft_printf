/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:38:21 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/18 16:31:43 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long num, int base, int upcase)
{
	char	*tmp;
	char	*base_str;
	char	*digit;
	char	*next_digit;

	if (upcase)
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	digit = ft_strnew(2);
	if (!digit || base < 2 || base > 16)
		return (NULL);
	if (num < (unsigned long)base)
		return (ft_strncat(digit, &base_str[num % base], 1));
	digit[0] = base_str[num % base];
	next_digit = ft_itoa_base(num / base, base, upcase);
	if (!next_digit)
	{
		ft_strdel(&digit);
		return (NULL);
	}
	tmp = ft_strjoin(next_digit, digit);
	ft_strdel(&digit);
	ft_strdel(&next_digit);
	return (tmp);
}
