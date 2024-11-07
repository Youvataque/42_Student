/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:47:03 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/07 17:36:19 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////
// delete all char contained in set from the start and the end of s1
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	new_size;
	char	*temp;
	char	*result;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	temp = (char *)&s1[i];
	new_size = len - i;
	i = 0;
	while (s1[len - 1 - i] && ft_strchr(set, s1[len - 1 - i]) != NULL)
		i++;
	new_size -= i;
	result = malloc(new_size * sizeof(char));
	i = 0;
	while (i < new_size)
	{
		result[i] = temp[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("coucou mes asticos", "cos"));
	return (0);
} */