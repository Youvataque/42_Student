/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:10:40 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 15:17:06 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

int	all_inb(t_list *a, double q1, double q2)
{
	while (a)
	{
		if (*(int *)a->content >= q1 && *(int *)a->content <= q2)
			return (1);
		a = a->next;
	}
	return (0);
}

void	push_b(t_quarts *quarts, t_list **a, t_list **b)
{
	int	val;

	while (all_inb(*a, quarts->q1, quarts->q2))
	{
		val = *(int *)(*a)->content;
		if (val <= quarts->med && val >= quarts->q1)
		{
			pb(a, b);
			if (ft_lstsize(*b) > 1)
				rb(b);
		}
		else if (val >= quarts->med && val <= quarts->q2)
			pb(a, b);
		else
			ra(a);
	}
	while (ft_lstsize(*a) > 3)
	{
		pb(a, b);
		if (*(int *)(*b)->content <= quarts->med)
			rb(b);
	}
}

void	quartile_sort(t_list **a, t_list **b)
{
	t_quarts	*quarts;

	quarts = malloc(sizeof(t_quarts));
	if (!quarts)
		return ;
	set_quartils(*a, quarts);
	push_b(quarts, a, b);
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
		push_good_b(a, b);
	while (!is_sorted(*a))
	{
		if (min_max(*a)[2] < ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);
	}
	free(quarts);
}
