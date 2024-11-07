/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:50:24 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:55:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Allocates memory for an array and initializes it to zero
void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)result)[i] = 0;
		i++;
	}
	return ((void *)result);
}
