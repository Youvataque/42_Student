/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monotone_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:37:04 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 13:16:34 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	extract_decroi(t_list **a, t_list **b)
{
	while (*a != NULL && (*a)->next != NULL)
	{
		if (*(int *)(*a)->content < *(int *)(*a)->next->content)
			break ;
		pb(a, b);
	}
}

void	monotone_sort(t_list **a, t_list **b)
{
	int	i;
	int	b_range;

	i = 0;
	while (!is_sorted(*a))
	{
		extract_decroi(a, b);
		if (!is_sorted(*a))
			ra(a);
	}
	b_range = ft_lstsize(*b);
	while (i < b_range)
	{
		push_good_b(a, b);
		i++;
	}
	while (!is_sorted(*a))
	{
		if (min_max(*a)[2] < ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
}
