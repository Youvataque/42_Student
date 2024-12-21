/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:46:05 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 17:31:10 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// sort list of two element
void	sort_two(t_list *a)
{
	if (*(int *)a->content > *(int *)a->next->content)
		sa(a);
}

///////////////////////////////////////////////////////////////////////////////
// sort list of three element
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
