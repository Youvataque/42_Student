/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_operand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:20:35 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/21 19:03:25 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// function for finish rotation of a after synced_rotate if necessary
void	complete_a(int direc, int val, t_list **lst)
{
	while ((*(int *)(*lst)->content != val))
	{
		if (direc)
			ra(lst);
		else
			rra(lst);
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for finish rotation of b after synced_rotate if necessary
void	complete_b(int direc, int val, t_list **lst)
{
	while ((*(int *)(*lst)->content != val))
	{
		if (direc)
			rb(lst);
		else
			rrb(lst);
	}
}

///////////////////////////////////////////////////////////////////////////////
// function for synced rotation and exception
void	synced_rotate(int a_direc, int b_direc, t_list **a, t_list **b)
{
	if (a_direc == b_direc)
	{
		if (a_direc == 1)
			rr(a, b);
		else
			rrr(a, b);
	}
	else
	{
		if (a_direc == 1)
			ra(a);
		else
			rra(a);
		if (b_direc == 1)
			rb(b);
		else
			rrb(b);
	}
}

///////////////////////////////////////////////////////////////////////////////
// rotate the best element of b and a before insertion.
void	rotate_all(int b_arg, int a_arg, t_list **b, t_list **a)
{
	const int	a_direc = get_direction(a_arg, *a);
	const int	b_direc = get_direction(b_arg, *b);
	int			val_a;
	int			val_b;

	val_a = *(int *)(*a)->content;
	val_b = *(int *)(*b)->content;
	while (*a && *b && (val_a != a_arg) && (val_b != b_arg))
	{
		synced_rotate(a_direc, b_direc, a, b);
		val_a = *(int *)(*a)->content;
		val_b = *(int *)(*b)->content;
	}
	complete_a(a_direc, a_arg, a);
	complete_b(b_direc, b_arg, b);
}

///////////////////////////////////////////////////////////////////////////////
// pb the first element of b a the good place in a
void	push_good_b(t_list **a, t_list **b)
{
	int	b_arg;
	int	a_arg;

	b_arg = search_best(*a, *b);
	a_arg = recup_a_pos(*a, b_arg);
	rotate_all(b_arg, a_arg, b, a);
	pa(a, b);
}
