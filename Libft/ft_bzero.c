/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:14:29 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:55:21 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Sets a block of memory to zero
void	ft_bzero(void *s, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (len--)
	{
		*p++ = 0;
	}
}
