/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:53:33 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/18 16:31:14 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)str;
	while (dest < (unsigned char *)str + n)
		*(dest++) = (unsigned char)c;
	return (str);
}
