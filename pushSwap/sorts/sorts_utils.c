/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:45 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/21 21:58:11 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// check if lst is sorted or not 
int	is_sorted(t_list *lst)
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
	int	val;

	result = malloc(sizeof(int) * 2);
	if (!result)
		return (NULL);
	result[0] = INT32_MAX;
	result[1] = INT32_MIN;
	while (lst)
	{
		val = *(int *)lst->content;
		if (val < result[0])
			result[0] = val;
		if (val > result[1])
			result[1] = val;
		lst = lst->next;
	}
	return (result);
}

///////////////////////////////////////////////////////////////////////////////
// set tab from lst values
int	*set_tab_from_lst(t_list *a, int *len)
{
	int		i;
	t_list	*origin;
	int		*tab;

	origin = a;
	i = 0;
	while (a)
	{
		(*len)++;
		a = a->next;
	}
	a = origin;
	tab = malloc(sizeof(int) * *len);
	while (a)
	{
		tab[i] = *(int *)a->content;
		a = a->next;
		i++;
	}
	quick_sort(tab, 0, *len - 1);
	return (tab);
}

///////////////////////////////////////////////////////////////////////////////
// calculate all median for obtain the index of q1 med and q2
double	calculate_median(int array[], int start, int end)
{
	int	size;
	int	mid;
	int	mid1;
	int	mid2;

	size = end - start + 1;
	if (size % 2 == 0)
	{
		mid1 = start + (size / 2) - 1;
		mid2 = start + (size / 2);
		return ((array[mid1] + array[mid2]) / 2.0);
	}
	else
	{
		mid = start + (size / 2);
		return (array[mid]);
	}
}

///////////////////////////////////////////////////////////////////////////////
// set q1 med and q2 from a sorted liste (array format)
void	set_quartils(t_list *a, t_quarts *quarts)
{
	int	size;
	int	*array;

	size = 0;
	array = set_tab_from_lst(a, &size);
	quarts->med = calculate_median(array, 0, size - 1);
	if (size % 2 == 0)
	{
		quarts->q1 = calculate_median(array, 0, (size / 2) - 1);
		quarts->q2 = calculate_median(array, size / 2, size - 1);
	}
	else
	{
		quarts->q1 = calculate_median(array, 0, (size / 2) - 1);
		quarts->q2 = calculate_median(array, (size / 2) + 1, size - 1);
	}
	free(array);
}
