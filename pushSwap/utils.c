/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:29:38 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/21 17:26:11 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

#include <limits.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// Converts a string to an integer with overflow checks
int	ft_mini_atoi(const char *str, int *n)
{
	int		i;
	long	result;
	int		s;

	i = 0;
	result = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((s == 1 && result > INT_MAX) || (s == -1 && - result < INT_MIN))
			return (0);
		i++;
	}
	if (i > 0 && str[i] == '\0')
	{
		*n = (int)(result * s);
		return (1);
	}
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// Convert input string to value and store in lstcontent format
int	converted_val(char *n, void **result)
{
	int	*temp;

	temp = malloc(sizeof(int));
	if (!temp)
		return (0);
	if (ft_mini_atoi(n, temp))
	{
		*result = (void *)temp;
		return (1);
	}
	free(temp);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// check if the list alredy contain the next->content
int	ft_lstcontain(t_list *lst, void *content)
{
	while (lst != NULL)
	{
		if (*(int *)(lst->content) == *(int *)content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	end_word_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ')
		i++;
	return (i);
}
