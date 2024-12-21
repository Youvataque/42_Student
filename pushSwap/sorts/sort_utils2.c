/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:59:18 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/18 20:34:25 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	get_index(t_list *lst, int target)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (*(int *)lst->content == target)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

int get_direction(int pos, t_list *lst)
{
	int index = get_index(lst, pos);
	if (index == -1)
		return (0);
	if (index < ft_lstsize(lst) / 2)
		return (1);
	return (0);
}
