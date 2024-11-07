/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:38:09 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:51:24 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// move memory area
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;
	size_t				i;

	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	i = 0;
	if (temp_dst < temp_src && len != 0)
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	else if (temp_dst > temp_src && len != 0)
	{
		while (i < len)
		{
			temp_dst[len - 1 - i] = temp_src[len - 1 - i];
			i++;
		}
	}
	return (dst);
}
