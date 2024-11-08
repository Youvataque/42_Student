/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:48:16 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/08 12:14:34 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// Extracts a substring from a string starting at a given index to len.
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len <= ft_strlen(s))
		result = (char *)malloc((len + 1) * sizeof(char));
	else
		result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include "stdio.h"

int main()
{
	printf("%s", ft_substr("coucou vous", 7, 4));
	return 0;
} */