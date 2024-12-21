/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quartile_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:30:37 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/21 19:04:46 by yseguin          ###   ########.fr       */
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
	int	*min_maxval;
	int	third;

	min_maxval = min_max(a);
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
// calculate other possibility of b in a (min cost no matter the cost ^^)
void	calculate_pos_end(int *cost, int *min_cost, int sync_rrr, int steps[4])
{
	if (*cost < *min_cost)
		*min_cost = *cost;
	*cost = steps[1] + steps[3] - sync_rrr;
	if (*cost < *min_cost)
		*min_cost = *cost;
	*cost = steps[0] + steps[2] + 1;
	if (*cost < *min_cost)
		*min_cost = *cost;
	*cost = steps[1] + steps[3] + 1;
	if (*cost < *min_cost)
		*min_cost = *cost;
}

///////////////////////////////////////////////////////////////////////////////
// Calculate all possibility for insert b element in a
int	calculate_pos(int b_pos, int a_pos, t_list *b, t_list *a)
{
	int	steps[4];
	int	sync_rr;
	int	sync_rrr;
	int	cost;
	int	min_cost;

	steps[0] = get_index(a, a_pos);
	steps[1] = ft_lstsize(a) - steps[0];
	steps[2] = get_index(b, b_pos);
	steps[3] = ft_lstsize(b) - steps[2];
	if (steps[0] < steps[2])
		sync_rr = steps[0];
	else
		sync_rr = steps[2];
	if (steps[1] < steps[3])
		sync_rrr = steps[1];
	else
		sync_rrr = steps[3];
	min_cost = steps[0] + steps[2] - sync_rr;
	cost = steps[0] + steps[3];
	if (cost < min_cost)
		min_cost = cost;
	cost = steps[1] + steps[2];
	calculate_pos_end(&cost, &min_cost, sync_rrr, steps);
	return (min_cost);
}

///////////////////////////////////////////////////////////////////////////////
// Main function for calculate all possibility of all 0 minCost 1 val 2 mode
int	search_best(t_list *a, t_list *b)
{
	int		cost_min[2];
	int		best_b_pos;
	int		b_pos;
	int		a_pos;
	t_list	*tmp;

	cost_min[1] = INT32_MAX;
	best_b_pos = *(int *)b->content;
	tmp = b;
	while (tmp)
	{
		b_pos = *(int *)tmp->content;
		a_pos = recup_a_pos(a, b_pos);
		cost_min[0] = calculate_pos(b_pos, a_pos, b, a);
		if (cost_min[0] < cost_min[1])
		{
			cost_min[1] = cost_min[0];
			best_b_pos = b_pos;
		}
		tmp = tmp->next;
	}
	return (best_b_pos);
}
