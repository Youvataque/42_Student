/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:27:29 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:40:08 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/////////////////////////////////////////////////////////////////////////////
// Finds the first occurrence of a substring within a string up to a specified length.
char	*is_in(const char *haystack, const char *needle, size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (needle[j] && haystack[i] && i < len)
	{
		if (haystack[i] != needle[j])
			return (NULL);
		j++;
		i++;
	}
	return ((char *)&haystack[i - j]);
}

/////////////////////////////////////////////////////////////////////////////
// Finds the first occurrence of needle in haystack within len characters.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = NULL;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			result = is_in(haystack, needle, i, len);
			if (result != NULL)
				return (result);
		}
		i++;
	}
	return (result);
}
