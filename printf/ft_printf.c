/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:52:36 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/12 21:15:11 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "libft/libft.h"

void	selector(const char **str, va_list args)
{
	if (**str == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1), (*str)++, (void)0);
	else if (**str == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1), (*str)++, (void)0);
	else if (**str == 'p')
	{}
	else if (**str == 'd')
		return (ft_putnbr_fd((int)va_arg(args, int), 1), (*str)++, (void)0);
	else if (**str == 'i')
		return (ft_putnbr_fd((int)va_arg(args, int), 1), (*str)++, (void)0);
	else if (**str == 'u')
	{}
	else if (**str == 'x')
	{}
	else if (**str == 'X')
	{}
	else if (**str == '%')
		return (ft_putchar_fd('%', 1), (*str)++, (void)0);
}

int ft_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    while (*str)
	{
		if (*str == '%')
		{
			str++;
			selector(&str, args);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
    va_end(args);
    return (0);
}

int main()
{
    ft_printf("test str : %s puis int : %d", "voyons", 12);
    return (0);
}