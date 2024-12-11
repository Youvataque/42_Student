/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:29:38 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/11 21:05:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// Converts a string to an integer with lower rules
int	ft_mini_atoi(const char *str, int *n)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] <= 57 && str[i] >= 48) && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[i - 1] <= 57 && str[i - 1] >= 48)
	{
		*n = result * sign;
		return (1);
	}
	else
		return (0);
}

///////////////////////////////////////////////////////////////////////////////
// convert in val into pointer for lstcontent format
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

///////////////////////////////////////////////////////////////////////////////
// check if lst is sorted or not 
int is_sorted(t_list *lst)
{
	if (ft_lstsize(lst) == 1)
		return (1);
	while (lst && lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
// return tab that contain min and max of lst
int	*min_max(t_list *lst)
{
	int	*result;
	int	index;

	index = 0;
	result = malloc(sizeof(int) * 4);
	result[0] = INT32_MAX;
	result[1] = INT32_MIN;
	result[2] = 0;
	result[3] = 0;
	while (lst)
	{
		if (*(int *)lst->content < result[0])
		{
			result[0] = *(int *)lst->content;
			result[2] = index;
		}
		if (*(int *)lst->content > result[1])
		{
			result[1] = *(int *)lst->content;
			result[3] = index;
		}
		lst = lst->next;
		index++;
	}
	return (result);
}
