/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:59:18 by yseguin           #+#    #+#             */
/*   Updated: 2025/01/15 16:14:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// for obtain the position of an element from a list
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

///////////////////////////////////////////////////////////////////////////////
// for know on wich middle of lst is the element pos
int	get_direction(int pos, t_list *lst)
{
	const int	index = get_index(lst, pos);

	if (index == -1)
		return (0);
	if (index <= ft_lstsize(lst) / 2)
		return (1);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
// get the second biggest int of a
int	get_second_max(t_list *a, int max)
{
	int	smax;

	smax = INT_MIN;
	while (a)
	{
		if (*(int *)a->content > smax && *(int *)a->content != max)
			smax = *(int *)a->content;
		a = a->next;
	}
	return (smax);
}

///////////////////////////////////////////////////////////////////////////////
// push all element in b for have 3 element in a
void	push_b_five(int dir, int pos, t_list **a, t_list **b)
{
	int	size;
	int	index;

	index = get_index(*a, pos);
	if (dir)
	{
		while (index != 0)
		{
			ra(a);
			index--;
		}
		pb(a, b);
	}
	else
	{
		size = ft_lstsize(*a);
		while (index != size)
		{
			rra(a);
			index++;
		}
		pb(a, b);
	}
	if (ft_lstsize(*b) == 2 && pos == min_max(*b)[1])
		sb(*b);
}

///////////////////////////////////////////////////////////////////////////////
// for sort 5 element array
void	five_sort(t_list **a, t_list **b)
{
	int	x;
	int	mp;
	int	smax_pos;
	int	md;

	x = 2;
	while (x > 0)
	{
		mp = min_max(*a)[1];
		smax_pos = get_second_max(*a, mp);
		md = get_direction(mp, *a);
		if (get_index(*a, smax_pos) < get_index(*a, mp) && x == 2 && md == 1)
			push_b_five(get_direction(smax_pos, *a), smax_pos, a, b);
		else
			push_b_five(md, mp, a, b);
		x--;
	}
	sort_three(a);
	x = 2;
	while (x > 0)
	{
		pa(a, b);
		ra(a);
		x--;
	}
}
