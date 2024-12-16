/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:59:18 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 13:18:08 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// search the better inter for place target into a
int	search_inter(t_list *a, int target, int max, int *index)
{
	int	val;
	int	i;

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
	return (val);
}

///////////////////////////////////////////////////////////////////////////////
// change a order before place first element of b
void	put_in_headtail(int target, t_list **a, int index, int mode)
{
	int	size;

	size = ft_lstsize(*a);
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

///////////////////////////////////////////////////////////////////////////////
// pb the first element of b a the good place in a
void	push_good_b(t_list **a, t_list **b)
{
	const int	*min_maxval = min_max(*a);
	int			index;
	int			third;

	index = 0;
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
		third = search_inter(*a, *(int *)(*b)->content, min_maxval[1], &index);
		put_in_headtail(third, a, index, 1);
	}
	pa(a, b);
}

///////////////////////////////////////////////////////////////////////////////
// sort liste of three element
void	sort_three(t_list **a)
{
	int	first;
	int	mid;
	int	last;

	if (ft_lstsize(*a) != 3 || is_sorted(*a))
		return ;
	first = *(int *)(*a)->content;
	mid = *(int *)(*a)->next->content;
	last = *(int *)ft_lstlast(*a)->content;
	if (first < mid && last < first)
		rra(a);
	else if (first < mid)
		return (rra(a), sa(*a), (void)0);
	else if (first > mid && last > first)
		sa(*a);
	else if (first > mid && mid > last)
		return (sa(*a), rra(a), (void)0);
	else if (first > mid && last < first)
		ra(a);
}
