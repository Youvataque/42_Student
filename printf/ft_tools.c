/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:26:35 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 11:29:00 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/////////////////////////////////////////////////////////////////////////////
// count nomber of required char for print int
int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/////////////////////////////////////////////////////////////////////////////
// count nomber of required char for print unsigned long
int	ft_count_digits_plus(unsigned long n)
{
	unsigned long	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

/////////////////////////////////////////////////////////////////////////////
// convert unsigned long into hex str 
char	*ft_itoa_plus(unsigned long n)
{
	char			*result;
	unsigned long	len;
	const char		*base = "0123456789abcdef";

	len = ft_count_digits_plus(n);
	result = malloc(sizeof(char) * (len + 3));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		return (result[0] = '0', result);
	while (n != 0)
	{
		result[--len] = base[(n % 16)];
		n /= 16;
	}
	return (result);
}
