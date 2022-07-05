/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzukale <rzukale@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:36:55 by rzukale           #+#    #+#             */
/*   Updated: 2022/06/18 18:04:17 by rzukale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_abs(int x);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
size_t	ft_int_length(int n);
char	*ft_strncat(char *dest, const char *src, size_t count);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_strdel(char **as);
void	ft_putnbr(int n);
int		ft_isspace(int c);
char	*ft_itoa_base(unsigned long num, int base, int upcase);
char	*ft_strjoin_freeable(char *s1, char *s2, int one, int two);

#endif
