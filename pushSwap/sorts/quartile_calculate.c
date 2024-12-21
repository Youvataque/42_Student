/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:30:37 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/21 16:16:33 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

///////////////////////////////////////////////////////////////////////////////
// search the better inter for place target into a
int	search_inter(t_list *a, int target, int max)
{
	int	closest;
	int	current;

	closest = max;
	if (target < min_max(a)[0])
		return (min_max(a)[1]);
	while (a)
	{
		current = *(int *)a->content;
		if (current > target && current < closest)
			closest = current;
		a = a->next;
	}
	return (closest);
}

///////////////////////////////////////////////////////////////////////////////
// recup the best inter for insert the val b_pos
int	recup_a_pos(t_list *a, int b_pos)
{
	int	*min_maxval = min_max(a);
	int			third;

	if (b_pos > min_maxval[1])
		third = min_maxval[0];
	else if (b_pos < min_maxval[0])
		third = min_maxval[0];
	else
		third = search_inter(a, b_pos, min_maxval[1]);
	free(min_maxval);
	return (third);
}

///////////////////////////////////////////////////////////////////////////////
// Calculate all possibility for insert b element in a
int calculate_pos(int b_pos, int a_pos, t_list *b, t_list *a)
{
	int	steps[4];
	int	sync[2];
	int	cost;

	steps[0] = get_index(a, a_pos);
	steps[1] = ft_lstsize(a) - steps[0];
	steps[2] = get_index(b, b_pos);
	steps[3] = ft_lstsize(b) - steps[2];
	if (steps[0] < steps[2])
		sync[0] = steps[0];
	else
		sync[0] = steps[2];

	if (steps[1] < steps[3])
		sync[1] = steps[1];
	else
		sync[1] = steps[3];
	cost = steps[0] + steps[2] - sync[0];
	if (steps[1] + steps[3] - sync[1] < cost)
		cost = steps[1] + steps[3] - sync[1];
	if (steps[0] + steps[3] < cost)
		cost = steps[0] + steps[3];
	return cost;
}

///////////////////////////////////////////////////////////////////////////////
// Main function for calculate all possibility of all 0 minCost 1 val 2 mode
int	search_best(t_list *a, t_list *b)
{
	int	b_pos;
	int	a_pos;
	int	val;
	int result[3];

	result[0] = INT32_MAX;
	while (b)
	{
		b_pos = *(int *)b->content;
		a_pos = recup_a_pos(a, b_pos);
		val = calculate_pos(b_pos, a_pos, b, a);
		if (val < result[0])
		{
			result[0] = val;
			result[1] = b_pos;
		}
		b = b->next;
	}
	return (result[1]);
}
