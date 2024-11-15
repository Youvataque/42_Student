/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:30:49 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/15 11:47:53 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/////////////////////////////////////////////////////////////////////////////
// convert a pointer into an str with format -> 0x...
int	ft_put_add(void	*pointer, int fd)
{
	char			*temp;
	unsigned long	i;

	temp = ft_itoa_plus((unsigned long)pointer, "0123456789abcdef");
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	i = 0;
	while (temp[i])
	{
		ft_putchar_fd(temp[i], fd);
		i++;
	}
	free(temp);
	return (i + 2);
}
