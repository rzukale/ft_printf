/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:46:58 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/18 16:33:31 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		i;
	int			sign;
	char		*tmp;

	i = ft_int_length(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		tmp[0] = '-';
	}
	tmp[i] = '\0';
	i--;
	if (n == 0)
		tmp[i] = '0';
	while (n)
	{
		tmp[i] = '0' + n % 10 * sign;
		i--;
		n /= 10;
	}
	return (tmp);
}
