/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 01:06:14 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/20 01:38:28 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	check_sign(long double *num, int *neg, int *i)
{
	if ((1 / (*num)) < 0)
	{
		(*i) += 1;
		(*neg) = 1;
	}
}

int	count_digits(long long nbr)
{
	int	digits;

	digits = 1;
	while (nbr / 10)
	{
		nbr = nbr / 10;
		digits++;
	}
	return (digits);
}

char	*get_whole_part(long long num)
{
	char	*str;
	int		i;

	i = count_digits(num);
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	while (num >= 10)
	{	
		str[i - 1] = '0' + (num % 10);
		num = num / 10;
		i--;
	}
	str[i - 1] = '0' + num;
	return (str);
}

void	round_up(char **str, int i, int past_precision, int *add_space)
{
	if ((*str)[i] == '.')
		round_up(str, i - 1, 1, add_space);
	else if ((*str)[i] + 1 <= '9')
		(*str)[i] += 1;
	else if ((*str)[i] == '9')
	{
		(*str)[i] = '0';
		if (i == 0)
		{
			*add_space = 1;
			return ;
		}
		round_up(str, i - 1, past_precision, add_space);
	}
}

long double	get_fraction(long double num, char **str, int precision)
{
	int		i;

	*str = ft_strnew(precision + 1);
	if (!*str)
		return (0);
	i = 0;
	num = num - (long double)(long long)num;
	if (precision > 0)
	{
		(*str)[i] = '.';
		i++;
	}
	while (precision > 0)
	{
		num *= (long double) 10.0;
		(*str)[i++] = ((long long)num % 10) + '0';
		num = num - (long long)num;
		precision--;
	}
	return (num);
}
