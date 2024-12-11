/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monotone_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:37:04 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/11 21:36:04 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void extract_decroi(t_list **a, t_list **b)
{
	while (*a != NULL && (*a)->next != NULL)
	{
		if (*(int *)(*a)->content < *(int *)(*a)->next->content)
			break;
		pb(a, b);
	}
}

int search_good_inter(t_list *a, int target, int max, int *index)
{
	int val;
	int i;

	i = 0;
	val = max;
	while (a != NULL)
	{
		if (*(int *)a->content < val && *(int *)a->content > target)
		{
			val = *(int *)a->content;
			*index = i;
		}
		a = a->next;
		i++;
	}
	return val;
}

void put_in_headtail(int target, t_list **a, int index, int mode)
{
	int size = ft_lstsize(*a);

	if (mode)
	{
		while (*(int *)(*a)->content != target)
		{
			if (index < size / 2)
				ra(a);
			else
				rra(a);
		}
	}
	else
	{
		while (*(int *)ft_lstlast(*a)->content != target)
		{
			if (index < size / 2)
				ra(a);
			else
				rra(a);
		}
	}
}

void push_good_b(t_list **a, t_list **b)
{
	const int *min_maxval = min_max(*a);
	int index = 0;
	int third;

	if (*(int *)(*b)->content > min_maxval[1])
	{
		put_in_headtail(min_maxval[0], a, min_maxval[2], 1);
	}
	else if (*(int *)(*b)->content < min_maxval[0])
	{
		put_in_headtail(min_maxval[1], a, min_maxval[3], 0);
	}
	else
	{
		third = search_good_inter(*a, *(int *)(*b)->content, min_maxval[1], &index);
		put_in_headtail(third, a, index, 1);
	}
	pa(a, b);
}

void monotone_sort(t_list **a, t_list **b)
{
	int i;
	int b_range;

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
