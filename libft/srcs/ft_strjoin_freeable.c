/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_freeable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:00:46 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/19 02:45:28 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_freeable(char *s1, char *s2, int one, int two)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i++] = s2[j];
	dest[i] = '\0';
	if (one)
		ft_strdel(&s1);
	if (two)
		ft_strdel(&s2);
	return (dest);
}
