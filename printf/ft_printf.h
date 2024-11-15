/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:57:52 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 10:29:27 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdlib.h>

char	*ft_itoa_plus(unsigned long n);
int		ft_printf(const char *str, ...);
int		ft_count_digits(int n);
int		ft_put_add(void	*pointer, int fd);
int		ft_putstr_fd_count(char *s, int fd);

#endif