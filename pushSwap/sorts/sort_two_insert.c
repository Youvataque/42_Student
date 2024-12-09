/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:46:05 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/09 12:55:33 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swaplib.h"

void	sort_two(t_list *a)
{
	if (*(int *)a->content > *(int *)a->next->content)
		sa(a);
}

void	insert_pickmin(t_list **a, int *min, int *index)
{
	int				i;
	t_list			*temp;

	i = 0;
	temp = *a;
	while (temp != NULL)
	{
		if (*(int *)temp->content < *min)
		{
			*min = *(int *)temp->content;
			*index = i;
		}
		i++;
		temp = temp->next;
	}
}

void	insert_rotate(t_list **a, int min, int index, int size)
{
	if (index <= size / 2)
	{
		while (*(int *)(*a)->content != min)
			ra(a);
	}
	else
	{
		while (*(int *)(*a)->content != min)
			rra(a);
	}
}

void	insertion(t_list **a, t_list **b)
{
	int	min;
	int	index;
	int	size;

	index = 0;
	while (*a != NULL)
	{
		size = ft_lstsize(*a);
		min = INT32_MAX;
		insert_pickmin(a, &min, &index);
		insert_rotate(a, min, index, size);
		pb(a, b);
	}
	while (*b != NULL)
		pa(a, b);
}
